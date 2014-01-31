/*===============================================Program Description===============================================
程序名称：线性拟合.cpp 
程序目的：利用Point类进行点的线性拟合 
Written By Dong-Hong-Yan(2012-4-15)
===================================================================================================================*/

#include"Pointa.h"
#include<iostream>
#include<cmath>

using namespace std;

//直线线性拟合，points为各点，npoint为点数
float lineFit(const Point points[], int npoint)  {
      
      float avgX = 0, avgY = 0;
      float lxx = 0, lyy = 0, lxy = 0;
      
      for(int i = 0; i<npoint; i++)  {
              avgX += points[i].getX() / npoint;                   //在这里注意混合运算，“/”的优先级大于“+= ” 
              avgY += points[i].getY() / npoint;
              
              }
              
      //计算lxx，lyy，lxy 
      for(int i = 0; i < npoint; i++)  {
              lxx += (points[i].getX() - avgX) * (points[i].getX() - avgX);               
              lyy += (points[i].getY() - avgY) * (points[i].getY() - avgY);
              lxy += (points[i].getX() - avgX) * (points[i].getY() - avgY);
              }
              
      cout<<"This line can be fitted by y = ax + b."<<endl;
      cout<<"a = "<<lxy/lxx<<" ";                                  //输出回归系数a                       
      cout<<"b = "<<avgY - lxy * avgX / lxx<<endl;                 //输出回归系数b 
      
      return static_cast<float>(lxy / sqrt(lxx * lxy));            //返回相关系数，强制类型转换 
      } 

//【主程序】 
int main()  {                 //初始化数据点 
    Point p[10] = {Point(6, 10), Point(14, 20), Point(26, 30), Point(33, 40), Point(46, 50),
                   Point(54, 60), Point(67, 70), Point(75, 80), Point(84, 90), Point(100, 100)};
    
    float r = lineFit(p, 10);            //进行线性回归计算，用r来接收函数返回值 
    cout<<"Line coefficient r = "<<r<<endl;
    
    system("pause");
    return 0;    
    }
