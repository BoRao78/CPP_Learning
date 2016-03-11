#include<iostream>
using namespace std;
int factorial(int n) //求n的阶乘
{
	int i, f = 1;
	for (i = 0; i <= n; i++) f *= i;
	return f;
}
int main()
{
	int x, result;
	cout << "请输入一个正整数：";
	cin >> x;
	result = factorial(x);//调用阶乘函数
	cout << "Factorial of " << x << " is " << result << endl;
	return 0;
}
