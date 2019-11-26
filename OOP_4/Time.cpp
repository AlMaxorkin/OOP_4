#include "Time.h"
#include <iostream>

Time::Time(char str[8])
{
	char h[2] = { str[0] + str[1] };
	hour = atoi(h);

	char m[2] = { str[3] + str[4] };
	minute = atoi(m);

	char s[2] = { str[6] + str[7] };
	second = atoi(s);
}

Time::Time()
{

}

Time::Time(int sec)
{
	hour = sec / 3600;
	minute = sec %3600 / 60;
	second = sec % 3600 % 60;
}

Time::~Time()
{
	std::cout << "Destruct";
}

void Time::show()
{
	std::cout << hour << ":" << minute << ":" << second << std::endl;  
}

int Time::difference(Time obj)
{
	return abs(hour - obj.hour) * 3600 + abs(minute - obj.minute)*60 + abs(second - obj.second) ;
}

void Time::adding_seconds(int sec)
{
	hour += sec / 3600;
	minute += sec % 3600 / 60;
	second += sec % 3600 % 60;
}

void Time::adding_seconds(int sec)
{
	hour += sec / 3600 % 24;
	minute += sec % 3600 / 60;
	second += sec % 3600 % 60;
}

void Time::subtract_seconds(int sec)
{
	hour -= sec / 3600;
	minute -= sec % 3600 / 60;
	second -= sec % 3600 % 60;
	if (second < 0)
	{
		minute--;
		second = -second;
	}
	if (minute < 0)
	{
		hour--;
		minute = -minute;
	}
	if (hour < 0)
	{
		 
	}
}

void Time::compare(Time obj)
{
	if (hour > obj.hour)
	{
		show();
		std::cout << " > ";
		obj.show();
	}
	else if(hour < obj.hour)
	{
		show();
		std::cout << " < ";
		obj.show();
	}
	else if (minute < obj.minute)
	{
		show();
		std::cout << " < ";
		obj.show();
	}
	else if (minute > obj.minute)
	
}