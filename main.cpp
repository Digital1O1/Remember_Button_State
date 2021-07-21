#include <Arduino.h>
const int buttonPin = 4; // the pin that the pushbutton is attached to
const int ledPin = 13;   // the pin that the LED is attached to

int buttonState = 0;     // current state of the button
int lastButtonState = 0; // previous state of the button
int ledState = 0;        // remember current led state
int relay_pin = 3;

const unsigned long debounce_Interval = 20;
unsigned long previousTime = 0;

void setup()
{
  pinMode(buttonPin, INPUT);    // initialize the button pin as a input
  pinMode(relay_pin, OUTPUT);   // initialize the button pin as a input
  pinMode(LED_BUILTIN, OUTPUT); // initialize the button pin as a output

  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(relay_pin, LOW);
}

void loop()
{
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= debounce_Interval)
  {

    buttonState = digitalRead(buttonPin);
    if (buttonState != lastButtonState)
    {

      // change the state of the led when someone pressed the button
      if (buttonState == 1)
      {
        if (ledState == 1)
        {
          ledState = 0;
        }
        else
        {
          ledState = 1;
        }
      }

      // remember the current state of the button
      lastButtonState = buttonState;
    }

    // turns LED on if the ledState=1 or off if the ledState=0
    digitalWrite(LED_BUILTIN, ledState);
    digitalWrite(relay_pin, ledState);

    // adding a small delay prevents reading the buttonState to fast
    // ( debouncing )
    //delay(20);
    previousTime = currentTime;
  }
}
