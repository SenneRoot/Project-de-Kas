#include <LiquidCrystal.h>                      //Haalt de benodigde methodes voor een lcd-display binnen

LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);        //Geeft aan welke pins op de Arduino verbonden zijn met de lcd-display

void setup()
{
  lcd.begin(16, 2);                             //Start de lcd-display en geeft aan dat het een 16 x 2 display is oftewel 16 karakters lang en 2 hoog
  lcd.setCursor(0,1);                           //Zet de cursor positie op 0,1 oftwel het begin van de 2de rij
  Serial.println("Hello world!");               //Print de tekst "Hello world!"
}

void loop()
{   
  
}
