/*===================================Program Description=====================================
程序名称：程序8-9.cpp.
程序目的：虚析构函数，基类指针，
Written By Dong-Hong-Yan（2012-6-5）
===========================================================================================*/

#include<iostream>
using namespace std;

//定义基类
class BaseClass  {
    public:
        BaseClass(int i = 0): i(i) {}
        virtual ~BaseClass()  {cout << "BaseClass destructor!" << endl;}      //
        int i;
        void fn() {cout << "The number i is " << i << endl;}
};

//定义派生类
class DerivedClass : public BaseClass {
    public:
        DerivedClass(int j = 10): j(j) {}
        ~DerivedClass() { cout << "DerivedClass destructor!" << endl;}
        int j;
        void fn() {cout << "The number j is " << j << endl;}
};

//[主函数]
int main()  {
    BaseClass * Ptr = new DerivedClass(2);      //在这里动态申请内存还调用构造函数（这里用的是有参数）
    Ptr->fn();
    delete Ptr;    //在那里申请，就在那里消灭
    return 0;
}
//调用虚析构函数删除内存时，先调用派生类，后调用基类的
//2、【重要】调用纯虚析构函数=0，还要给出完整定义，哪怕函数体是空
