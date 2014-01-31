/*==========================================================Program Description====================================================
程序名称：常引用做形参.cpp 
程序目的：通过示例对const进行深度理解
Written By Dong-Hong-Yan(2012-4-15)
===================================================================================================================================*/

#include<iostream>
#include<cmath>
using namespace std;

class Point  {
      public:
             Point(int x = 0, int y = 0) :x(x), y(y)  {}
             Point(const Point &p);  
             int getX()  {return x;}
             int getY()  {return y;}
             
             friend float dist(const Point &p1, const Point &p2);
      private:
              int x, y;
      };    //分号i必不可少
 
//定义复制构造函数的参数       一般都用常引用传递     
Point::Point(const Point &p) :x(p.x), y(p.y)  {
                   cout<<"Calling the copy constructor!"<<endl;
                   }   
                   
//友元函数定义     在这里用常引用做形参                     
float dist(const Point &p1, const Point &p2) {
      
      double x = p1.x - p2.x;
      double y = p1.y - p2.y;
      
      return static_cast<float>(sqrt(x * x + y * y));                //强制类型转换 
      } 

//【主程序】  
int main()  {
    const Point myp1(1, 1), myp2(4, 5);                   //定义Point类对象 
    
    cout<<"The distance is : ";
    cout<<dist(myp1, myp2)<<endl;                         //计算两点间距离 
    
    system("pause");
    return 0;
    }
