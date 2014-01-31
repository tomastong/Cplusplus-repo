/*=======================Program Description===============================
程序名称:设置对其方式.cpp
程序目的:通过练习对齐，习惯各种函数
Written By Dong-Hong-Yan(2012-5-27)
===========================================================================*/

#include<iostream>
#include<iomanip>

using namespace std;

int main(void)  {
    double values[] = {2, 12, 326, 5687};
    for( int i=0; i<4; i++ ) {
        cout.fill('#');   //fill成员函数可以为已经指定宽度的域设置填充的值
        cout << setiosflags(ios::left) << setw(6) <<values[i];
        cout.fill('#');
    }
    cout << resetiosflags(ios::left);  //resetiosflags操作符清除标志
    cout << endl;
    for(int j=0; j<4; j++)  {
        cout << setiosflags(ios::right) << setw(6) << values[j];
        cout.fill('#');
    }
    return 0;

}
//设置域宽为6，全部的为6个！
