/*====================================================Program Description===============================================
程序名称：常成员函数.cpp
程序目的：通过实例了解常成员函数的用法         
       类外定义-对象-格式如下  <类名> const<对象名> 或const <类名> <对象名>
       类内进行声明格式  类型说明符  函数名（参数表） const 
Written  By Dong-Hong-Yan(2012-4-14)
========================================================================================================================*/

#include<iostream>
using namespace std;

//【R类】 
class R  {
      public:
             R(int r1, int r2) :r1(r1), r2(r2)  {}
             void print();
             void print() const;                //类内进行声明格式  类型说明符  函数名（参数表） const 
      private:
              int r1, r2;
     };    //分号不可少 

void R::print()  {
     cout<<r1<<":"<<r2<<endl;
     } 
     
//类外定义常成员函数 
void R::print() const {
     cout<<r1<<":"<<r2<<endl;
     }
     
//【主程序】     
int main()  {
    R a(4, 5);
    a.print();                 //调用void print() 
    R const b(20, 52);                    //类外定义-对象-格式如下  <类名> const<对象名> 或const <类名> <对象名>
    b.print();               //调用void print() const 
    system("pause");
    return 0; 
    }
