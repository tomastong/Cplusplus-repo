//程序7-11

#include<iostream>
using namespace std;

//定义基类BaseClass
class BaseClass  {
    public:
        BaseClass( int a = 3, int b = 1 )  {  //基类构造函数
            this->a = a;
            this->b = b;
        }
        void fn1()  {cout << "result is :" << a + b << endl;}
        void fn2()  {cout << "result is :" << a - b << endl;}
    protected:
        int a, b;   //基类成员
};

//定义派生类DerivedClass
class DerivedClass : public BaseClass  {
    public:
        DerivedClass( int c = 1 )  {   //派生类构造函数
            this->c = c;
        }
        void fn1()  {cout << "result is :" << a + b + c << endl;}
        void fn2()  {cout << "result is :" << a - b - c << endl;}
    protected:
        int c;      //新增成员
};

//主程序
int main()  {
    DerivedClass obj;      //定义派生类对象
    BaseClass * p1;        //定义基类指针
    p1 = new BaseClass;    //动态申请内存

    DerivedClass * p2;     //定义派生类指针
    p2 = new DerivedClass; //动态申请内存

    obj.fn1();           //派生类对象调用成员函数
    obj.fn2();

    p1->fn1();           //基类指针调用成员函数
    p1->fn2();

    p2->fn1();           //派生类指针调用成员函数
    p2->fn2();

    return 0;
}
//如果基类的构造函数初始化保护成员，则派生类中不用在初始化，如果没有的话，
//给基类传个参就行！
