// Lesson1_3.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include<math.h>
const double ANG_TO_RAD = 0.0174532925;
using namespace std;

class angle {
	double value;
public:
	void SetValue(double);
	double GetSine(void);
} deg;

void angle::SetValue(double a) {
	value = a;
}

double angle::GetSine(void) {
	double temp;
	temp = sin(ANG_TO_RAD * value);
	return temp;
}
int main()
{
	deg.SetValue(60.0);
	cout << "The sine of the angle is:";
	cout << deg.GetSine() << endl;
	getchar();
}

