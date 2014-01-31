/*==========================================Program Description======================================
程序名称:复数类.cpp
程序要求：用复数3+5i初始化c1，用实数4,5初始化c2，将c1和c2相加，结果保存在c1中，将c1输出（这时的结果应
该是7.5+5i）
Written By Dong-Hong-Yan (2012-4-8)
=====================================================================================================*/

#include<iostream>
using namespace std;

class Complex {
      public :
             Complex(float num1 = 0, float num2 = 0): num1(num1), num2(num2) {} 
             Complex (Complex &pp);
             float GetNum1();                              
             float GetNum2();
      private :
              float num1;       //定义复数的整数部 
              float num2;       //定义复数的复数部 
      };                      //切记分号，永远不可忘 
       
 // 定义复制构造函数 
Complex::Complex(Complex &pp) : num1(pp.num1), num2(pp.num2) {
                 cout<<"Calling the copy constructor !"<<endl;
                 }
                 
//定义输入num1函数                 
float Complex::GetNum1()  {
             return num1;
             }    
             
//定义输入num1函数             
float Complex::GetNum2()  {
             return num2;
             }
             
//定义复数相加函数，用Complex定义函数返回类型     
Complex add(Complex p1, Complex p2)  {
             float x = p1.GetNum1() + p2.GetNum1();           //在这里不可用私有成员想加减，不可访问 
             float y = p1.GetNum2() + p2.GetNum2();
             Complex p(x, y);                                  //定义p并初始化赋值 
             return p;                                          //返回p并调用复制构造函数 
             }
          
//【主程序】             
int main()  {
    Complex c1(3, 5);               //定义并初始化 
    Complex c2(4.5, 0);             //定义并初始化
    c1 = add(c1, c2);               //用c1接收并保存相加之后的值 
    cout<<"The answer is : "<<c1.GetNum1();
    cout<<"+"<<c1.GetNum2()<<"i"<<endl;
    system("pause");
    return 0;
    } 
             
             
