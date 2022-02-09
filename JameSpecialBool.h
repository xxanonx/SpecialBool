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

class Timer
{
  public:
    Timer(unsigned long time_, bool on);
    void setTime(unsigned long time_);
	bool input(bool in_);
	bool Q();
	unsigned long time;
  private:
	JameSpecialBool in;
	unsigned long initial_time;
};

#endif