const int buzzer = 9; //buzzer to arduino pin 9
const int TRIG_PIN = 12;
const int ECHO_PIN = 13;

void setup() {

  Serial.begin(9600);

  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

}

void loop() {

  long duration, distanceCm, distanceIn;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);

  // convert the time into a distance
  distanceCm = duration / 29.1 / 2 ;

  Serial.println(distanceCm);

  if (distanceCm > 2000 ) {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(30);
    digitalWrite(TRIG_PIN, LOW);
    duration = pulseIn(ECHO_PIN, HIGH);

    // convert the time into a distance
    distanceCm = duration / 29.1 / 2 ;
  } else if (distanceCm > 1000 ) {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(20);
    digitalWrite(TRIG_PIN, LOW);
    duration = pulseIn(ECHO_PIN, HIGH);

    // convert the time into a distance
    distanceCm = duration / 29.1 / 2 ;
  }

  if (distanceCm > 2000) {
    tone(buzzer, 150); // Send 1KHz sound signal...
    delay(100);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(1000);
  } else if (distanceCm < 1000) {


    tone(buzzer, 150); // Send 1KHz sound signal...
    delay(100);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(distanceCm);        // ...for 1sec
  }
}
