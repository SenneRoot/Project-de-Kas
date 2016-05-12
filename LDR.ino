int sensorPin = A0; // selecteer de input pin voor de ldr
int sensorValue = 0; // variable om de waarde van de sensor op te slaan
int ledPin = 8; // selecter de output pin waarde voor de LED

void setup()
{
	pinMode(ledPin, OUTPUT); //zet de pinmode van ledPin naar output
	Serial.begin(9600); //zet de serial port voor communicatie
}

void loop()
{
	readSensor(sensorPin);
	Monitor(sensorValue);

}

static double readSensor(int sensorPin)
{
	sensorValue = analogRead(sensorPin);
	return sensorValue;
}

static void Monitor(double sensorValue)
{
	Serial.println(sensorValue); //prints the values coming from the sensor on the screen
}