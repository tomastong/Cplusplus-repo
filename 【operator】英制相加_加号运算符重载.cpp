/*==============================Program Description==================================
程序名称：英制相加_加号运算符重载.cpp
程序目的：两个英制尺寸相加（1英尺=12英寸），两个时间相加（1小时=60分，1分=60秒）
          两个二进制、八进制和十六进制数相加，这时都应该创建相应的类，然后重载
          加号运算符，使两个类对象相加！
Written by Dong-Hong-Yan(2012-4-28)
=====================================================================================*/

#include<iostream>
#include<string>   //包含头文件
using namespace std;

//声明一个类Length
class Length  {
    public:
        Length();                       //声明无参构造函数
        Length( int , int );            //声明有参构造函数
        Length operator + ( Length );     //声明加号运算符函数，只有形参类型
        void display( string );           //声明显示英制长度函数，只有形参类型
    private:            //私有数据
        int iFeet;
        int iInch;
};

Length::Length()  {
    iFeet = 0;
    iInch = 0;
}

Length::Length(int iFt, int iIh) :iFeet(iFt), iInch(iIh) {
    cout << " Calling the default constructor! " << endl;
}

//声明加号运算符函数,返回值类型还为Length型，这里运算符函数为成员函数
Length Length::operator + (Length L)  {

    cout << "\n加号运算符函数operator+()被重载 " << endl;

    Length Temp;

    Temp.iFeet = this->iFeet + L.iFeet;
    Temp.iInch = this->iInch + L.iInch;

    while( Temp.iInch >= 12)        //进制为12
    {
        Temp.iInch -= 12;
        Temp.iFeet++;
    }

    return Temp;

}

//定义显示英制长度函数
void Length::display( string s)  {
    cout << s <<" = " << iFeet << "\'" << iInch << "\'" << endl;
}

//【主函数】
int main()  {
    Length L1(3, 10);      //声明类对象L1，调用有参构造函数
    Length L2(4, 6);       //声明类对象L2，调用有参构造函数

    cout << "\n调用operator+()运算符函数前 " << endl;

    L1.display("L1");
    L2.display("L2");

    Length L3;
    L3 = L1 + L2;          //等价于L1.operator + (L2)

    cout << "\n调用operator+()运算符函数后 " << endl;
    L3.display("L3");      //调用显示英制长度函数

    return 0;
}

/*【心得】
   按该格式：Obj1<运算符>Obj2

<运算符>是指示二元运算符的符号。c++解释为：
    Obj1.operator <运算符>(Obj2);（成员函数重载） 或
    operator<运算符>（Obj1, Obj2）;(全局函数重载)
在这两种情形中，第二个操作数将作为参数，可以将运算符看做编译器内部的函数
*/
