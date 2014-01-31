/*========Program Description========
程序名称:index_function.cpp
程序目的:编写整型和实型的两个重载函数
实现指数运算
Written By Dong-Hong Yan
=====================================*/

#include<iostream>
using namespace std;

//整型形式
int getPower(int x,int y) {

	//不允许输入负数情况
	if(y<=0)
		return 0;
	else if(y==1)
		return x;
	else
		return x*getPower(x,y-1);
}

//实型形式
double getPower(double x,int y)  {

	//不允许输入负数情况
	if(y<=0)
		return 0;
	else if(y==1)
		return x;
	else
		return x*getPower(x,y-1);
}

//主程序
int main()  {

	//定义变量底数整型和实型
	int i_basic;
	double d_basic;

	//定义指数变量
	int index;
	cout<<"Please enter i_basic,d_basic and index:";
	cin>>i_basic>>d_basic>>index;
	cout<<"The integer result is :"<<getPower( i_basic,index)<<endl;
	cout<<"The double result is :"<<getPower( d_basic,index)<<endl;
	return 0;
}