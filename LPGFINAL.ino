#define MQ2pin (0)
#include <LiquidCrystal_I2C.h>
int buzzerPin = 9;
float sensorValue;  
LiquidCrystal_I2C lcd(0x27,16,2);
void setup()
{
  Serial.begin(9600); 
  Serial.println("Activating Gas sensor");
  delay(10000); 
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(10,1);
  delay(10000);
  digitalWrite(10,0);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("warming up ");
  pinMode(buzzerPin, OUTPUT);
  tone(buzzerPin, 1000, 2000); 
}
void loop()
{
  sensorValue = analogRead(MQ2pin); 
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  if(sensorValue > 300)
  {
    Serial.print("gas leak!");
     digitalWrite(11,1);
     delay(1000);
     digitalWrite(11,0);
     lcd.setCursor(0,0);
     lcd.print("Gas Leaking ");
     lcd.setCursor(0,1);
     lcd.print("PPM=");
     lcd.print(sensorValue);
     tone(buzzerPin, 440); // A4
     delay(1500);
     tone(buzzerPin, 494); // B4
     
  }
  if(sensorValue < 300)
  {
    Serial.print("No gas Leak");
     digitalWrite(12,1);
     delay(1000);
     digitalWrite(12,0);
     lcd.setCursor(0,0);
     lcd.print("No Gas Leak");
     lcd.setCursor(0,1);
     lcd.print("PPM=");
     lcd.print(sensorValue);
     
  }
  Serial.println("");
  delay(3000); 
}
