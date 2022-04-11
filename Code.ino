#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int count = 0;
char c;
String id;
int total = 0;
int last = 0 ;

void setup() 
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  lcd.begin(16,2);
  
}

void loop() {
  while(Serial.available()>0)
  {
   c = Serial.read();
   count++;
   id += c;
   if(count > 0)  
    {
      if(id=="PEN10RS")
      {
        lcd.clear();
        total = total + 10;
        lcd.print("Total = ");
        lcd.print(total);
        delay(1000);
        last = 10 ;
        digitalWrite(13, HIGH);
      }
      if(id=="BISCUIT20RS")
      {
        lcd.clear();
        total = total + 20; 
        lcd.print("Total = ");
        lcd.print(total);
        delay(1000);
        last = 20 ;
        digitalWrite(13, HIGH);
      }
      if(id=="OIL200RS")
      {
        lcd.clear();
        total = total + 200; 
        lcd.print("Total = ");
        lcd.print(total);
        delay(1000);
        last = 200;
        digitalWrite(13, HIGH);
      }
      if(id=="CHEESE100RS")
      {
        lcd.clear();
        total = total + 100;
        lcd.print("Total = ");
        lcd.print(total);
        delay(1000);
        last = 100;
        digitalWrite(13, HIGH);
      }
      if(id=="BREAD50RS")
      { 
        lcd.clear();
        total = total + 50;
        lcd.print("Total = ");
        lcd.print(total);
        delay(1000);
        last = 50;
        digitalWrite(13, HIGH);
        
      }
      if(id=="Done")
      {
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("Final bill = ");
        lcd.setCursor(1,1);
        lcd.print(total);
        lcd.command(0x18);
        digitalWrite(13, LOW);
      }
      if(id=="Remove")
      {
        lcd.clear();
        total = total - last ;
        lcd.print("Total = ");
        lcd.print(total);
        delay(1000);
      }
    }
  }
  count = 0;
  id="";
  delay(500);

}
