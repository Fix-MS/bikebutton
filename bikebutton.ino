#include <ezButton.h>
#include <WiFi.h>

// NOTE: please create a local file with the following variables
// const char* ssid = "...";
// const char* password = "...";
#include "wifi_credentials.h"

//// Button
#define VALIDATION_TIME 3000

ezButton button(23); // create ezButton object that attach to pin GIOP21

unsigned long pressedTime = 0;
unsigned long releasedTime = 0;

unsigned long numberOfTimes = 0;
bool sendEvent = true;

void setup() {
  Serial.begin(9600);
  button.setDebounceTime(50); // set debounce time to 50 milliseconds

  //Initiate WiFi connection
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Wait for connection
  Serial.print("\ntrying to connect to Wifi!\n");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
}

void send() {
  Serial.println("Button was pressed: " + String(numberOfTimes));

  sendEvent = true;
  numberOfTimes = 0;

  // TODO: send request to our server
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
