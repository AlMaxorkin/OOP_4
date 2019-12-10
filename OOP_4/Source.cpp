#include <iostream>
#include "Time.h"
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	Time obj1(11, 11, 11);
	Time obj2("22:22:22");
	Time obj3;
	Time obj4(444985);

	cout << obj1.info() << endl;
	cout << obj2.info() << endl;
	cout << obj3.info() << endl;
	cout << obj4.info() << endl;

	
	cout << endl;
	obj1.adding_seconds(234);
	obj2.subtract_seconds(123);
	obj3.compare(obj1); cout << endl;
	cout << "Minutes: " << obj4.minutes_conversion() << endl;
	cout << "Seconds: " << obj4.seconds_conversion() << endl;
	cout << "Difference: "<< obj1.difference(obj2) << endl;
	cout << endl;


	cout << obj1.info() << endl;
	cout << obj2.info() << endl;
	cout << obj3.info() << endl;
	cout << obj4.info() << endl;


	return 0;
}