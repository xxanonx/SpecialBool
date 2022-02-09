/*
  JameSpecialBool.cpp - Library for special bools and tools.
  Created by McKinley James Pollock, Febuary, 2022.
  Released into the public domain.
*/

#include "Arduino.h"
#include "JameSpecialBool.h"

JameSpecialBool::JameSpecialBool(){
	special = 0;
}

bool JameSpecialBool::actual(){
	return bitRead(special, 0);
}

bool JameSpecialBool::actualNot(){
	return not bitRead(special, 0);
}

bool JameSpecialBool::rise(){
	return bitRead(special, 2);
}

bool JameSpecialBool::fall(){
	return bitRead(special, 3);
}

bool JameSpecialBool::change(){
	return bitRead(special, 4);
}

void JameSpecialBool::write(byte val){
	if (val < 2){
		bitWrite(special, 1, bitRead(special, 0));									//Write previous state
		bitWrite(special, 0, val);													//Write actual state
		bitWrite(special, 2, (bitRead(special, 0) && not (bitRead(special, 1))));	//Write true when rising edge
		bitWrite(special, 3, ( not (bitRead(special, 0)) && bitRead(special, 1)));	//Write true when falling edge
		bitWrite(special, 4, (bitRead(special, 2) || bitRead(special, 3)));			//Write true when change occurs
	}
}

bool JameSpecialBool::auxR(int num){
	if (0 < num < 4){
		return bitRead(special, (num + 4));
	}
}

void JameSpecialBool::auxW(int num, byte val){
	if ((0 < num < 4) and (val < 2)){
		bitWrite(special, (num + 4), val);
	}
}



Timer::Timer(unsigned long time_, bool on){
	this->setTime(time_);
	in.auxW(2, on);
}

void Timer::setTime(unsigned long time_){
	this->time = time_;
}

bool Timer::input(bool in_){
	in.write(in_);
	if (in.auxR(2)){
		//On Delay Timer
		if (in.rise()){
			initial_time = millis();
		}
		else if (in.fall()){
			in.auxW(1,0);
			initial_time = 0;
		}
	}
	else if (not in.auxR(2)){
		//Off Delay Timer
		if (in.fall()){
			initial_time = millis();
		}
		else if (in.actual()){
			initial_time = 0;
			in.auxW(1,1);
		}
	}
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
	//ALOT OF SHIT IS GOING ON HERE!!!!
	if (initial_time > 0){
		if ((millis() - initial_time) >= this->time){
			if (in.actual() == in.auxR(2)){
				in.auxW(1,in.auxR(2));
			}
			
		}
		else{
			in.auxW(1, (not in.auxR(2)));
		}
	}
	
	return in.auxR(1);
}

