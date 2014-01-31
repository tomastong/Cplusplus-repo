/*===================================Program Description=====================================
程序名称：程序8-8.cpp.
程序目的：虚函数，基类指针，以及派生类指针
Written By Dong-Hong-Yan（2012-6-5）
===========================================================================================*/

#include<iostream>
using namespace std;

//定义基类
class BaseClass  {
    public:
        BaseClass(int i = 0): i(i) {}
        int i;
        virtual void fn1()  { cout<< "This is BaseClass" << endl;}   //定义虚函数
        void fn2() {cout << "The number i is " << i << endl;}
};

//定义派生类
class DerivedClass : public BaseClass {
    public:
        DerivedClass(int j = 10): j(j) {}
        int j;
        void fn1()  { cout<< "This is DerivedClass" << endl;}
        void fn2() {cout << "The number j is " << j << endl;}
};

//主程序
int main () {
    DerivedClass obj;               //定义DerivedClass对象
    BaseClass *Ptr1 = &obj;         //定义BaseClass类型指针
    DerivedClass *Ptr2 = &obj;      //定义DerivedClass类型指针

    Ptr1->fn1();                 //通过指针调用BaseClasds中函数
    Ptr1->fn2();

    Ptr2->fn1();                 //通过指针调用BaseClasds中函数
    Ptr2->fn2();

    return 0;
}

/*[心得]
1。有此题可以知道虚函数是覆盖作用
2。基类指针只可以指向派生类的基类部分*/
