/*==================================================Progrram Descriptionn=====================================================
程序名称：常数据成员示例.cpp
程序目的：练习常数据如何在类中使用 
Written By Dong-Hong-Yan(2012-4-14) 
==============================================================================================================================*/

#include<iostream>
using namespace std;

//【Locating类】 
class Location  {
      public:         //外部接口 
             Location(int k): a(k), r(a)  {             //当初始化const成员时，必须通过--成员初始化列表--进行 
                            b = a;
                            }
             const int &r;                  //定义常引用成员 
             void print()  {
                  cout<<"a = "<<a<<" "<<"r = "<<r<<" "<<"b = "<<b<<" "<<endl;
                  }
      private:         //私有数据 
              const int a;                   //定义常数据成员 
              int b;
      };          //分号必不可少 
      
//【主程序】 
int main()  {
    Location m(10);
    m.print();
    system("pause");
    return 0;
    }
