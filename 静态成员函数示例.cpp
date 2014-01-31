/*==================================================Program Description========================================
程序名称：静态成员函数示例.cpp
程序目的：通过实例加深对静态的理解      调用静态成员函数格式  <类名>::<静态成员函数名>(<参数表>)
                                        或对象.静态成员函数(<参数表>)  
Written By Dong-Hong-Yan(2012-4-14)
===============================================================================================================*/

#include<iostream>
using namespace std;

//【Myclass类】 
class Myclass  {
      public:
             Myclass():a(0)  {}           //由于静态数据成员b,为所有对象共享，是静态生存期，
             Myclass(Myclass &p);         //需初始化，但不能再构造函数中初始化，在类外进行 
             void func();
             static int sfunc1();
             static void sfunc2(Myclass &r);
      private:
              int a;
              static int b;
      } ;                  //分号必不可少
      
//复制构造函数定义 
Myclass::Myclass(Myclass &p):a(p.a)  {
                         cout<<"Calling the copy constructor!"<<endl;
                         }
                         
//静态数据成员初始化，如果没有初始化，系统默认为0  
int Myclass::b = 5;
 
void Myclass::func()  {
     b = 10;
     }      
     
int Myclass::sfunc1()  {
    return b;
    }     
    
void Myclass::sfunc2(Myclass &r)  {
     //a = 10;           //错误，静态成员函数不能直接访问非静态成员 
     r.a = 10;           //对，通过类对象或指向对象的指针访问 非静态成员 
     b = 20;
     }
     
//【主程序】 
int main()  {
    cout<<Myclass::sfunc1()<<endl;
    Myclass r;
    cout<<r.sfunc1()<<endl; 
    system("pause"); 
    return 0;
    } 
    
/*【心得】 静态成员的说明：
  1.定义在类的静态成员函数为内联函数。当然也可以在类外定义，这时不用static前缀
  2.静态成员函数一般访问的是静态数据成员，特殊情况也可以访问非静态成员，如通过类对象或指向对象的指针访问 非静态成员 
  3.静态成员函数和一般成员函数区别：
    a.可以不指向某个具体的对象，只与类名连用
    b.在没有建立类对象之前，静态成员就已经存在
    c.没有this指针。如果要在函数中范文某个特定存在对象的成员，必须结合使用操作符"."或"->"来显式的制定所属对象
    d.静态成员们为该类的所有对象共享，他们存在一个公共的内存中，不属于任何函数（静态数据）和类的对象（静态函数），是他们所共享的*/
