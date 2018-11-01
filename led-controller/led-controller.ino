int ledPins[] = {
  9, 10
};

int ledPinCount = 2;
int mode = 2;

void setup() {
  // nothing happens in setup
  randomSeed(analogRead(0));
  mode = floor((random(0, 3)));
}

void loop() {
  if(mode == 0) {
      for(int i = 0; i < ledPinCount; i++) {
        int current = ledPins[i];
        analogWrite(current, 0);
      }
   } else if(mode == 1) {
      for(int i = 0; i < ledPinCount; i++) {
        int current = ledPins[i];
        analogWrite(current, 255);
      }
   } else if(mode == 2) {
      for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 15) {
      for(int i = 0; i < ledPinCount; i++) {
        int current = ledPins[i];
        analogWrite(current, fadeValue);
      }
      delay(30);
    }
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 15) {
      for(int i = 0; i < ledPinCount; i++) {
        int current = ledPins[i];
        analogWrite(current, fadeValue);
      }
      delay(30);
    }
   }
}
