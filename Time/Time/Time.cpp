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
	return (hour == x.hour)&&(minute = x.minute)&&(second = x.second);
}

bool Time::less_than(Time const & x){
	if (hour > x.hour) 
		return false;
	else if (hour < x.hour)
		return true;
	else {
		if (minute > x.minute)
			return false;
		else if (minute < x.minute)
			return true;
		else {
			if (second > x.second)
				return false;
			else
				return true;
		}
	}
}

Time & Time::operator=(Time const & x){
	hour = x.hour, minute = x.minute, second = x.second;
	return *this;
}

Time::operator int(){
	return hour * 3600 + minute * 60 + second;
}

Time::Time(int x){
	hour = x / 3600, minute = x % 3600 / 60, second = x % 60;
}

void Time::Time_vaildate(){
	if (second > 59) { minute += second / 60; second = second % 60; }
	if (minute > 59) { hour += minute / 60; minute = minute % 60; }
	if (hour > 23)  hour = hour % 24; 
}

bool Time::operator==(Time const & x){
	return (hour == x.hour)&&(minute = x.minute)&&(second = x.second);
}

bool Time::operator<(Time const & x){
	if (hour > x.hour)
		return false;
	else if (hour < x.hour)
		return true;
	else {
		if (minute > x.minute)
			return false;
		else if (minute < x.minute)
			return true;
		else {
			if (second > x.second)
				return false;
			else
				return true;
		}
	}
}

Time Time::operator+(int n){
	Time temp = Time(n);
	second += temp.second;
	minute += temp.minute;
	hour += temp.hour;
	temp.Time_vaildate();
	return temp;
}

Time Time::operator-(int n){
	Time temp = Time(n);
	second -= temp.second;
	if (second < 0) { minute--; second += 60; }
	minute -= temp.minute;
	if (minute < 0) { hour--; minute += 60; }
	hour -= temp.hour;
	if (hour < 0) { hour += 24; }
	temp.Time_vaildate();
	return temp;
}

Time Time::operator++(int){
	Time temp = *this;
	second++;
	(*this).Time_vaildate();
	return temp;
}

Time Time::operator--(int){
	Time temp = *this;
	second--;
	if (second < 0) { minute--; second += 60; }
	if (minute < 0) { hour--; minute += 60; }
	if (hour < 0) { hour += 24; }
	(*this).Time_vaildate();
	return temp;
}

int Time::operator-(Time const & x){
	Time temp = x;
	return int(*this) - int(temp);
}

Time & Time::getTime(){
	return Time(hour, minute, second);
}

void ExtTime::set(int t, int h, int m, int s){
	timezone = t;
	Time(h, m, s);
}

bool ExtTime::operator==(ExtTime & x){
	return (timezone == x.timezone) && (this->getTime() == x.getTime());
	return false;
}

bool ExtTime::operator<(ExtTime & x){
	if (timezone < x.timezone)
		return true;
	else if (timezone>x.timezone)
		return false;
	else
		return this->getTime() < x.getTime();
}

void ExtTime::display(){
	cout << "Timezone: +"<<timezone<< endl;
	Time::display();
}
