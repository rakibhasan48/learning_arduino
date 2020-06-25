int voltageRead = A0;
int resistorVoltValue;
int greedLightPin = 9;

void setup()
{
  pinMode(voltageRead, INPUT);
  pinMode(greedLightPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
    resistorVoltValue = analogRead(voltageRead);
    Serial.print("Resistor value: ");
    Serial.println(resistorVoltValue);

    if (resistorVoltValue > 190) {
        analogWrite(greedLightPin, 255);
    } else if (resistorVoltValue > 90 ) {  
        analogWrite(greedLightPin, 100);
    } else {
        analogWrite(greedLightPin, 10);
    }

    delay(100);
}
