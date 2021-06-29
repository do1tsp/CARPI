# CARPI

Carpi - Anzeigen und Steuern per externer Sensoren / Aktoren

# Sensoren / Aktoren
 - Sensoren / Aktoren werden per Arduinos gesteuert
 - Arduinos haben den Namen 'Gateway' 
 - Diese können z.B. sein: Lenkradfernbedienung, Lichtsteuerung per WS2812b, Klemme 15, Klemme S, Auf oder abgeschlossenes Fahrzeug

# Datenstruktur:
 - Daten zu den Gateways findet man im Unterordner Gateways
 - Beispiel datein sind unter DATA Abgespeichert
 
- Drehzahl
- Geschwindigkeit inkl. Voreilung
- GRA
	-Soll Geschwindigkeit
	-Eingeschaltet Ja/Nein
Fahrpedalstellung
Kühlmitteltemperatur
ÖL Temperaur
Klemme 58d Displaybeleuchtung 
Normalbetrieb / Klemme 15
Lufttemperatur / Außentemperatur
Türkontaktschalter
Blinker L/R
Batteriespannung 
ASR
Handbremse
ECU
Fernlicht
Licht 
-Tankanzeige
	-Benzinverbrauchsanzeige
Kilometeranzeige
Tripkilometer
Zeigerwischen bei Start

Radio Anzeige → Daten von Pi #1

Notwendige Aufgaben:

-CAN Codes 
-CAN Lesen und Auswerten
-Oberfläche gestalten
-Oberfläche mit Daten füllen
-3D Rahmen für Display
-Welche Kabel müssen wo angeschlossen werden
-Fastboot Raspberry Pi
-Stromversorgung
-Anbindung Radio 
-Anbidung Funkgerät 
-Welche Anzeigen werden benötigt ?
- Wie werden diese Dargestellt
-Anbindung Lenkradfernbedinung

