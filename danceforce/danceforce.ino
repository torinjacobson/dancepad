#define DEBUG 0

const int UP = 2;
const int DOWN = 4;
const int LEFT = 5;
const int RIGHT = 3;
const int START =  1;
const int SELECT = 0;

void setup() {
}

void loop() {
  const uint8_t ain[] =        {UP,  DOWN, LEFT, RIGHT, START, SELECT};
  const int thresh_falling[] = {600, 600,  600,  600,   200,   200};
  const int thresh_rising[] =  {700, 700,  700,  700,   800,   600};

  for(size_t i = 0; i < sizeof(ain); ++i)
  {
    int raw = analogRead(ain[i]);
    if (raw < thresh_falling[i]) 
      Joystick.button(i + 1, true);
    else if (raw > thresh_rising[i])
      Joystick.button(i + 1, false);

    if (DEBUG) {
      Serial.printf("%4d ", raw);
    }
  }

  if (DEBUG) {
    Serial.printf("\n");
    delay(50);
  }
  delay(1);
 }