/*=========================Program Description==============================
程序名称：typeid获取运行类型信息.cpp
程序目的：介绍typeid的用法，可作用与表达式和类型说明符
Written By Dong-Hong-Yan(2012-5-27)
============================================================================*/

#include<iostream>
#include<typeinfo>     //包含头文件

using namespace std;

class Base {
    public:
        virtual ~Base()  {}
};

class Derived : public Base {};

void fun( Base * b ) {

    //得到表示b和*b类型信息的对象
    const type_info &info1 = typeid( b );
    const type_info &info2 = typeid( *b );

    cout << "typeid( b ):" << info1.name() << endl;
    cout << "typeid( *b ):" << info2.name() << endl;

    if( info2 == typeid(Base) )
        cout << "A Base class!" << endl;
}

int main()  {
    Base b;
    fun(&b);
    Derived d;
    fun(&d);

    return 0;
}
/*1、该例中，由于* b的类型是Base，而Base是多态类型，所以用typeid（*b）得到的
是b指针所指向对象的具体类型，因而两次调用得到不同结果！
2、虽然b是指向多态类型的指针，但指针本身不是多态类型，所以两次调用结果一样
3、通过typeid得到的是type_info类型的常引用，而type_info类中有一个名为name的
常引用！*/











