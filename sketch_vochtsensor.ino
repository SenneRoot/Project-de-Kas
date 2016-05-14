int grondvochtSensor = 0;

void setup() 
{

	Serial.begin(9600);

}
void loop()
{

	int sensorValue = analogRead(grondvochtSensor);

	Serial.println(sensorValue);

	delay(1000);
}