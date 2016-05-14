int sensorPin = 0;                              //Intialiseert de temperatuursensor en geeft aan dat deze op pin 0 zit

void setup()
{
  Serial.begin(9600);                           //Start de seriële monitor.
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
  double tempC = temperatuur - calibratie;      //Intialiseert een kommagetal genaamd TempC die +- gelijk is aan de temperatuur die het op dit moment echt is
    Serial.print(tempC);                        //Print de waarde van tempC in de seriële monitor
    Serial.println(" graden");                  //Print de tekst " graden" achter de waarde tempC
    delay(1000);                                //Wacht 1 seconde voordat de loop verder gaat
}
