
int sensorPin = A0; // select the input pin for ldr
int sensorValue = 0; // variable to store the value coming from the sensor
int ledPin = 8; // select the output pin value for the LED

void setup()
{
	pinMode(ledPin, OUTPUT); //set the pinmode of ledPin to output
	Serial.begin(9600); //sets serial port for communication
}

void loop()
{
	readSensor(sensorPin);
	Serial.println(sensorValue); //prints the values coming from the sensor on the screen
	LichtSensor(ledPin, sensorValue, 500);
	delay(100); //

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