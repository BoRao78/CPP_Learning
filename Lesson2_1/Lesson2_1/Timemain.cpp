#include "Time.h"
#include<iostream>
using namespace std;

int main(){
	Time T1 = Time(11, 22, 04);
	T1.display();
	T1.set(12, 11, 05);
	T1.display();
	T1.increment();
	T1.display();
	cout << T1.equal(Time(12, 11, 06)) << endl;
	cout << T1.less_than(Time(12, 11, 15)) << endl;
	getchar();
    return 0;
}

