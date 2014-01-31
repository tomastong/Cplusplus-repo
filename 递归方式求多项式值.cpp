/*========Program Description=========
程序名称：Legendre.cpp
程序目的：运用递归的方式求多项式的值
Written By Dong-Hong Yan
======================================*/

#include<iostream>
using namespace std;

//定义勒让德多项式函数，返回double类型
double Legendre( int n,double x)  {
	if(n==0)
		return 1;
	else if(n==1)
		return x;
	else 
	//切记是2*n，否则编译错误 
		return ((2*n-1)*x*(Legendre( n-1, x))-(n-1)*Legendre( n-2, x))/n;

}

//主程序
int main()  {

	//定义变量n和自变量x
	int num;
	double x;
	cout<<"Please enter num and x:";
	cin>>num>>x;
	cout<<"The result of Legendre is :"<<Legendre( num, x)<<endl;
	return 0;
}
