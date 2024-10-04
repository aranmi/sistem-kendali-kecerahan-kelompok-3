int pinldr = A0;
const int relayPin = 7;
int treshold = 883;
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(pinldr, INPUT);
  pinMode(relayPin, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int adc = analogRead(pinldr);
  float tegangan = adc*(5.0/1023);
  Serial.print("adc = ");
  Serial.println(adc);
  Serial.print("Tegangan = ");
  Serial.println(tegangan);
  int aktual = map(tegangan,0.9,4.82,0,3532);
  Serial.print("aktual = ");
  Serial.println(aktual);


  
  

  delay(50);

  

  if (aktual > treshold){
   {
    lcd.setCursor(1, 0);
    lcd.print("Lampu mati!");
    delay(1000);
    lcd.clear();
   }
    
    
    digitalWrite(relayPin, HIGH);
    Serial.print("Nilai Sensor");
    Serial.println("Relay Off");
    delay(200); 
  }
  else {
    {
    lcd.setCursor(2, 0);
    lcd.print("lampuna idupppp");
    delay(1000);
    lcd.clear();
  }
    
    digitalWrite(relayPin, LOW);
    Serial.println("Relay aktif");
    
  }
  delay(50);
  
  
  
 
 // digitalWrite(relayPin, HIGH);
 // delay(1000); 

  //digitalWrite(relayPin, LOW);
  //delay(1000); 

  
  
}
