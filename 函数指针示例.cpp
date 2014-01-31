/*=============================Program Description===================================
程序名称：函数指针示例.cpp
程序目的：熟练掌握函数指针
Written By Dong-Hong—Yan(2012-4-19)
=====================================================================================*/

#include<iostream>
using namespace std;

void printStuff(float)  {
    cout << "This is the print stuff function!" << endl;
}

void printMessage(float data)  {
    cout << "The data to be listed is " << data <<endl;
}

void printFloat(float data)  {
    cout << "The data to be listed is " << data <<endl;
}

//一般情况下，除了整数，其余的全是double（双精度）的，为了表示单精度，故在数据后加f
//使其在运算过程中，保持单精度
const float PI = 3.14159f;
const float TWO_PI = PI * 2.0f;

//【主程序】
int main()  {
    void (* functionPointer)(float);     //定义函数指针
    printStuff(PI);
    functionPointer = printStuff;        //函数指针指向printstuff，不用带参数
    functionPointer(PI);                 //函数指针调用
    functionPointer = printMessage;
    functionPointer(TWO_PI);
    functionPointer(13.0);
    functionPointer = printFloat;
    functionPointer(PI);
    printFloat(PI);

    return 0;
}
