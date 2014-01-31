/*==============================Program  Description===============================
程序名称：类的组合（线段类-Line）.cpp
程序目的：使用一个类来描述线段，Point类来表示端点
程序要求：使Line类中包括Point类的两个对象p1和p2，作为其数据成员，Line类具有计算线段
         长度的功能
Written By Dong-Hong Yan(2012-4-4)
===================================================================================*/
//头文件 
#include<iostream>
#include<cmath>

using namespace std;

//定义Point类 
class Point  {
      public:     //外部接口 
             Point(int xx=0,int yy=0) {
                       x=xx;
                       y=yy;
                       cout<<"Calling the constructor Point"<<endl;   
                       }
             Point(Point &p);
             int getX() {return x;}             //返回x坐标 
             int getY() {return y;}             //返回y坐标 
      private:    //私有成员 
              int x,y;
      } ;               //注意在类的定义结束后，都有一个分号 

//Point类的复制构造函数 
Point::Point(Point &p)  {
      x=p.x;
      y=p.y;  
      cout<<"Calling the copy constructor Point"<<endl;           
      } 
      
//类的组合
class Line  {
      public:
             Line(Point xp1,Point xp2);
             Line (Line &l);                   //  变量名必须以"字母"打头，名字中间只能由字母、数字和下划线“_”组成；
             double getLen() {return len;}      //最后一个字符可以是类型说明符；
      private:
              Point p1,p2;
              double len;
      } ;

//组合类的构造函数 ---一般形式： 类名::类名(形参表):内嵌对象1(形参表),内嵌对象2(形参表),... 
Line::Line(Point xp1,Point xp2):p1(xp1),p2(xp2) {      //这里p1(xp1)相当于p1=xp1; 
                 cout<<"Calling constructor of Line"<<endl;
                 double x=static_cast<double>(p1.getX()-p2.getX());    //这里static_cast<类型>(表达式);强制类型转换 
                 double y=static_cast<double>(p1.getY()-p2.getY());
                 len=sqrt(x*x+y*y);
                  }      

//组合类的复制构造函数--（假设C类中包含B类中的对象b作为成员，那么C类的复制构造函数形式如下）：注意在C类外定义C::C(C &c1):b(c1.b)  {...} 
//在这里，说明一点，按照格式， p1(l.p1),p2(l.p2) 可以写在函数体内，即p1=l.p1 
Line::Line(Line &l):p1(l.p1),p2(l.p2)  {
                cout<<"Calling the copy constructor of Line"<<endl;
                len=l.len;
                } 
 
 //【主程序】 
 int main()  {
     Point myp1(1,1),myp2(4,5);                       //建立Point类的对象 
     Line line(myp1,myp2);                            //建立Line类的对象 
     Line line2(line);                               //利用复制构造函数建立一个新对象，相当于Line line2=line;复制，但是2成员复制1次，共两次 
     cout<<"The length of the line is :";
     cout<<line.getLen()<<endl;
     cout<<"The length of the line2 is :";
     cout<<line2.getLen()<<endl;
     system("pause");                                //使系统结束时，暂停一下 
     return 0;
     } 
