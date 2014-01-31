/*=====================================================Program Description================================================
程序名称：Point头文件.h
程序目的：通过该例子加深对c++组织结构理解
Written By Dong-Hong-Yan(2012-4-15)
==========================================================================================================================*/
#ifndef -POINT_H      //在这里不一定要和标题一样，只要保持 #ifndef和#define一样即可
#define -POINT_H


class Point  {
      public:
             Point(int x = 0, int y = 0) :x(x), y(y)  {}
             Point(const Point &p);                      //复制构造函数的参数用常引用传递
             ~Point()  {count--;}

             int getX() const  {return x;}
             int getY() const  {return y;}

             static void showCount();                      //静态函数成员 不属于任何类对象，所有类对象共享，没有对象之前就已经存在
      private:
              int x, y;

              static int count;                   //静态数据成员，没有赋值，系统默认为0
      };                     //分号必不可少

#endif
