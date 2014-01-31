/*=========Program Ddescription=========
程序名称：pret_parameter.cpp
程序目的：编写一个具有默认形参值的函数,求
圆的面积
Written By-DongHong Yan
========================================*/

#include<iostream>
using namespace std;

//常量定义
const double PI=3.1415926;

//带默认形参的面积函数
double area(double r=1.0)  {
	return PI*r*r;
}

//主程序
int main()  {
	double radius;
	cout<<"The pretermit area is :"<<area()<<endl;
	cout<<"Please enter the radius of area:";
	cin>>radius;
	cout<<"The area is :"<<area(radius)<<endl;
	return 0;
}


