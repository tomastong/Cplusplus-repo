/*==============================Program Description==================================
程序名称：简单的一元运算符重载.cpp
程序目的：下面程序中，类对象通过实用点运算符，调用Negative()函数，达到使类对象成员变量
          取负的目的！
Written by Dong-Hong-Yan(2012-4-28)
=====================================================================================*/

#include<iostream>
using namespace std;             //使用名字空间std

//声明一个类Person
class Person  {
    friend void operator-(Person);  //声明负号运算符函数为友元函数,参数只写”类型“
    public:               //外部接口
        Person(int iApple);
        void Negative();
        void display();

    private:              //私有成员数据
        int iApple;
};

Person::Person(int iApple)  {
    this->iApple = iApple;
}

//定义成员变量取负数函数
void Person::Negative()  {
    iApple = -iApple;
}

void Person::display()  {
    cout << " iApple =  " << iApple << endl;
}

//定义符号运算符函数
void operator-(Person p1)  {
    p1.iApple = -p1.iApple;
}

//【主程序】
int main()  {
    Person XiaoWang(5);     //声明对象XiaoWang,自动调用构造函数

    cout << "\n调用Negative()取负成员函数前" << endl;
    XiaoWang.display();

    XiaoWang.Negative();

    cout << "\n调用Negative()取负成员函数后" << endl;
    XiaoWang.display();

    operator-(XiaoWang);        //等价于-XiaoWang

    cout << "\n调用operator()负号运算符函数后" << endl;
    XiaoWang.display();

    return 0;
}

