/*--------------Program  Description-----------
程序名称：构造函数.cpp
程序目的：调用类成员以及构造函数 
Written By Dong-Hong yan（WANT Studio）
=================================================*/

#include<iostream>
using namespace std;

//Clock的定义
class Clock  {
	//外部接口
public:
	//构造函数里的参数是“私有数据”，不是函数参数，
	//如果没有构造函数，编译通不过，嘻嘻
	Clock (int newH,int newM,int newS);
	void setTime(int newH,int newM,int newS);
	void showTime();
	//私有数据
private:
	int hour,minute,second;
};
//构造函数的实现
Clock::Clock(int newH,int newM,int newS)  {
	hour=newH;
	minute=newM;
	second=newS;
}
//成员函数的实现，类型后函数前加上类的名称
void Clock::setTime(int newH,int newM,int newS)  {
	hour=newH;
	minute=newM;
	second=newS;
}
//定义为内联函数
inline void Clock::showTime()  {
	cout<<hour<<":"<<minute<<":"<<second<<endl;
}

//主程序
int main()  {
	//该语句必须有参数，如果有默认值的话，也写成Clok c;
	Clock c(0,0,0);
	c.showTime();
	c.setTime(8,30,30);
	c.showTime();
	return 0;
}
