#include<iostream>
using namespace std;

//Point类的定义
//公有函数中，第一个，第二个函数是重载函数，参数不同
class Point {
	//外部接口
public:     
	//构造函数
	Point (int xx=0,int yy=0)  {                            
		x=xx;
		y=yy;
	}
	//复制构造函数的声明
	Point (Point &p);
	int getX()  {
		return x;
	}
	int getY()  {
		return y;
	}
	//私有数据
private:
	int x,y;
};

//成员函数的实现
Point::Point (Point &p)  {
	x=p.x;
	y=p.y;
	cout<<"Calling the copy constructor"<<endl;
}

//形参为point类对象的函数
//这里出现函数实参传递形参，Point p=b;即Point p(b);，再次调用copy函数
void fun1(Point p)  {
	cout<<p.getX()<<endl;
}

//返回值为point类对象的函数
Point fun2()  {
	Point a(1,2);//调用类成员中，第一个公有函数
	return a;
}

//主程序
int main()  {
	//第一个对象a
	Point a(4,5);
	//情况1，用a初始化b，第一次调用复制构造函数，也可以Point b(a);
	Point b=a;                                                         
	cout<<b.getX()<<endl;                                            
	//情况2，对象b作为fun1的实参，第二次调用复制构造函数
	fun1(b);
	//情况3，函数的返回值是类对象，函数返回时，调用复制构造函数
	b=fun2();
	cout<<b.getX()<<endl;
	return 0;
}


//主函数中，第一.第二个语句由于参数不同，分别调用不同函数，
// 也可以这样理解，先定义point=b，无参数（默认为0，是原点），故调用第一个函数，然后a赋值b调用第二个函数 