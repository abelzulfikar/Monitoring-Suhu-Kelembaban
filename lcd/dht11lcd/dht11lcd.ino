#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
LiquidCrystal_I2C lcd(0x27,16,2);  
DHT dht(DHTPIN,DHTTYPE);
void setup() 
{
  Serial.begin(9600);
  dht.begin();
  lcd.init();   
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Zulfikar");
 
  lcd.setCursor(0,1);
  lcd.print("TT3A");
  delay(3000);
}

void loop() 
{
 float h = dht.readHumidity();
 float t = dht.readTemperature();

lcd.setCursor(0,0);
lcd.print("Suhu "); 
lcd.print(t);
lcd.setCursor(0,1);
lcd.print("Kelembaban ");
lcd.print(h);
delay(1000);

}
