#include "Time.h"
#include <iostream>
#include <Windows.h>
#include <string>

Time::Time(std::string str)
{
	std::string h = str.substr(0, 2);
	std::string m = str.substr(3, 2);
	std::string s = str.substr(6, 2);

	hour = atoi(h.c_str()) % 24;
	minute = atoi(m.c_str());
	second = atoi(s.c_str());
}

Time::Time()
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	hour = st.wHour + 3;
	minute = st.wMinute;
	second = st.wSecond;

}

Time::Time(int sec)
{
	hour = sec / 3600 % 24;
	minute = sec %3600 / 60;
	second = sec % 3600 % 60;
}

Time::~Time()
{
	std::cout << "\nDestructor for " << info() << std::endl;
}

std::string Time::info()
{
	 return std::to_string(hour) + ':' + std::to_string(minute) + ':' + std::to_string(second);  
}

int Time::difference(Time &obj)
{
	return abs(hour - obj.hour) * 3600 + abs(minute - obj.minute)*60 + abs(second - obj.second) ;
}

void Time::adding_seconds(int sec)
{
	hour += sec / 3600 % 24;
	minute += sec % 3600 / 60;
	second += sec % 3600 % 60;

	if (second > 60)
	{
		minute++;
		second = second - 60;
	}
	if (minute > 60)
	{
		hour++;
		minute = minute - 60;
	}
	if (hour > 23)
	{
		hour = hour - 24;
	}
}

void Time::subtract_seconds(int sec)
{
	hour -= sec / 3600 % 24;
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
		hour = 23;
	}
}

int Time::seconds_conversion()
{
	return hour * 3600 + minute * 60 + second;
}

int Time::minutes_conversion()
{
	int res = hour * 60 + minute;
	if (second >= 30)
		res++;
	return res;
}

bool Time::operator ==(Time &obj)
{
	return hour == obj.hour && minute == obj.minute && second == obj.second;
}

bool Time::operator <(Time& obj)
{
	if (hour < obj.hour)
		return true;
	else if (hour > obj.hour)
		return false;
	
	if (minute < obj.minute)
		return true;
	else if (minute > obj.minute)
		return false;

	if (second < obj.second)
		return true;
	else
		return false;
	
}

bool Time::operator >(Time& obj)
{
	if (hour > obj.hour)
		return true;
	else if (hour < obj.hour)
		return false;

	if (minute > obj.minute)
		return true;
	else if (minute < obj.minute)
		return false;

	if (second > obj.second)
		return true;
	else
		return false;
}

bool Time::operator <=(Time& obj)
{
	if (hour < obj.hour)
		return true;
	else if (hour > obj.hour)
		return false;
	
	if (minute < obj.minute)
		return true;
	else if (minute > obj.minute)
		return false;

	if (second < obj.second)
		return true;
	else if (second > obj.second)
		return false;
	else
		return true;

}

bool Time::operator >=(Time& obj)
{
	if (hour > obj.hour)
		return true;
	else if (hour < obj.hour)
		return false;

	if (minute > obj.minute)
		return true;
	else if (minute < obj.minute)
		return false;

	if (second > obj.second)
		return true;
	else if (second < obj.second)
		return false;
	else
		return true;
}

bool Time::operator !=(Time& obj)
{
	return !( hour == obj.hour && minute == obj.minute && second == obj.second);
}