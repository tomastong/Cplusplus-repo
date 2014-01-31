/*=====================================================Program Description================================================
程序名称：c++的组织结构.cpp 
程序目的：通过该例子加深对c++组织结构理解 
Written By Dong-Hong-Yan(2012-4-15)
==========================================================================================================================*/

#include"1.h"
#include<iostream>

using namespace std;

//【主程序】 
int main()  {
    Point a(4, 5);
    cout<<"Point A: "<<a.getX()<<","<<a.getY();
    Point::showCount();                                 //静态函数成员，直接与类名连用 
    
    Point b(a);
    cout<<"Point B: "<<b.getX()<<","<<b.getY();
    Point::showCount();
    
    system("pause");
    return 0;
    }
