/*----------------------------Program Description---------------------------
程序名称：指向类中非静态成员的指针.cpp
程序目的：本例编写一个Point类，通过指针访问非静态成员
Written By Dong-Hong-Yan(2012-5-27)
----------------------------------------------------------------------------*/

#include<iostream>

using namespace std;

class Point {             //类的声明
    public:
        Point( int x = 0, int y = 0, int z = 0 ) {    //构造函数
            X = x; Y = y; Z = z;
        }
        int GetX() const  {return X;}        //常内联函数
        int GetY() const {return Y;}         //常内联函数
        int GetZ() const {return Z;}         //常内联函数
    private:
        int X, Y, Z;
};

int main()  {
    Point Obj(4, 5, 6);            //声明对象Obj
    Point *pObj = &Obj;            //声明对象指针并初始化、

    //类成员指针指向函数的返回值类型，函数前的int是函数类型！
    int (Point::* p_GetX)() const = &Point::GetX;   //声明成员函数指针并初始化
    int (Point::* p_GetY)() const = &Point::GetY;   //声明成员函数指针并初始化
    int (Point::* p_GetZ)() const = &Point::GetZ;   //声明成员函数指针并初始化

    cout << "The Coordinate of X is " << (Obj.*p_GetX)() << endl; //使用成员函数指针
    cout << "The Coordinate of Y is " << (pObj->GetY)() << endl;//使用对象指针
    cout << "The Coordinate of Z is " << (Obj.GetZ)() << endl;  //使用对象名

    return 0;
}
/*【心得】
1、成员函数指针申明之后，用一下形式赋值
   指针名=&类名::成员函数;
2、调用成员函数指针
   （对象名.*类成员指针名）（形参表）  或者
    （对象指针名->*类成员指针名）（形参表）*/
