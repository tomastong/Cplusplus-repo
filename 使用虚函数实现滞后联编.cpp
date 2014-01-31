/*==================================================Progrram Descriptionn=====================================================
程序名称：使用虚函数实现滞后联编.cpp
程序目的：为声明函数为虚拟的，它的声明前有一个关键字virtual，函数声明为虚拟的
          因为它的执行依赖上下文（调用它所用的基类指针的内容）
Written By Dong-Hong-Yan(2012-4-14)
==============================================================================================================================*/

#include<iostream>      //包含头文件
#include<string>        //包含头文件

using namespace std;    //使用名字空间std

//声明基类Employee
class Employee  {
    public:
        virtual void Cal_salary()  {   //声明基类成员函数
            cout << "调用基类Employee成员函数 " << endl;
        }
};

//声明子类Worker
class Worker : public Employee {
    public:
        void Cal_salary()  {
            cout << "调用子类Worker成员函数 " << endl;
        }
};

//声明子类Manager
class Manager  : public Employee   {
    public:
        void Cal_salary()  {
            cout << "调用子类Manager成员函数 " << endl;
        }
};

int main()  {
    Employee * Ptr;
    Ptr = new Employee;
    Ptr->Cal_salary();       //调用Employee成员函数
    delete Ptr;

    Ptr = new Worker;
    Ptr->Cal_salary();      //本想调用Worker成员函数
    delete Ptr;

    Ptr = new Manager;
    Ptr->Cal_salary();      //本想调用Manager成员函数

    delete Ptr;

    return 0;
}

/*【心得】
1、在c++中，基类和派生类存在一种特殊的关系。基类的指针可以指向派生类的
   任何一个对象。如：
   Employee * Ptr;
   Ptr = new Worker;
   Ptr = new Manager;
   这样赋值有效的*/
