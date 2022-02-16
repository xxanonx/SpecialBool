#include <JameSpecialBool.h>
/*
 * JameSpecialBool is a class that helps keep memory usage low and has great uses built in!
 * arduino bools take up a whole byte even though it's states can only be 1 or 0.
 * JameSpecialBool uses that byte to its fullest potential by using individual bits within the byte.
 * 
*/
byte button = 4;
byte blue = A0;
byte yellow = A1;
JameSpecialBool butt_state;      
byte count = 0;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop() {
  butt_state.write(not digitalRead(button));
  
  digitalWrite(blue, (butt_state.rise() or butt_state.auxR(1)));  //state of led is either on rising edge or the state of auxillary bit 1
  digitalWrite(yellow, (butt_state.fall() or butt_state.auxR(2)));//state of led is true on falling edge or the state of auxillary bit 2

  if (butt_state.rise()){
    //only execute on rising edge
    count++;
    switch (count){

    case 10:
      butt_state.auxW(1, 1);  //if the count is 10 write true to auxillary bit one
      break;
    case 20:
      butt_state.auxW(2, 1);  //if the count is 20 write true to auxillary bit two
      break;
    case 30:
      butt_state.auxW(1, 0);  //if the count is 10 write true to auxillary bit one
      butt_state.auxW(2, 0);
      count = 0;
      break;
    }
  }
  if (butt_state.change()){
    delay(50);  //make led turning on noticeable
  }
}
