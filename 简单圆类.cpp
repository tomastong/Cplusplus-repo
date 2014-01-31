/*===========================Program Description=================================
程序名称：简单圆类.cpp
程序目的：定义一个简单圆类，用指针作为半径，进行动态申请
Written By Dong-Hong-Yan(2012-4-24)
=================================================================================*/

#include<iostream>
#include<string>
using namespace std;

const float PI = 3.14159f;         //定义PI为单精度常浮点数

//定义简单圆类
class SimpleCirCle  {
	public:
		SimpleCirCle()  {
			itsRadius = new int (0);    //用指针动态申请并初始化为0
		}
		~SimpleCirCle()  {              //定义析构函数，删除指针申请内存
			delete itsRadius;
			cout << "deleting ..." << endl;
		}

		void input();
		double itsArea();
        void display( string s );

	private:
		int * itsRadius;
};

void SimpleCirCle::input()  {
	cout << "Please enter the radius :";
	cin >> *itsRadius;           //输入时，必须带上指针全名
}

double SimpleCirCle::itsArea()  {
	return PI * (* itsRadius) * (* itsRadius);
}

//定义显示函数，用到string字符串，故参数用string 定义
void SimpleCirCle::display( string s )  {
	cout << s <<" = " << *itsRadius << endl;  //输出时，加不加星号，无所谓
}

//【主程序】
int main() {

    SimpleCirCle a;    //调用无参构造函数，初始化对象
	a.input();
	a.display( "itsRadius" );         //调用显示函数，输出相关信息
	cout << a.itsArea() << endl;

	return 0;
}
