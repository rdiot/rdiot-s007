/* LM35 (LM35DZ) [S007] : http://rdiot.tistory.com/43 [RDIoT DEMO] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
 
int sensorPin1 = A0;
int counter = 0;
float temperature = 77.7;
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
  
  pinMode(sensorPin1,INPUT);
  delay(1000);
 
}
 
void loop()
{
 
  //only read temp every 100 cycles
  if(counter%500 == 0)
  {
 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("S007:LM35");
 
    // read the pin
    int reading = analogRead(sensorPin1);
    //convert reading to volts
    float volts = (reading * 5.0);
    volts /= 1024.0;
 
    temperature = volts * 100.0;
    lcd.setCursor(0,1);
    lcd.print("Value=" + (String)temperature + "'C");
 
    delay(100);
    //Serial.print(temperature);
    //Serial.println(" degrees Celsius");
 
    counter = 0;
  } 
  counter ++;
}
