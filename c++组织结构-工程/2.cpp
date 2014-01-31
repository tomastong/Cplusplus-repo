/*=====================================================Program Description================================================
程序名称：Point源文件.cpp 
程序目的：通过该例子加深对c++组织结构理解 
Written By Dong-Hong-Yan(2012-4-15)
==========================================================================================================================*/

#include"1.h"            //用双引号系统先在用户当前目录中寻找要包含的文件，然后在c库寻找 
#include<iostream>           //用户直接到c库中寻找要包含的文件 

using namespace std;

int Point::count = 0;         //使用类名初始化静态数据成员 

//复制构造函数体 
Point::Point(const Point &p) :x(p.x), y(p.y)  {   
                   count++;
                   }
                   
void Point::showCount()  {
     cout<<"  Object count = "<<count<<endl;
     }
