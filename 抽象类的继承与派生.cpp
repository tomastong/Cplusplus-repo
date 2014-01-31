//程序7-5

#include<iostream>
#include<cmath>
using namespace std;

const double PI = 3.1515926;

//定义抽象类Shape
class Shape  {
    public:
        Shape( int num1 = 0 ): num1(num1) {}
        virtual void Input() = 0;              //纯虚函数
        virtual void Output() = 0;             //纯虚函数
        virtual double getArea() = 0;          //纯虚函数
        float num1;
};

//定义矩形类
class Rectangle : public Shape {
    public:
        Rectangle( int num2 = 0 ): num2(num2)  {}
        void Input()  {
            cout << "请输入矩形的长和宽:";
            cin >> num1 >> num2;
        }
        void Output()  {
            cout << "矩形面积是:" << getArea() << endl << endl;
        }
        double getArea()  {
            return num1 * num2;
        }
    private:
        double num2;
};

//定义Circle类
class Circle :  public Shape {
    public:
        Circle()  {}
        void Input()  {
            cout << "请输入圆的半径:";
            cin >> num1;
        }
        void Output()  {
            cout << "圆的面积是:" << getArea() << endl << endl;
        }
        double getArea()  {
            return PI * pow( num1, 2 );
        }
};

//定义Square类
class  Square: public Rectangle {
    public:
        void Input()  {
            cout << "请输入正方形的边长:";
            cin >> num1;
        }
        void Output()  {
            cout << "正方形面积是:" << getArea() << endl << endl;
        }
        double getArea()  {
            return pow( num1, 2 );
        }
};

//主程序
int main()  {
    Shape * shape;         //定义基类指针

    shape = new Rectangle;  //分别访问派生类成员函数
    shape->Input();
    shape->Output();
    delete shape;

    shape = new Circle;    //分别访问派生类成员函数
    shape->Input();
    shape->Output();
    delete shape;

    shape = new Square;   //分别访问派生类成员函数
    shape->Input();
    shape->Output();
    delete shape;

    return 0;
}

//1、在继承类中，如果对私有成员、保护成员进行了初始化，即有默认值，
//   则在派生类中，不用再初始化，省事！！！
//2、只有在在多重继承（一定要区分多层继承）中，才用虚基类，是因为
//   怕继承路径不同，而重复初始化基类变量！
//3、注意：虚函数不是函数函数重载，函数重载是相同函数名，参数类型或个数不同！

