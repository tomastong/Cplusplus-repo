/*===========================Program Description=====================================
程序名称：访问对象公有成员函数的不同方式.cpp
程序目的：熟悉分别用对象名、对象指针、成员函数指针和对象名、成员函数指针和对象指针访问
Written By Dong-Hong-Yan(2012-4-19)
=====================================================================================*/

#include<iostream>
using namespace std;

//【Point类】
class Point {
    public:
        Point(int x = 0, int y = 0) :x(x), y(y)  {}
        int getX() const  {return x;}
        int getY() const  {return y;}
    private:
        int x, y;
};

//【主程序】
int main()  {
    Point a(4, 5);
    Point *p1 = &a;         //定义对象指针并初始化

    //在这里，函数的getX()的参数表表示到前面，而在后面什么也不用写
    int (Point::*funcPtr)()const = &Point::getX;     //定义成员函数指针并初始化


    cout << (a.*funcPtr)() << endl;      //使用成员函数指针和对象名访问成员函数
    cout << (p1->*funcPtr)() << endl;    //使用成员函数指针和对象指针访问成员函数
    cout << a.getX() << endl;            //适用对象名访问成员函数
    cout << p1->getX() << endl;          //使用对象指针访问成员函数

    return 0;
}
