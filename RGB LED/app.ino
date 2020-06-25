int redPin = 9;
int  greenPin = 10;
int bluePin = 11;
String colorToLight;
String askForColor = "What color do you want?";

void setup()
{
    Serial.begin(9600);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void loop()
{
    Serial.println(askForColor);
    while (Serial.available() == 0) {}

    colorToLight = Serial.readString();
    colorToLight.trim();
    lightUp(colorToLight);
}

void lightUp(String colorToLight) {
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(greenPin, LOW);
    
    if (colorToLight == "red"){
        digitalWrite(redPin, HIGH);
    }
    if (colorToLight == "blue"){
        digitalWrite(bluePin, HIGH);
    }
    if (colorToLight == "green"){
        digitalWrite(greenPin, HIGH);
    }
}
