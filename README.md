# CARPI
CARPI

Carpi - Anzeigen und Steuern per externer Sensoren / Aktoren

# Sensoren / Aktoren
 - Sensoren / Aktoren werden per Arduinos gesteuert
 - Arduinos haben den Namen 'Gateway' 
 - Diese können z.B. sein: Lenkradfernbedienung, Lichtsteuerung per WS2812b, Klemme 15, Klemme S, Auf oder abgeschlossenes Fahrzeug

# Funkgerät
 - Icom ID-E880
 - Das Display soll ausgelesen werden
 - Das Originale Display wird im moment von einem LC75847T angesteuert
 - Dieses Signal soll ausgewertet werden und über das 'Gateway' Funkgerät zum CARPI gesendet werden
 - PTT wird über einen Taster auf der Lenkradfernbedienung geschaltet, sofern im 2. Display das menü des Funkgeräts angewählt ist
 - Ebenfalls wird eine LED Rot im Hud geschaltet sodas es nicht zu einer Ungewünschten aussendung kommt
# HUD
 - Im Hud soll es ein 2. Display geben das eine Menüstruktur hat, hier kann man verschiedene Modis wählen 
 - Radio, DAB, Spotify, Funkgerät,
 -  Verbaut werden soll ein 3,5" SPI TFT 
 - https://de.aliexpress.com/item/32954240862.html?spm=a2g0s.9042311.0.0.3d724c4dUBKcZj

# Gateways
 - Lenkradfernbedienung
 - WS2812b
 - HW Tasten Radio, Steuerung Pi -> Anschalten,Sleepmode 