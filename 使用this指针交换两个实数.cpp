/*=========================Program Description=============================
程序名称：使用this指针交换两个实数.cpp
程序目的：使用this指针交换两个实数
Written By Dong-Hong-Yan(2012-5-12)
===========================================================================*/

#include<iostream>
using namespace std;

class ThisSwap  {
    public:
        ThisSwap();
        void read();
        void swap();
    private:
        float * a, * b;
};
//构造函数（含有私有成员的指针的初始化），就是这样
ThisSwap::ThisSwap()  {
    a = new float;
    b = new float;
    * this->a = 0;
    * this->b = 0;
}

void ThisSwap::read()  {
    cout << "Enter two real data: ";
    cin >> *a >> *b;
}

void ThisSwap::swap()  {
    float temp;
    cout << endl << "Before swap : a = " << * a << " b = " << * b << endl;
    temp = * b;
    * b = * a;
    * a = temp;
    cout << "After swap : a = " << * a << " b = " << * b << endl << endl;
}

//【主程序】
int main()  {
    ThisSwap * p;        //定义一个类指针
    p = new ThisSwap();   //动态申请类对象

    p->read();           //通过指针调用类成员函数
    p->swap();

    delete p;              //删除动态创建对象的内存

    return 0;
}
