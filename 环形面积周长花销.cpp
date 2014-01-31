/*====================Program  Description========= 
程序名称：环形面积周长花销.cpp
程序目的：求环形的面积周长建设消费 
程序要求：通过运用类，解决问题 
Written By Dong-Hong yan（WANT Studio）
=================================================*/

#include<iostream>
using namespace std;

//在这里，const相当于宏定义#define
//给出π的值
const double PI=3.1415926;
//栅栏的单价
const float FENCE_PRICE=35;
//过道水泥的单价
const float CONCRETE_PRICE=20;

//声明定义类circle及其数据和方法
class Circle  {
	//外部接口
public:
	//构造函数，形参可以不同于私有成员，但个数必一一对应
	Circle(float r);
	//计算圆的周长
	float circumference();
	//计算圆的面积
	float area();
	//私有数据成员
private:
	//圆半径
	float radius;
};

//类的实现，构造函数初始化数据成员radius
Circle::Circle(float r)  {
	radius=r;
}
//计算圆的周长
float Circle::circumference()  {
	return 2*PI*radius;
}
//计算圆的面积
float Circle::area()  {
	return PI*radius*radius;
}

//主程序
int main()  {
	float radius;
	//提示用户输入半径
	cout<<"Enter the radius of the pool:";
	cin>>radius;

	//游泳池边界的对象
	Circle pool(radius);
	//栅栏对象
	Circle poolRim(radius+3);

	//计算栅栏造价并输出
	float fenceCost=poolRim.circumference()*FENCE_PRICE;
	cout<<"Fencing Cost is $"<<fenceCost<<endl;
	
	//计算过道造价并输出
	float concreteCost=(poolRim.area()-pool.area())*CONCRETE_PRICE;
	cout<<"Concrete Cost is $"<<concreteCost<<endl;


	return 0;
}
/*【心得】在这个程序中，初始化类的对象有3种方法（有形参的情况）：
   1、在构造函数中，只给出形参，而没有给形参赋值，而是在主函数中进行输入初始化，声明一个类，参数是即将输入的半径。
   2、和1唯一不同的是，直接在主函数中，书写出将要计算的形参值，即Circle pool(5);
   3、第三种即是，在类中定义一个input()函数，在主函数中调用输入函数*/
