#include "Time.h"
#include<iostream>
using namespace std;

void Time::set(int h, int m, int s){
	hour = h;
	minute = m;
	second = s;
}

Time & Time::increment(){
	second++;
	if (second >=60){
		second -= 60;
		minute++;
	}
	if (minute >= 60) {
		minute -= 60;
		hour++;
	}
	if (hour >= 24) {
		hour -=24;
	}
	return *this;
}

void Time::display(){
	cout << "Now the time is:" << endl;
	cout << hour << ':' << minute << ':' << second << endl;
}

bool Time::equal(Time const & x){
	if (hour == x.hour) {
		if (minute == x.minute)
			if (second == x.second)
				return true;
	}
	return false;
}

bool Time::less_than(Time const & x){
	if (hour > x.hour) 
		return true;
	else if (hour < x.hour)
		return false;
	else {
		if (minute > x.minute)
			return true;
		else if (minute < x.minute)
			return false;
		else {
			if (second > x.second)
				return true;
			else
				return false;
		}
	}
}
