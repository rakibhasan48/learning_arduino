int pinVoltRead = A0;
int voltInput;
float outVolt;
int ledPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(pinVoltRead, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  voltInput = analogRead(pinVoltRead);
  outVolt = (5./1023.) * voltInput;
  Serial.print("Out voltage: ");
  Serial.println(outVolt);

  analogWrite(ledPin, calculateAnalog(voltInput));
  delay(500);
}

int calculateAnalog(float volt) {
    return (255./1023.) * volt; 
}