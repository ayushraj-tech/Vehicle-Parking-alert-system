/* Define pin numbers */
#define TRIG_PIN   6
#define ECHO_PIN   7
#define BUZZER_PIN 8
#define RED_LED    10
#define GREEN_LED  9

/* Variables */
long duration;
int distance;

void setup()
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);

}

void loop()
{
    // Generate ultrasonic pulse
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);

    digitalWrite(TRIG_PIN, LOW);

    // Read echo pulse duration
    duration = pulseIn(ECHO_PIN, HIGH);

    // Convert to distance (cm)
    distance = (duration * 0.034) / 2;
  
    // WARNING LEVEL
    if (distance < 20)
    {
        digitalWrite(RED_LED, HIGH);
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(BUZZER_PIN, HIGH);
        Serial.println("FLOOD ALERT!");
    }
    // SAFE LEVEL
    else
    {
        digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(BUZZER_PIN, LOW);
        Serial.println("Water Level Normal");
    }

    delay(25);
}
