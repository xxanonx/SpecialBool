#include <SpecialBool.h>

/*
 * SpecialBool is a class that helps keep memory usage low and has great uses built in!
 * arduino bools take up a whole byte even though it's states can only be 1 or 0.
 * SpecialBool uses that byte to its fullest potential by using individual bits within the byte.
 * 
*/
const byte PROGMEM button = 4;
const byte PROGMEM blue = A0;
const byte PROGMEM yellow = A1;

Timer butt_state(2000, 1);      
/*Timer means we are calling the Timer class from the JameSpecialBool library, think of a class as another data
//type that can be declared by the programmer. butt_state is the name of the instance of this data type just like
//naming a variable. Because the declaration of the Timer class looks like this: Timer::Timer(unsigned long time_, bool on)
//whenever we initialize a Timer variable we have to include a time and a true or false depending if it's an on-delay (true) or off-delay (false).
*/ 
Timer butt_state_off(2000, 0);
//byte count = 0;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop() {
  /*Two options:
  //butt_state.write(not digitalRead(button));          //Must write to the variable to get rise and fall status
  //butt_state_off.write(not digitalRead(button));          //Must write to the variable to get rise and fall status
  //digitalWrite(blue, butt_state.Q());
  //digitalWrite(yellow, butt_state_off.Q());
   */

  //OR
  
    digitalWrite(blue, butt_state.input(not digitalRead(button)));           
  //state of led is true 2 seconds after button is pushed and being held
  digitalWrite(yellow, (butt_state_off.input(not digitalRead(button))));  
  //state of led is true for as long as button is being held and for 2 seconds after letting go
  
  //Blue light will act as output of our on-delay timer and yellow as our off-delay timer
}
