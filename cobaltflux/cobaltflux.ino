const int UP = 22;
const int DOWN = 21;
const int LEFT = 20;
const int RIGHT = 19;

const int UPLEFT = 18;
const int UPRIGHT = 23;

const uint8_t pins[] = {UP, DOWN, LEFT, RIGHT, UPLEFT, UPRIGHT}; 

void setup() {
  for (size_t i = 0; i < sizeof(pins); i++) {
    pinMode(pins[i], INPUT_PULLUP);
  }
}

void loop() {
  for (size_t i = 0; i < sizeof(pins); i++) {
    bool val = digitalRead(pins[i]);
    Joystick.button(i+1, !val);
  }
  delay(1);
}
