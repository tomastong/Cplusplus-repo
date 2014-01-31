/*===============================Program Description====================================
程序名称：抽象类.cpp
程序目的：
Written By Dong-Hong-Yan(2012-5-16)
========================================================================================*/

#include<iostream>
#include<cmath>           //包含数学文件

using namespace std;

//定义抽象类figure
class figure  {
    public:
        virtual void draw( void ) = 0;      //声明纯虚函数draw()
        virtual void area( void ) = 0;      //声明纯虚函数draw()
};

class circle :public figure {       //从基类figure派生circle类
    public:
        float r;
    public:
            circle( float radius ):r( radius )  {}   //定义circle类构造函数
            void draw( void );               //声明基类中的纯虚函数draw()
            void area( void );               //声明基类中的纯虚函数area()
};

void circle::draw( void )  {
    cout << "画出一个圆！"  << endl;
}

void circle::area( void )  {
    cout << "半径是10的圆面积是：" << 3.14 * r * r << endl;
}

class triangle : public figure  {      //从基类figure派生triangle类， triangle不再是抽象类
    public:
        float a;
        float b;
        float c;
        triangle( float f1, float f2, float f3 )  {
            a = f1;
            b = f2;
            c = f3;
        }
        void draw( void );
        void area( void );
};

void triangle::draw( void )  {
    cout << "画出一个三角形！" << endl;
}

void triangle::area( void )  {      //利用海伦公式求面积
    float s;
    s = ( a + b + c ) / 2;
    cout << "边长为（3,4,5）的三角形面积是： "  << sqrt( s*(s-a)*(s-b)*(s-c) ) << endl;
}

int main()  {
    circle c1(10);
    triangle t1 (3, 4, 5);
    c1.draw();
    c1.area();
    t1.draw();
    t1.area();

    return 0;
}
