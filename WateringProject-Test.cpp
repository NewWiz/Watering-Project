// Sensor input values range between 220 being completely submerged and 480 being compltely dry.

int analog_moisture_sensor = A0;
float moisture_sensor_value = 0;
const int MOISTURE_THRESHOLD = 350;

void setup() {
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(analog_moisture_sensor, INPUT);
	
	// When powered on, the on-board LED turns on for 3 seconds to let you know it is operational.
	digitalWrite(LED_BUILTIN, HIGH);
	delay(3000);
}

void loop() {
	// Print the moisture level to console:
	Serial.print("Moisture Level:");
	moisture_sensor_value = analogRead(analog_moisture_sensor);
	Serial.println(moisture_sensor_value);
	
	if(moisture_sensor_value < MOISTURE_THRESHOLD)
	{
		// If the moisture is less than 50% moist, send the signal to power the LED to HIGH.
		digitalWrite(LED_BUILTIN, HIGH);
	}
	else {
		// If the moisture sensor is more than 50% moist, send the signal to power the LED to LOW.
		digitalWrite(LED_BUILTIN, LOW);
	}
	
	// Print the moisture level every 1 sec.
	delay(1000);