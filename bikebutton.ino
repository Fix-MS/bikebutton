#include <ezButton.h>

#define VALIDATION_TIME 3000

ezButton button(23); // create ezButton object that attach to pin GIOP21

unsigned long pressedTime = 0;
unsigned long releasedTime = 0;

unsigned long numberOfTimes = 0;
bool sendEvent = true;

void setup() {
  Serial.begin(9600);
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
}

void send() {
  Serial.println("Button was pressed: " + String(numberOfTimes));

  sendEvent = true;
  numberOfTimes = 0;

}

void loop() {
  button.loop(); // MUST call the loop() function first

  if (button.isPressed()) {
    pressedTime = millis();
  }
  else if (button.isReleased()) {
    releasedTime = millis();

    sendEvent = false;

    numberOfTimes += 1;

    if (numberOfTimes == 3) {
      send();
    }

  }
  if (millis() - releasedTime >= VALIDATION_TIME && !sendEvent) {
    send();
  }
}
