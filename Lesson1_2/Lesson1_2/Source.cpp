#include<iostream>
using namespace std;
int factorial(int n) //��n�Ľ׳�
{
	int i, f = 1;
	for (i = 0; i <= n; i++) f *= i;
	return f;
}
int main()
{
	int x, result;
	cout << "������һ����������";
	cin >> x;
	result = factorial(x);//���ý׳˺���
	cout << "Factorial of " << x << " is " << result << endl;
	return 0;
}
