/*=======================================================Program Description===================================================
程序名称：简单继承示例.cpp
程序目的：单一继承的构造函数
Written By Dong-hong-Yan(2012-4-15)
===============================================================================================================================*/

#include<iostream>
using namespace std;

//【B类】
class B  {
      public:
             B()   {
                  b = 0;
                  cout<<"B's default constructor called! "<<endl;
                   }
             B(int i) {
                  b = i;
                  cout<<"B's constructor called! "<<endl;
                   }
             ~B()  {
                   cout<<"B's destructor called! "<<endl;
                   }
             void Print()  {
             cout<<b<<endl;
             }
      private:
              int b;
      };      //分号必不可少

//【C类】 ，对B类进行公有继承
class C :public B  {
      public:
             C()  {
                 c = 0;
                 cout<<"C's default constructor called! "<<endl;
                 }
             C(int i, int j);
             ~C()  {
                  cout<<" C's destructor called! "<<endl;
                  }
             void Print();
      private:
              int c;
      };         //分号必不可少

//C的带参数的构造函数
C::C(int i, int j):B(i)  {              //这里传递形参，对B不起作用，只是传递基类形参
    c = j;
    cout<<"C's constructor called! "<<endl;
    }

//定义类C的print函数
void C::Print()  {
     B::Print();
     cout<<c<<endl;
     }

//【主程序】
int main()  {
    C obj(6, 9);
    obj.Print();

    system("pause");
    return 0;
    }

/*【心得】：
================================================================继承方式=========================================================================================
                 基类           基类              Private继承方式                              proteced继承方式                        Public继承方式
                 内部函数       对象       派生类内部函数       派生类对象          派生类内部函数        派生类对象         派生类内部函数          派生类对象

基类public       可访问        可访问           可访问           不可访问               可访问              不可访问             可访问                可访问
成员                                         转化为private                           转化为protected                           保持protected

基类protected    可访问        不可访问         可访问           不可访问               可访问              不可访问             可访问                不可访问
成员                                         转化为private                           转化为protected                           保持protected

基类private      可访问        不可访问        不可访问          不可访问               不可访问            不可访问             不可访问              不可访问
成员

==================================================================================================================================================================*/


