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