/*===============================Program Description==================================
程序名称：求不同对象的表面积和体积.cpp
程序目的：通过继承来计算圆、球、圆柱和圆锥的表面积和体积。定义一个圆类，含半径成员。
          球类、圆柱类和圆锥类作为圆类的派生类。计算圆、球、圆柱和圆锥的表面积和体积。
程序要求：1. Ax 在C++中可以用函数pow(A,x)来表示;
          2. sqrt(x)用来表示x的开根号。
          3. 如果要用上述函数，请在头文件出添加#include <math.h>。
Written By Dong-Hong-Yan(2012-5-5)
======================================================================================*/

#include<iostream>
#include<cmath>
using namespace std;

const double PI = 3.14159;

//定义圆类
class Circle  {
    public:
        Circle( float radius = 0 )  {
            this->radius = radius;
            }
        ~Circle()  {}

        void input()  {
            cout << "请输入圆的半径" << endl;
            cin >> radius;
        }
        double Cir_Area()  {
            return PI * pow( radius, 2 );
        }
        double Cir_Volume() {
            return 0;
            }
    protected:
        float radius;
};

//定义球类
class Sphere : public Circle  {
    public:
        Sphere( float radius = 0 ) : Circle( radius ) {}
        ~Sphere()  {}

        void input()  {
            cout << "请输入球的半径" << endl;
            cin >> radius;
        }
        double Sph_Area()  {
                return 4 * PI * pow( radius, 2 );
        }
        double Sph_Volume()  {
                return 4.0 / 3 * PI * pow( radius, 3 );
        }
};

//定义圆柱类
class Cylinder : public Circle {
    public:
        Cylinder( float radius = 0, float height = 0 ) :Circle( radius ) {
            this->height = height;
        }
        ~Cylinder()  {}

        void input()  {
            cout << "请输入圆柱的高和圆柱的底面半径" << endl;
            cin >> radius >> height;
        }
        double Cyl_Area()  {
            return 2 * PI * pow( radius, 2) + 2 * PI * radius * height;
        }
        double Cyl_Volume()  {
            return PI * pow( radius, 2 ) * height;
        }
    protected:
        float height;
};

//定义圆锥类
class Cone : public Cylinder  {
    public:
        Cone( float radius = 0, float height = 0 ) {
            Cylinder( radius, height );
        }
        ~Cone()  {}

        void input()  {
            cout << "请输入圆锥的高和圆锥的底面半径" << endl;
            cin >> radius >> height;
        }
        double Con_Area()  {
            return PI * pow( radius, 2 ) + PI * radius * sqrt( pow(radius, 2) + pow( height, 2 ));
        }
        double Con_Volume()  {
            return 1.0 / 3 * Cyl_Volume();
        }
};

int main()  {

    Circle circle;
    Sphere sphere;
    Cylinder cylinder;
    Cone cone;

    circle.input();
    sphere.input();
    cylinder.input();
    cone.input();

    cout << "\n圆 面积   体积\n" << circle.Cir_Area() <<"    " << circle.Cir_Volume() << endl;
    cout << "球 表面积   体积\n" << sphere.Sph_Area() <<"  " << sphere.Sph_Volume() << endl;
    cout << "圆柱 表面积   体积\n" << cylinder.Cyl_Area() <<"  " << cylinder.Cyl_Volume() << endl;
    cout << "圆锥 表面积   体积\n" << cone.Con_Area() <<"  " << cone.Con_Volume() << endl;

    return 0;
}
