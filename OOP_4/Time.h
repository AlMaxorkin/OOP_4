#pragma once
#include <iostream>

class Time
{
	int hour;
	int minute;
	int second;
public:
	Time(int H, int M, int S) : hour(H), minute(M), second(S) {};
	Time(std::string);
	Time(int sec);
	Time();
	~Time();
	std::string info();
	int difference(Time &obj);
	void adding_seconds(int sec);
	void subtract_seconds(int sec);
	int seconds_conversion();
	int minutes_conversion();
	bool operator == (Time&);
	bool operator != (Time&);
	bool operator <= (Time&);
	bool operator >= (Time&);
	bool operator < (Time&);
	bool operator > (Time&);
};

