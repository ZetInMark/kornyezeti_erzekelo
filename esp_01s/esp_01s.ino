#include <ESP8266Webhook.h>
#include <ESP8266WiFi.h>

#define _SSID "Hunor"      //WiFi SSID
#define _PASSWORD "Asdfghj11"  //WiFi Password
#define KEY "jAy-d9XRNZtCrslkWWC0u3EUBGBFzswAJLdhjUJVDOU"        // Webhook kulcs
#define EVENT "tweet"      // Webhook Event Name

Webhook webhook(KEY, EVENT);    // Create an object.

const unsigned int MAX_UZENET_HOSSZ = 17;
static char uzenet[MAX_UZENET_HOSSZ];

char strings[3]; // elemek száma amit át szeretnék adni a webhooknak
charptr = NULL;

unsigned long seconds = 1000L;
unsigned long minutes = seconds * 180; //3 perc varakozasi ido, ez a long kell mivel az int az csak 32000 milisecondig megy



void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  //kapcsolódás a hálózathoz
  WiFi.begin(_SSID, _PASSWORD);



  digitalWrite(LED_BUILTIN, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

}
