/*===================================Program Description=====================================
程序名称：程序8-7.cpp.cpp
程序目的：运算符重载自加自减，分为前缀和后缀
Written By Dong-Hong-Yan（2012-6-5）
===========================================================================================*/

#include<iostream>
using namespace std;

//定义点类
class Point {
    public:
        Point(double x/*=0*/, double y/*=0*/);   //带有默认形参值
        ~Point()  {}
        Point &operator ++();                  //重载前置运算符
        Point &operator ++(int);               //重载后置运算符
        Point &operator --();                  //重载前置运算符
        Point &operator --(int);               //重载后置运算符
        friend ostream &operator << (ostream &out, const Point &right);  //重载<<运算符
    private:
        double x;
        double y;
};
//构造函数
Point::Point(double x = 0, double y = 0) {
    this->x = x;
    this->y = y;
}
//重载函数定义
Point &Point::operator ++()  {
    y++;
    x++;

    return * this;
}
//重载函数定义
Point &Point::operator ++(int)  {
    Point Temp = * this;
    ++(* this);
    return Temp;
}
//重载函数定义
Point &Point::operator --()  {
    y--;
    x--;

    return * this;
}
//重载函数定义
Point &Point::operator --(int)  {
    Point Temp = * this;
    --(* this);
    return Temp;
}
//重载函数定义
ostream &operator << (ostream &out, const Point &right) {
    cout << "(" << right.x << "," << right.y << ")";
    return out;
}

//[主程序]
int main()  {
    Point obj1(2, 3), obj2;    //声明并初始化对象
    cout << "前缀自加前：" << obj1 << endl; ++obj1; cout << "前缀自加后：" << obj1 << endl << endl;
    cout << "后缀自加前：" << obj1 << endl; obj1++; cout << "后缀自加后：" << obj1 << endl << endl;
    cout << "前缀自减前：" << obj2 << endl; --obj2; cout << "前缀自减后：" << obj2 << endl << endl;
    cout << "后缀自减前：" << obj2 << endl; obj2--; cout << "后缀自减后：" << obj2 << endl << endl;

    return 0;
}
