#include "iostream"
#include "stdlib.h"
using namespace std;

class Complex {
public:
	Complex(double r = 0.0, double i = 0.0) {real = r; imag = i;}
	void display() const { cout << real << '+' << imag << 'i'<<endl; }
	Complex add(const Complex &x) const;   //��Ա����
	friend Complex Complex_add(const Complex &x1, const Complex &x2);//ȫ�֡���Ԫ����
	//��Ա��������������
	Complex operator +(const Complex &x); 
	bool operator ==(const Complex &x)const {return(real == x.real) && (imag == x.imag);}
	bool operator !=(const Complex &x)const {return!(*this == x);}
	Complex & operator ++() { //ǰ��
		real++, imag++; return *this;
	}
	const Complex operator ++(int) { //����
		Complex temp = *this; ++(*this); return temp; 
	}
	//ȫ����Ԫ����������
	friend Complex operator +(const Complex &c1, const Complex &c2);
	friend Complex operator +(const Complex &c, double d);
	friend Complex operator +(double d, const Complex &c);
private:
	double real;
	double imag;
};

Complex Complex::add(const Complex &x)const { //&��ʾ���ݵ����������ͣ���ֱ�����õ�ַ
	Complex temp;
	temp.real = real + x.real;//This "real" belongs to "this" pointer
	temp.imag = imag + x.imag;
	return temp;
}

Complex Complex_add(const Complex &x1,const Complex &x2) {//���������Ĳ�ͬ
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

