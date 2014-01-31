#include<iostream>
using namespace std;

//Clock的定义
class Clock  {
	//外部接口，里边的函数相当于都是声明
public:
	//构造函数
	Clock (int newH,int newM,int newS);
	//定义了一个无参的构造函数
	Clock ()  {
		hour=1;
	    minute=2;
	    second=3;
	}
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
	//因为之前定义了一个无参的构造函数，这里不需要参数
	Clock c1;
	c1.showTime();
	c.showTime();
	c.setTime(8,30,30);
	c.showTime();
	return 0;
}
