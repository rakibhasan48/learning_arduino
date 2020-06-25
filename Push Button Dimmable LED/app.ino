int LEDPin = 9;
int pushBtnPin = 12;
int pushBtnRead;
byte brightness = 0;
bool up = true;

void setup()
{
    pinMode(LEDPin, OUTPUT);
    pinMode(pushBtnPin, INPUT);
    Serial.begin(9600);
}

void loop()
{
    pushBtnRead = digitalRead(pushBtnPin);  
    
    if (pushBtnRead == LOW) {
      if (brightness == 255) {
        up = false;
      } 
      if (brightness == 0){
        up = true;
      }

      if (up) {
        brightness += 5;
      } else {
        brightness -= 5;  
      }
    }
    analogWrite(LEDPin, brightness);
    Serial.println(brightness); 
    delay(50);
}
