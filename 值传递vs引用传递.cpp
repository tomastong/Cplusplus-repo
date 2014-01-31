/*-------------Program Description------------
程序名称：val_Pass.cpp
程序目的：值传递与引用传递的比较
Written By Dong-Hong Yan(WANT Studio)
----------------------------------------------*/

#include<iostream>
//因为用到setw()函数，用此头文件
#include<iomanip>
using namespace std;

//定义函数，值传递（in1）和引用传递（in2）
void fiddle(int in1,int &in2)  {
	in1=in1+100;
	in2=in2+100;
	cout<<"The values are: ";
	cout<<setw(5)<<in1;
	cout<<setw(5)<<in2<<endl;
}

int main()  {
	int v1=7,v2=12;
	cout<<"The values are ";
	cout<<setw(5)<<v1;
	cout<<setw(5)<<v2<<endl;
	fiddle(v1,v2);            //函数作用效果是，有地址的变量值完全变了
	cout<<"The values are ";

	//引用setw函数的使用格式
	cout<<setw(5)<<v1;
	cout<<setw(5)<<v2<<endl;
	return 0;

}
