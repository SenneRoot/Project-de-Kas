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
	LichtSensor(ledPin, sensorValue, 500);
	delay(100); 
}

static void ledon(int ledPin)
{
	digitalWrite(ledPin, HIGH);
}

static void ledoff(int ledPin)
{
	digitalWrite(ledPin, LOW);
}

static double readSensor(int sensorPin)
{
	sensorValue = analogRead(sensorPin);
	return sensorValue;
}

static void LichtSensor(int ledPin, int sensorValue, int lichtwaarde)
{
	if (sensorValue < lichtwaarde) // setting a threshold value
		digitalWrite(ledPin, HIGH); // turn LED ON

	else
		digitalWrite(ledPin, LOW); // turn LED OFF
}

static void Monitor(double sensorValue)
{
	Serial.println(sensorValue); //prints the values coming from the sensor on the screen
}