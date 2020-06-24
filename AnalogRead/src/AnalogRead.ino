int readPin = A3;
int V2 = 0;
int delayTime = 500;
int totalVoltage = 5;
int totalBits = 1023;

void setup() {
    pinMode(readPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    V2 = analogRead(readPin) * (totalVoltage/totalBits);
    Serial.println("Voltage: " + V2);
    delay(delayTime);
}