#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

const int inPower = 7;

/////////////////homerseklet - paratartalom
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
/////////////////

/////////////////föld nedvesség sensor
const int AirValue = 500;   //Üresen kell mérni egyet a levegőben és helyettesíteni az értékkel
const int WaterValue = 220;  //Üresen kell mérni egyet a vízben és helyettesíteni az értékkel
int soilMoistureValue = 0;
int soilmoisturepercent=0;
/////////////////

///////////////// Surface moisture sensor
const int capteur_D = 4;
const int capteur_A = A1;
/////////////////

/////////////////Vízpumpához tartozó relé pin száma
int relay = 9;

void setup() {
  
  //Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
  pinMode(capteur_D, INPUT);
  pinMode(capteur_A, INPUT);
  pinMode(inPower, INPUT);
  pinMode(relay, OUTPUT);
  dht.begin();

}

void loop() {
  float h = dht.readHumidity();   //Páratartalom
  float t = dht.readTemperature();  //Hőmérséklet
  soilMoistureValue = analogRead(A0);  //talajnedvesség
  
  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);

  if (isnan(h) || isnan(t) ) {
    
    return;
}
//páratartalom

lcd.setCursor(0,0);
lcd.print(F("Paratart.:"));
lcd.setCursor(10,0);

lcd.print(h);

//homerseklet

lcd.setCursor(0,1);
lcd.print(F("Homerseklet:"));
lcd.setCursor(12,1);

lcd.print(t);
lcd.setCursor(17,1);
lcd.print(F("C"));

//talajnedvesség
if(soilmoisturepercent >0 && soilmoisturepercent < 100)
{
  
  
  lcd.setCursor(0,2);
  lcd.print("Talajnedv: ");
  lcd.setCursor(12,2);
  lcd.print(soilmoisturepercent);
  lcd.setCursor(15,2);
  lcd.print("%");
  
}

//felszín nedvesség
String felsz;
if(digitalRead(capteur_D) == LOW) 
  {
    felsz = "nedves";
    
    lcd.setCursor(0,3);
    lcd.print("talaj nedves");
  }


else
  {
    felsz = "szaraz";

    lcd.setCursor(0,3);
    lcd.print("talaj szaraz");
  }  

//70% talajnedvesség alatt bekapcsol a vízpumpa
while (soilmoisturepercent<70){
     digitalWrite(relay, HIGH);
     soilMoistureValue = analogRead(A0);
     soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
}
digitalWrite(relay, LOW);



  Serial.begin(9600);
  String uzenet = String(h) + "," + String(t) + "," + String(soilmoisturepercent);

  Serial.print(uzenet);
  Serial.print('\n');



delay(5000);
}
