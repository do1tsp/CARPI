/* 
 * VAG Radio Remote Control Decoder
 * Copyright (c) 2020 Stefan Endemann (info@dj2sea.de).
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <Arduino.h>

#define DATA_IN 2
#define SYNC_TO 20000    // Timeout for sync in µs
#define SYNC_HI_LEN 4550 // Length of sync signal high in µs
#define SYNC_HI_TOL 100  // Tolerance for sync signal high in µs
#define DATA_TO 3000     // Timeout for data bits in µs
#define DATA_HI_LEN 1700 // Length of data signal high for '1' bit in µs
#define DATA_LO_LEN 600  // Length of data signal high for '0' bit in µs
#define DATA_TOL 100     // Tolerance for data signal high in µs

// Prototypes of functions
boolean read_data(uint8_t *rx_code);

// Setup
void setup()
{
    Serial.begin(19200);

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    pinMode(DATA_IN, INPUT);
}

// Main loop
void loop()
{
    static uint8_t rx_code;
    if (digitalRead(DATA_IN) == LOW)
    {
        // read_data() returns 'true' when valid code has been received.
        // Received code is stored in variable rx_code.
        if (read_data(&rx_code))
        {
            // Do whatever you like with the received code here:
            Serial.print("Received code: ");
            Serial.println(rx_code, HEX);
        }
        else
        {
            Serial.println("Data error.");
        }
    }

    /*
    Put other program parts here. This part of the code must take less than 8.5 ms.
    Otherwise the sync signal might not detected reliably. Please note the code for
    receiving a command from the steering wheel is blocking and might take up to
    100 ms.
    */
}

// Read data
boolean read_data(uint8_t *rx_code)
{
    *rx_code = 0xFF;
    uint8_t byte_pos = 0;           // Number of current data byte
    uint8_t bit_pos = 0;            // Current bit position in byte
    uint8_t rx_buffer[4];           // Buffer for received data
    uint32_t pulse_length;          // Measured length of high pulse
    boolean data_incomplete = true; // Data not completely received

    // Clear RX buffer
    memset(rx_buffer, 0, sizeof(rx_buffer));

    // Wait for high of sync signal
    pulse_length = pulseIn(DATA_IN, HIGH, SYNC_TO);

    // Repeat signal
    if ((pulse_length >= 1750) and (pulse_length <= 2750))
    {
        Serial.print("Repeat. Length = ");
        Serial.println(pulse_length);
        return true;
    }

    // Abort if sync signal high is not within default time +/- tolerance
    if ((pulse_length <= SYNC_HI_LEN - SYNC_HI_TOL) or (pulse_length >= SYNC_HI_LEN + SYNC_HI_TOL))
    {
        Serial.println("Sync error.");
        return false;
    }

    // Receive and process data until 32 bits have been received
    while (data_incomplete)
    {
        pulse_length = pulseIn(DATA_IN, HIGH, DATA_TO);
        rx_buffer[byte_pos] = rx_buffer[byte_pos] << 1;
        if (pulse_length >= 1150) // HIGH
        {
            rx_buffer[byte_pos]++;
        }

        // Increase bit position
        bit_pos++;
        // Switch to next byte after 8 received bits
        if (bit_pos > 7)
        {
            bit_pos = 0;
            byte_pos++;
            // Reception sequence is complete after 4 bytes (32 bits)
            if (byte_pos > 3)
            {
                data_incomplete = false;
            }
        }
    }

    // Wait for end of stop bit to avoid wrong syncs
    pulse_length = pulseIn(DATA_IN, HIGH, 2000);
    while (digitalRead(DATA_IN) == LOW)
    {
    }

    // Check first and second data byte. Value is always 0x41 and 0xE8.
    if ((rx_buffer[0] != 0x41) or (rx_buffer[1] != 0xE8))
    {
        Serial.println("Data header error. (Byte 1 and 2 not 0x41 0xE8)");
        return false;
    }

    // Sum of third and fourth data byte must be 0xFF.
    if ((rx_buffer[2] + rx_buffer[3]) != 0xFF)
    {
        Serial.println("Data consistency error. (Byte 3 + 4 != 0xFF)");
        return false;
    }

    // Copy received code and return
    *rx_code = rx_buffer[2];
    return true;
}
