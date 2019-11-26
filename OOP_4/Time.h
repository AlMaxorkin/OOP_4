#pragma once
#include <iostream>

class Time
{
	int hour;
	int minute;
	int second;
public:
	Time(int H, int M, int S) : hour(H), minute(M), second(S) {};
	Time(char str[8]);
	Time(int sec);
	Time();
	~Time();
	void show();
	int difference(Time obj);
	void adding_seconds(int sec);
	void subtract_seconds(int sec);
	void compare(Time obj);
	int seconds_conversion();
	int minutes_conversion();
};

