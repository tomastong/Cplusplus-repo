/*==========================================Program Description======================================
程序名称:复数类.cpp
程序要求：用复数3+5i初始化c1，用实数4.5初始化c2，将c1和c2相加，结果保存在c1中，将c1输出（这时的结果应
该是7.5+5i）
Written By Dong-Hong-Yan (2012-4-8)
=====================================================================================================*/

#include<iostream>
using namespace std;

//定义Complex类
class Complex {
	public:     //外部接口
		Complex(float num1 = 0, float num2 = 0):num1(num1), num2(num2)  {}
		Complex(Complex &p);
		void add(Complex pp);
		void show();
		float GetNum1()  {return num1;}
		float GetNum2()  {return num2;}
		~Complex()  {}
	private:   //私有数据
		float num1;           //复数的实数部 
		float num2;			//复数的虚数部
};

//定义复制构造函数
Complex::Complex(Complex &p): num1(p.num1), num2(p.num2) {
	cout<<"Calling the copy constructor!"<<endl;
}

//定义复数相加函数,将参数数据域当前默认的类的值相加，并保存 
void Complex::add(Complex pp)  {
	num1+=pp.GetNum1();
	num2+=pp.GetNum2();
}

//定义输出函数，输出当前的类的成员 
void Complex::show()  {
	cout<<num1<<"+"<<num2<<"i"<<endl;
}
//主程序
int main()  {
	Complex c1(3,5);
	Complex c2=4.5;
	c1.add(c2);
	c1.show();
	system("pause");
	return 0;
}
