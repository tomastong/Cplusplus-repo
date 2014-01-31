/*-------------Program Description------------
程序名称：递归勒让德多项式.cpp
程序目的：通过递归求n阶勒让德多项式的值，公式为
Pn(x)=（1  n=0;x  n=1;[(zn-1)x*P(n-1)(x)-(n-1)*P(n-2)(x)]/n   n>1）
Written By Dong-Hong Yan(WANT Studio)
----------------------------------------------*/

#include<iostream>
using namespace std;

//定义函数，按公式用来计算处理m,切记定义为double型的，变量也是
double Legendre(int m,double x)  {

	//当m=0，时
	if(m==0)
		return 1;
	else if(m==1)

		//当m=1时，返回x
		return x;
	else

		//其他情况，进行循环调用，这里2m必须写成2*m，否则编译出错
		return ((2*m-1)*x*Legendre(m-1,x)-(m-1)*Legendre(m-2,x))/m;

}

//主函数
int main()  {
	//定义要输入的变量的值
	int Num;
	int x;

	//定义变量Result,用来接收函数返回值
	int Result;
	cout<<"Please enter a number num and x:";
	cin>>Num>>x;
	//接收函数返回值
	Result=Legendre(Num,x);
	cout<<"The result is "<<Result<<endl;
	return 0;

}