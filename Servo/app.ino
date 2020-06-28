#inculde <Servo.h>

int servoPin = 9;
int servoPos = 160;
Servo serv;

void setup()
{
    Serial.begin(9600);
    serv.attach(servoPin); 
}   

void loop()
{
	Serial.println("Angle for servo:");
    while (Serial.available == 0)
    {
    }
    servoPos = Serial.parseInt();
    serv.write(servoPos);
}
