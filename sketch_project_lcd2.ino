#include <LiquidCrystal.h>                      //Haalt de benodigde methodes voor een lcd-display binnen
#include <Servo.h>                              //Haalt de benodigde methodes voor een servo binnen

int sensorPin = 0;                              //Intialiseert de temperatuursensor en geeft aan dat deze op pin 0 zit
LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);        //Geeft aan welke pins op de Arduino verbonden zijn met de lcd-display
Servo mijnServo;                                //Intialiseert een servo met de naam "mijnServo"
int pos = 0;                                    //Intialiseert de positie van de raampjes in graden


void setup()
{
  Serial.begin(9600);                           //Start de seriële monitor.
  lcd.begin(16, 2);                             //Start de lcd-display en geeft aan dat het een 16 x 2 display is oftewel 16 karakters lang en 2 hoog
  lcd.setCursor(0,1);                           //Zet de cursor positie op 0,1 oftwel het begin van de 2de rij
  lcd.write("Temp: ");                          //Schrijft het stukje "Temp: " op de lcd-display
  mijnServo.attach(13);                         //Zet de servo aan en verbindt deze met port 13
}

void loop()
{
  int reading = analogRead(sensorPin);          //Intialiseert een variabele genaamd reading, deze leest de temperatuursensor af doormiddel van "analogRead"
 
  float voltage = reading * 5.0;                //Intialiseert een kommagetaal genaamd voltage die 5x de waarde is van de afgelezen waarde van reading (reading * 5)
  voltage /= 1024.0;                            //Verandert de waarde van voltage naar de waarde van de vorige formule gedeeld door 1024 (reading * 5 / 1024)
 
  Serial.print(voltage);                        //Print de waarde van voltage in de seriële monitor
  Serial.println(" volt");                      //Print de tekst " volt" achter de waarde voltage

  double calibratie = 13.5;                     //Intialiseert een variabele genaamd calibratie die zorgt dat de temperatuur die
                                                //wordt weergeven op de lcd gelijk is aan de temperatuur die het op dit moment echt is
  float temperatuur = (voltage - 0.5) * 100;    //Intialiseert een kommagetal genaamd temperatuur die gelijk is aan ((voltage - 0,5) * 100)
    double tempC = temperatuur - calibratie;    //Intialiseert een kommagetal genaamd TempC die +- gelijk is aan de temperatuur die het op dit moment echt is
    Serial.print(tempC);                        //Print de waarde van tempC in de seriële monitor
    Serial.println(" graden");                  //Print de tekst " graden" achter de waarde tempC
    lcd.setCursor(7,1);                         //Zet de cursor op de 8ste positie van de 2de rij
    lcd.print(tempC);                           //Print de waarde van tempC op de lcd-display
    delay(1000);                                //Wacht 1 seconde voordat de loop verder gaat
 
  if(tempC >= 23)                               //Kijkt of de temperatuur hoger of gelijk is aan 23
  {                                             //Als dit zo is wordt de volgende code uitgevoert
    int Open = 90;                              //Intialiseert een variabele genaamd Open met de waarde 90
    mijnServo.write(Open);                      //Zet de positie van het raam op 90
  }  
  else                                          //Als de temperatuur lager is dan 23 wordt de volgende code uitgevoert
  {
    int Dicht = 180;                            //Intialiseert een variabele genaamd Open met de waarde 180
    mijnServo.write(Dicht);                     //Zet de positie van het raam op 180
  }
}
