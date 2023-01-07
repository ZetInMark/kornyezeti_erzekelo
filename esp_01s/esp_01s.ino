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
  while(Serial.available() > 0) //ha vannak byteok a bufferben akkor....
  {
    //Helyet csinálunk az érkező üzenetnek
    //egy karakter tömböt hozunk létre amiben majd tároljuk az egyes karaktereket
    static unsigned int uzenet_poz = 0;  //ezt fogjuk változtatni hogy lépkedjünk a buffer elemei között.

    //Beolvassuk a következő byte-ot a soros monitorról
    char inByte = Serial.read();

    //Ellenőrizzük a bejövő üzenetet hogy biztos nem terminating character e (Ez dönti el hogy a buffer / üzenet végén vagyunk e)

    if(inByte != '\n')  //ellenőrizzük hogy ez nem egy new line terminating character // && (uzenet_poz < MAX_UZENET_HOSSZ - 1
    {
      //Hozzáadjuk a bejövő byte-ot a karakter tömbünkhöz
      uzenet[uzenet_poz] = inByte;
      uzenet_poz++;
    }

    //Az else ág akkor valósul meg ha az egész üzenetet befogadtuk
    else
    {
      //adjunk egy null karaktert a stringnek
      uzenet[uzenet_poz] = '\0';  //ez fontos mivel ha atoi() átalakító használunk ez kell a végére

      //Írjuk ki az üzenetet vagy csináljunk vele amit szeretnénk



      byte index = 0;
      ptr = strtok(uzenet, ",");  // szeparátor karakter
      while (ptr != NULL)
      {
        strings[index] = ptr;
        index++;
        ptr = strtok(NULL, ",");
      }

      String paratartalom = strings[0];
      String homerseklet = strings[1];
      String talajnedv = strings[2];


      //átadjuk a webhooknak ami elküldi a http kérést
      webhook.trigger(paratartalom,homerseklet,talajnedv);


      //reseteljuk az uzenet poziciot

      uzenet_poz = 0;
}

  }


}
