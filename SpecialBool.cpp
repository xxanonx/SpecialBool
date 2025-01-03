/*
  SpecialBool.cpp - Library for special bools and tools.
  Created by McKinley James Pollock, Febuary, 2022.
  Released into the public domain.
*/

#include "Arduino.h"
#include "SpecialBool.h"

SpecialBool::SpecialBool(){
	//Serial.begin(9600);
	//Serial.println(sizeof(special));
}

bool SpecialBool::actual(){
	return special.a;
}

bool SpecialBool::actualNot(){
	return not special.a;
}

bool SpecialBool::rise(){
	return special.c;
}

bool SpecialBool::fall(){
	return special.d;
}

bool SpecialBool::change(){
	return special.e;
}

void SpecialBool::write(byte val){
	if (val < 2){
		special.b = special.a;								//Write previous state
		special.a = val;									//Write actual state
		special.c = (special.a and not special.b);			//Write true when rising edge
		special.d = ((not special.a) and special.b);		//Write true when falling edge
		special.e = (special.c or special.d);				//Write true when change occurs
	}
}




Timer::Timer(unsigned long time_, bool on){
	this->time = time_;
	in.special.g = on;
}

bool Timer::input(bool in_){
	in.write(in_);
	
	if (in.special.g){
		//On Delay Timer
		if (in.rise()){
			initial_time = millis();
		}
		else if (in.fall()){
			in.special.f = 0;
			initial_time = 0;
		}
	}
	else{
		//Off Delay Timer
		if (in.fall()){
			initial_time = millis();
		}
		else if (in.actual()){
			initial_time = 0;
			in.special.f = 1;
		}
	}
	/*
	bool ond = in.auxR(2);
	if ((in.rise() and ond) or (in.fall() and not ond)){
		initial_time = millis();
	}
	else if (in.fall() and ond){
		in.auxW(1,0);
		initial_time = 0;
	}
	else if (in.actual() and not ond){
		initial_time = 0;
		in.auxW(1,1);
	}
	*/
	return this->Q();
}

bool Timer::Q(){
	/*
	if (in.actual() and in.auxR(2)){
		//On Delay Timer
		if ((initial_time > 0) and ((millis() - initial_time) >= this->time)){
			in.auxW(1,1);
		}
		else{
			in.auxW(1,0);
		}
	}
	else if (in.actualNot() and not in.auxR(2)){
		//Off Delay Timer
		if (initial_time > 0){
			if ((millis() - initial_time) >= this->time){
				in.auxW(1,0);
			}
			else{
				in.auxW(1,1);
			}
		}
	}
	*/
	//A LOT OF SHIT IS GOING ON HERE!!!!
	if (initial_time > 0){
		if ((millis() - initial_time) >= this->time){
			if (in.actual() == in.special.g){
				in.special.f = in.special.g;
			}
			
		}
		else{
			in.special.f = not in.special.g;
		}
	}
	
	return in.special.f;
}

