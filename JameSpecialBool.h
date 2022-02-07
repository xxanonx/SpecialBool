/*
  JameSpecialBool.h - Library for special bools and tools.
  Created by McKinley James Pollock, Febuary, 2022.
  Released into the public domain.
*/
#ifndef JameSpecialBool_h
#define JameSpecialBool_h

#include "Arduino.h"

class JameSpecialBool
{
  public:
    JameSpecialBool();
    bool rise();
    bool fall();
	bool change();
	void write(byte val);
	bool actual();
	bool actualNot();
	bool auxR(int num);
	void auxW(int num, byte val);
  private:
	byte special;
};

#endif