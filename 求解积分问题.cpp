/*==================================================Progrram Descriptionn=====================================================
程序名称：求解积分问题.cpp
程序目的：用矩形法：求定积分Y=1/x在（a,b）上的积分
Written By Dong-Hong-Yan(2012-4-14)
==============================================================================================================================*/

#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

double g(double x)  {
    return 1 / x;
}
//double(*f)(double)----见下列注释
double rectangle(double a, double b, double(*f)(double))  {
    double w = b - a, sumNew = w * (f(a) + f(b)) / 2, sumOld = 0;
    for(int n = 1; abs(sumNew - sumOld) >= 1e-4; n *= 2)  //这里指数表示不许添加空格，否则不是指数
    {
        sumOld = sumNew;
        sumNew = 0;
        for(int i = 0; i < n; ++i)
        {
            sumNew += f(a + w * (i + 0.5) / n);
            sumNew *= w / n;
        }
    }
    return sumNew;
}

int main()  {
    double a, b;
    cout << "input a: " << endl;
    cin >> a;
    if(a <0 || a ==0)
    cout << "input error!" << endl;
    cout << "input b: " << endl;
    cin >> b;

    if(b < a)
    cout << "input error!" << endl;
    cout << "y= " << rectangle(a, b, g) << "\n";

    return 0;
}
/*【心得】
1、gaiss_ch2()是函数,他有2个参数，第一个是函数指针，第二个是int型整数。
   double (*f)(double) 是个函数指针，f就是一个指针变量，可以指向返回
   double，参数是double 的函数，比如 double fun（double）; f = fun;
   调用gauss_ch2时这样 gauss_ch2( f, 21 )；就行了。*/
