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

	T1 = Time(11, 18, 03);
	T1.display();
	cout << int(T1)<<endl;
	Time(7640).display();
	cout <<( T1==Time(11, 18, 03))<< endl;
	cout << (T1<Time(12, 11, 15)) << endl;
	T1 + 65; T1.display();
	T1 - 88; T1.display();
	T1++.display();
	T1--.display();
	T1.display();
	cout << (T1 - Time(10, 25, 00)) << endl;
	system("PAUSE");
    return 0;
}

