/*
  JameSpecialBool.h - Library for special bools and tools.
  Created by McKinley James Pollock, Febuary, 2022.
  Released into the public domain.
*/
#ifndef SpecialBool_h
#define SpecialBool_h

#include "Arduino.h"

struct sbool{
	unsigned int a:1;
	unsigned int b:1;
	unsigned int c:1;
	unsigned int d:1;
	unsigned int e:1;
	unsigned int f:1;
	unsigned int g:1;
	unsigned int h:1;
};

class SpecialBool
{
  public:
    SpecialBool();
    bool rise();
    bool fall();
	bool change();
	void write(byte val);
	bool actual();
	bool actualNot();
	sbool special;
};

class Timer
{
  public:
    Timer(unsigned long time_, bool on);
	bool input(bool in_);
	bool Q();
	unsigned long time;
  private:
	SpecialBool in;
	unsigned long initial_time;
};

#endif