int ONE_PLACE = 2;
int TWO_PLACE = 3;
int FOUR_PLACE = 4;
int SIX_PLACE = 5;
int shortDelay = 1000;
int longDelay = 2000;

void setPinOutput(int pin);
void lightUp(int pin);
void lightDown(int pin);
void runOpOnAllPins(void (*func)(int));
int getPin(int num);
void loopBinaryCount();
void binaryCounter(int decNum);

void setup() {
  runOpOnAllPins(setPinOutput);
}

void loop() {
  loopBinaryCount(16);
  delay(longDelay);
}

void setPinOutput(int pin) {
  pinMode(getPin(pin), OUTPUT);
}

void lightUp(int pin) {
  digitalWrite(getPin(pin), HIGH);
}

void lightDown(int pin) {
  digitalWrite(getPin(pin), LOW);
}

void runOpOnAllPins(void (*func)(int)) {
  int count = 4;
  while (count)
  {
    func(count);
    count--;
  }
}

int getPin(int num) {
  switch (num)
  {
  case 1:
    return ONE_PLACE;
    break;
  
  case 2:
    return TWO_PLACE;
    break;
  
  case 3:
    return FOUR_PLACE;
    break;
  
  case 4:
    return SIX_PLACE;
    break;
  
  default:
    break;
  }
}

void loopBinaryCount(int upTo) {
  for (int i = 0; i < upTo; i++) {
    binaryCounter(i);
    delay(shortDelay);
    runOpOnAllPins(lightDown);
    delay(shortDelay);
  }
}

void binaryCounter(int decNum) {
  int counter = 0;
  while(decNum) {
    counter++;
    if ((decNum & 1) == 1) {
      lightUp(counter);
    }
    decNum >>= 1;
  }
}
