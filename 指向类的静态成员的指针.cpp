/*==================================================Program Description====================================================
程序名称：指向类的静态成员的指针.cpp 
程序目的：通过指针访问类的静态数据成员 
Written By Dong-Hong-Yan(2012-4-16)
===========================================================================================================================*/

#include<iostream>
using namespace std;

//【Point类】 
class Point  {
      public:          //外部接口 
             Point(int x = 0, int y = 0) :x(x), y(y)  {          //构造函数 
                       count++;
                       }
             Point(const Point &p) :x(p.x), y(p.y)  {            //复制构造函数 
                         count++;
                         }
             ~Point()  { count--; }                               //析构函数 
             
             int getX()  { return x; }
             int getY()  { return y; }
             
             static int count;                  //静态数据成员声明，用于记录点的个数 
      private:           //私有数据 
              int x, y; 
      }; 

int Point::count = 0;                    //静态数据成员定义和初始化，使用类名限定 

 //【主程序】 
int main()  {
    int *ptr = &Point::count;        //定义一个int型指针，指向类的静态成员   格式为  指针名=&类名::函数成员名 
    Point a(4, 5);                   //定义对象a 
    
    cout<<"Point A: "<<a.getX()<<","<<a.getY();
    cout<<"  Object count = "<<* ptr<<endl;          //直接通过指针访问静态数据成员
    
    Point b(a);                                //定义对象b 
    cout<<"Point B: "<<b.getX()<<","<<b.getY();
    cout<<"  Object count = "<<* ptr<<endl;          //直接通过指针访问静态数据成员 
    
    system("pause");
    return 0;
    }
