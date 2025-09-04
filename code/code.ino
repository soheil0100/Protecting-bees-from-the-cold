#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 13, 12, 11, 10, 9);
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

#define fan 2
#define element 6
#define uptemp A0
#define dntemp A1
#define upled 3
#define dnled 4
#define normled 5

int h, t;
int upt, dnt;
float ut, dt, uptt;


void setup() {
  lcd.begin(16, 2);
  lcd.noBlink();
  dht.begin();
  pinMode(element, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(uptemp, INPUT);
  pinMode(dntemp, INPUT);
  pinMode(upled, OUTPUT);
  pinMode(dnled, OUTPUT);
  pinMode(normled, OUTPUT);
}

void loop() {
  h = dht.readHumidity();
  t = dht.readTemperature();
  ut=analogRead(uptemp);
  ut*=5;
  ut/=1024;
  ut*=20;
  upt=ut;
  dt=analogRead(dntemp);
  dt*=5;
  dt/=1024;
  dt*=20;
  dnt=dt;
  lcd.setCursor(0, 0);
  lcd.print("H=");
  lcd.setCursor(2, 0);
  lcd.print(h);
  lcd.setCursor(4, 0);
  lcd.print(" % ");
  lcd.setCursor(7, 0);
  lcd.print("T=");
  lcd.setCursor(9, 0);
  lcd.print(t);
  lcd.setCursor(11, 0);
  lcd.print(" 'C");
  if(h>=0 and h<=9){
    lcd.setCursor(3, 0);
    lcd.print(" ");
  }
  if(t>=0 and t<=9){
    lcd.setCursor(10, 0);
    lcd.print(" ");
  }
  lcd.setCursor(0, 1);
  lcd.print("DNT=");
  lcd.setCursor(4, 1);
  lcd.print(dnt);
  lcd.setCursor(6, 1);
  lcd.print("C ");
  lcd.setCursor(8, 1);
  lcd.print(" UPT=");
  lcd.setCursor(13, 1);
  lcd.print(upt);
  lcd.setCursor(15, 1);
  lcd.print("C");
  if(dnt>=0 and dnt<=9){
    lcd.setCursor(5, 0);
    lcd.print(" ");
  }
  if(upt>=0 and upt<=9){
    lcd.setCursor(14, 0);
    lcd.print(" ");
  }
  if(t>upt){
    digitalWrite(element, LOW);
    digitalWrite(dnled, LOW);
    digitalWrite(normled, LOW);
    digitalWrite(upled, HIGH);
  }
  if(t<dnt){
    digitalWrite(element, HIGH);
    digitalWrite(upled, LOW);
    digitalWrite(normled, LOW);
    digitalWrite(dnled, HIGH);
  }
  if(t<=upt and t>=dnt){
    digitalWrite(dnled, LOW);
    digitalWrite(upled, LOW);
    digitalWrite(normled, HIGH);
  }
  uptt=upt+3;
  if(t>=uptt){
    digitalWrite(fan, LOW);
  }
  if(t<=upt){
    digitalWrite(fan, HIGH);
  }
}
