/*==============================Program Description========================
程序名称：静态多态性和动态多态性.cpp
程序目的：接收职员和学员的材料，并显示。职员和学员
          具有相同的属性是：
            姓名、年龄、生日和电话：
          不同的属性是：
            职员有工资，学员有考试分数！
Written By Dong-Hong-Yan(2012-5-12)
===========================================================================*/

#include<iostream>
#include<string>

using namespace std;

//定义基类Person
class Person  {
    public:
        virtual void Accept()  {
            cout << "请输入姓名：";   cin >> cName;
            cout << "请输入年龄：";   cin >> iAge;
            cout << "请输入生日：";   cin >> cBirth;
            cout << "请输入电话：";   cin >> cPhone;
        }
        virtual void Display()  {
            cout << "输入的姓名是：" << cName << endl;
            cout << "输入的年龄是：" << iAge << endl;
            cout << "输入的生日是：" << cBirth << endl;
            cout << "输入的电话是：" << cPhone << endl;
        }
    protected:
        char cName[20];
        int iAge;
        char cBirth[12];
        char cPhone[15];
};

//定义子类Employee
class Employee : public  Person  {
    public:
        void Accept()  {            //声明子类成员函数
            cout << "\n----请输入职员的个人信息----"  << endl;
            Person::Accept();
            cout << "请输入工资： ";
            cin >> Salary;
        }
        void Display()  {           //声明子类成员函数
            cout << "\n----显示职员的个人信息----" << endl;
            Person::Display();
            cout << "输入的工资是： " << Salary << endl;
        }
    private:
        float Salary;
};

//定义子类Student
class Student : public Person {
    public:
        void Accept()  {          //声明子类成员函数
            cout << "\n----请输入职员的个人信息----"  << endl;
            Person::Accept();
            cout << "请输入分数： ";
            cin >> Score;
        }
        void Display()  {         //声明子类成员函数
            cout << "\n----显示职员的个人信息----" << endl;
            Person::Display();
            cout .<< "输入的分数是：" << Score << endl;
        }
    private:
        float Score;
};

int main()  {
    Person * Ptr;
    Ptr = new Employee;
    Ptr->Accept();
    Ptr->Display();
    delete Ptr;

    Ptr = new Student;
    Ptr->Accept();
    Ptr->Display();
    delete Ptr;

    return 0;
}
/*【心得】
1、静态多态性：指函数具有相同的函数名、不同的函数参数列表；
2、而动态多态性：指具有相同的函数名、相同的函数参数列表，
   仅仅是函数体代码不同
3、Person类的两个函数都为虚函数，当虚函数被继承时，也继承它的虚拟性质。
   Employee和Student类的两个函数是虚拟的！*/
