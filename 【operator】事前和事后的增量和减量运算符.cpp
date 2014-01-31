
/*==============================Program Description==================================
程序名称：事前和事后的增量和减量运算符.cpp
程序目的：对于运算符重载前缀的应用，编译器调用无参的运算函数，对于运算符重载的后缀
          应用，编译器调用的是带int参数的运算符函数
Written by Dong-Hong-Yan(2012-4-28)
=====================================================================================*/

#include<iostream>
#include<string>         //包含头文件
using namespace std;

//声明一个类MyNum
class MyNum   {
    public:
        MyNum();
        MyNum( int iNumber );
        MyNum operator++();
        MyNum operator++( int );
        void display( string );
    private:                           //私有数据
        int iNumber;
};

MyNum::MyNum() :iNumber( 0 ) {}

MyNum::MyNum( int iNumber )  {
    this->iNumber = iNumber;
}

//定义前缀增量运算符函数
MyNum MyNum::operator++()  {
    MyNum Temp;
    iNumber += 1;
    Temp.iNumber = iNumber;
    return Temp;
}

//定义后缀增量运算符函数
MyNum MyNum::operator++( int )  {
    MyNum Temp;
    Temp.iNumber = iNumber;
    iNumber += 1;
    return Temp;
}

void MyNum::display( string s )  {
    cout << s <<" = " << iNumber << endl;
}

//【主函数】
int main()  {
    MyNum MyN1(100);
    MyNum MyN2;

    MyN2 = ++MyN1;                      //等价于MyN1.operator++()

    cout << "\n调用operator++()取负成员函数后 " << endl;

    MyN1.display("MyN1");               //调用显示成员变量函数
    MyN2.display("MyN2");               //调用显示成员变量函数

    MyN2 = MyN1++;                      //等价于MyN1.operator++(0)

    cout << "\n调用operator++(int)取负成员函数后 " << endl;

    MyN1.display("MyN1");
    MyN2.display("MyN2");
    return 0;

}
