/*==============================Program Descrription======================================
程序名称：包含虚基类和非虚基类多级继承的构造和析构.cpp
程序目的：
Written By Dong-Hong-Yan(2012-5-19)
========================================================================================*/

#include<iostream>
using namespace std;

class base1  {
    public:
        base1( int i )  {cout << "Base1 constructor called " << i << endl;}
        ~base1()  {cout << "Base1 destructor called " << endl;}
};

class base2  {
    public:
        base2( int i )  {cout << "Base2 constructor called " << i << endl;}
        ~base2()  {cout << "Base2 destructor called " << endl;}
};

class ExtBase1 :virtual public base1, public base2 {
    public:
        ExtBase1( int i, int j ): base1(i), base2(j)  {
            cout << "ExtBase1 constructor called " << i << endl;}
        ~ExtBase1()  {cout << "ExtBase1 destructor called " << endl;}
};

class ExtBase2 : public base2, virtual public base1 {
    public:
        ExtBase2( int i, int j ):base2(j), base1(i)   {
            cout << "ExtBase2 constructor called " << i << endl;}
        ~ExtBase2()  {cout << "ExtBase2 destructor called " << endl;}
};

class Derived : public ExtBase2, public ExtBase1  {
    public:
        Derived( int i, int a, int b, int c ):ExtBase1(i, a), ExtBase2(i, b), base1(c)
         {cout << "Derived constructor called " << i << endl;}
        ~Derived()  {cout << "Derived destructor called " << endl;}
};

int main  {
    Derived objD( 1, 2, 3, 4 );
    return 0;
}
