#include "iostream"
#include "stdlib.h"
using namespace std;

class Complex {
public:
	Complex(double r = 0.0, double i = 0.0) {real = r; imag = i;}
	void display() const { cout << real << '+' << imag << 'i'<<endl; }
	Complex add(const Complex &x) const;   //成员函数
	friend Complex Complex_add(const Complex &x1, const Complex &x2);//全局、友元函数
	//成员函数操作符重载
	Complex operator +(const Complex &x); 
	bool operator ==(const Complex &x)const {return(real == x.real) && (imag == x.imag);}
	bool operator !=(const Complex &x)const {return!(*this == x);}
	Complex & operator ++() { //前置
		real++, imag++; return *this;
	}
	const Complex operator ++(int) { //后置
		Complex temp = *this; ++(*this); return temp; 
	}
	//全局友元操作符重载
	friend Complex operator +(const Complex &c1, const Complex &c2);
	friend Complex operator +(const Complex &c, double d);
	friend Complex operator +(double d, const Complex &c);
private:
	double real;
	double imag;
};

Complex Complex::add(const Complex &x)const { //&表示传递的是引用类型，即直接引用地址
	Complex temp;
	temp.real = real + x.real;//This "real" belongs to "this" pointer
	temp.imag = imag + x.imag;
	return temp;
}

Complex Complex_add(const Complex &x1,const Complex &x2) {//参数个数的不同
	Complex temp;
	temp.real = x1.real + x2.real;
	temp.imag = x1.imag + x2.imag;
	return temp;
}

Complex Complex::operator +(const Complex &x) {
	Complex temp;
	temp.real = real + x.real;//This "real" belongs to "this" pointer
	temp.imag = imag + x.imag;
	return temp;
}

Complex operator +(const Complex &c1, const Complex &c2) {
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
Complex operator +(const Complex &c, double d) {
	return Complex(c.real + d, c.imag);
}
Complex operator +(double d, const Complex &c) {
	return Complex(d + c.real, c.imag);
}

int main(){
	Complex a(1.0, 2.0), b(3.1, 4.2), c;
	c = a.add(b);
	c.display();
	system("PAUSE");
	return 0;
}

