/*-------------Program Description------------
程序名称：is_Parld.cpp
程序目的：判断一个数、平方以及立方是否回文
Written By Dong-Hong Yan(WANT Studio)
----------------------------------------------*/


#include<iostream>
using namespace std;

//判断n是否回文数，返回值为bool型
bool is_Pald(unsigned int n) {
 
	//定义无符号变量n
	unsigned i=n; 
	unsigned m=0;

	while(i>0)  {
	
		m=m*10+i%10;      //此方法很不错，通过求每位数据，逆乘相加与原数相比较
		i/=10;
	}
    return m==n; //此句很不错，通过m==n进行判断，从而返回true、false
}

//主函数
int main()  {
	for(unsigned m=11;m<1000;m++)  {

		//该种方法很好，判断一个数调用一个函数
		if(is_Pald(m)&&is_Pald(m*m)&&is_Pald(m*m*m))  {
			cout<<"m="<<m;
			cout<<"   m*m="<<m*m;
			cout<<"   m*m*m="<<m*m*m<<endl;
		}
	}
	return 0;
}
