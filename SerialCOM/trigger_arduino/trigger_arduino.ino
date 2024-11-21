bool trigger_state = false;
int trigger_pin = A5;

void setup() {
    Serial.begin(9600);        // Initialize Serial communication
    pinMode(A5, OUTPUT); // Set the pin as an output
    pinMode(LED_BUILTIN, OUTPUT); // Set the built-in LED pin as an output
}

void loop() {
    if (Serial.available() > 0) {  // Check if data is received
        int value = Serial.parseInt(); // Read an integer from Serial input
        if (value == 1) {
            trigger_state = true;
            Serial.println("Trigger on");
        } else if (value == 0) {
            trigger_state = false;  
            Serial.println("Trigger off");
        }
    }
    if (trigger_state) {
        digitalWrite(trigger_pin, HIGH);  // Set pin to 5V
        digitalWrite(LED_BUILTIN, HIGH); // Turn on the built-in LED
        delay(500); // Wait for 500 milliseconds
        Serial.println("Trigger sent");
        digitalWrite(LED_BUILTIN, LOW); // Turn off the built-in LED
        delay(500);
    } else {
        digitalWrite(trigger_pin, LOW);   // Set pin to 0V
        digitalWrite(LED_BUILTIN, LOW); // Turn off the built-in LED
    }
}
