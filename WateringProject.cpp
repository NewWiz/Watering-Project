// Sensor input values range between 220 being completely submerged and 480 being compltely dry.

int submersible_pump - 2;
int analog_moisture_sensor = A0;
float moisture_sensor_value = 0;

// Change to what your moisture sensor is calibrated to.
const int MOISTURE_THRESHOLD = 450;

void setup() {
	Serial.begin(9600);
	pinMode(submersible_pump, OUTPUT);
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
	
	if(moisture_sensor_value > MOISTURE_THRESHOLD)
	{
		// If the sensor is dry, send the signal to power the submersible_pump to HIGH (On).
		digitalWrite(submersible_pump, HIGH);
	}
	else {
		// If the sensor reads an adequate moisture value, send the signal to power the pump to LOW (Off).
		digitalWrite(LED_BUILTIN, LOW);
	}
	// Set a delay to check the moisture level every 10 minutes (600,000ms). You can change this according to your setup.
	delay(600000);