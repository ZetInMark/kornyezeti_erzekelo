-----Felhasználói dokumentáció----

1) A mikrokontroller és a szenzorok közötti kapcsolat kiépítése

Kábelezés:

Talajnedvesség szenzor

szenzor		Arduino

VCC	---	5V

GND	---	GND

AOUT	---	A0 (Analog 0)








DHT szenzor (Hő és pára)

szenzor		Arduino

VCC	---	5V

GND	---	GND

Digital	---	D2 (Digital 2)








Felszín nedvesség szenzor

szenzor		Arduino

VCC	---	5V

GND	---	GND

D0	---	D4

A0	---	A1








LCD panel 4x20

szenzor		Arduino

VCC	---	5V

GND	---	GND

SDA	---	SDA

SCL	---	SCL









Vízpumpa relé

Relé		Arduino

VCC (+)	---	5V

GND (-)	---	GND

S	---	D9








ESP-01S wifi modul (használat közben)

ESP-01S		Arduino

3v3	---	3.3V	(FONTOS!!!!!! MEGHIBÁSODHAT HA 5V-ra kötjük)

RST	---	

EN	---	3.3V

TX	---	RX (D0 uno modellen)

RX	---	TX (D1 uno modellen)

IO0	---	

IO2	---	

GND	---	GND










2) Használat
Létre kell hozni a https://twitter.com/ oldalon egy új fiókot
Létre kell hozni az https://ifttt.com/ oldalon egy webhookot, amit megfelelő módon be kell konfigurálni úgy hogy tweeteljen html kérés esetén
Tutorial: https://ifttt.com/connect/maker_webhooks/twitter

Helyes összekötés esetén az 'esp-01s' mappában található esp_01s.ino fájlban át kell írni
a webhook kulcs, valamint a csatlakozni kívánt hálózatnak a jelszavát valamint a hálózati SSD-t meg kell adni.

Ha mindent jól kötöttünk össze, az esp_01s.ino file aján található delay-el csökkenthetjük illetve növelhetjük az időtartamot amilyen időközzel működjön a webhook

(megjegyzés: az iftt-s webhook-ok egy nap 25x futtathatók le)
