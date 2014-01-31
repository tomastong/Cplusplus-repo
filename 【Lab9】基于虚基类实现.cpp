/*==================================================Progrram Descriptionn=====================================================
程序名称：基于虚基类.cpp
程序目的：声明一个共同的基类Person,它包含了所有派生类共有的数据，职工类Employee和大学生类Student为虚基类Person的派生类，在职大学生类E_student是职工类Employee的派生类。每类人员具有的数据如下：
            职工类：姓名、性别、年龄、部门
            大学生类：姓名、性别、年龄、专业
            在职大学生类：姓名、性别、年龄、部门、导师
程序要求：1.用继承和虚基类来实现；
2. 请严格按照下面的格式进行输入输出。输入输出格式：
Written By Dong-Hong-Yan(2012-4-14)
==============================================================================================================================*/

#include<iostream>      //包含头文件
#include<string>        //包含头文件

using namespace std;    //使用名字空间std

//声明基类Person
class Person  {
    public:
        string name, sex, age;
        virtual void Input()  {   //声明基类成员函数
            cin >> name >> age >> sex;
        }
        virtual void Output()  {
            cout << "  "<< name <<"  "
                 << sex << "  "
                 << age << "  ";
        }
};

//声明定义派生类Student
class Student  : public Person   {
    public:
        string major;
        void Input()  {
            cout << "请输入一个大学生的信息\n姓名  年龄  性别  专业\n";

            Person::Input();
            cin >> major;
        }
        void Output()  {
            cout << "\n\n*********大学生信息**************\n  姓名  性别  年龄  专业\n";

            Person::Output();
            cout << major <<"\n*********************************\n\n";
        }
};
//声明定义派生类Employee
class Employee : public Person {
    public:
        string section;
        void Input()  {
            cout << "\n请输入一个职工的信息\n姓名  年龄  性别  单位\n";

            Person::Input();
            cin >> section;
        }
        void Output()  {
            cout << "***********职工信息**************\n  姓名  性别  年龄  单位\n";

            Person::Output();
            cout << section <<"\n*********************************\n" << " " <<endl;
        }
};


//声明并定义派生类E_student
class E_student  : public Employee   {
    public:
        string section, tutor;
        void Input()  {
            cout << "\n请输入一个在职大学生的信息\n姓名  年龄  性别  单位  导师\n";

            Person::Input();
            cin >> section >> tutor;
        }
        void Output()  {
            cout << "**********在职大学生信息*********\n  姓名    性别    年龄    单位    导师\n";
            Person::Output();

            cout << section << "  " << tutor;
            cout << "\n*********************************\n\n" << " ";
        }
};

int main()  {
    Person *Ptr1, *Ptr2, *Ptr3;

    Ptr1 = new Student;
    Ptr1->Input();       //调用Student成员函数

    Ptr2 = new Employee;
    Ptr2->Input();      //调用Employee成员函数

    Ptr3 = new E_student;
    Ptr3->Input();      //调用E_student成员函数

    Ptr1->Output();     //调用Student成员函数
    Ptr2->Output();     //调用Employee成员函数
    Ptr3->Output();     //调用Employee成员函数

    delete Ptr1;
    delete Ptr2;
    delete Ptr3;

    return 0;
}

/*【心得】
1、在c++中，基类和派生类存在一种特殊的关系。基类的指针可以指向派生类中的
   基类部分。如：
   Employee * Ptr;
   Ptr = new Worker;
   Ptr = new Manager;
   这样赋值有效的*/
