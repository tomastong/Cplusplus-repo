/*=================================Program Description===========================
程序名称;指针做函数参数.cpp
程序目的；读入3个浮点数，将整数和小数部分分别输出
程序要求：如果直接使用整型和浮点型变量，则形参在子函数中的变化根本无法返回到主函数
          ，因此采用指针作函数参数。
Written By Dong-Hong-yan(2012-4-19)
=================================================================================*/

#include<iostream>
using namespace std;

//将实数x分成整数和小数部分，形参intPart和fracPart是指针
void splitFloat(float x, int * intPart, float * fracPart)  {
    * intPart = static_cast<int>(x);  //取x的整数部分
    * fracPart = x - * intPart;       //取x的小数部分
}

int main()    {
    cout << "Enter 3 float point numbers: " << endl;
    for(int i = 0; i < 3; i++)  {
        float x, f;
        int n;
        cin >> x;
        splitFloat(x, &n, &f);     //变量地址作为函数实参
        //这里是指针接收 1、变量地址 2、数组名
        cout << "Intgeter Part = " << n << " Fraction Part = " << f << endl;
        }
        return 0;
}
