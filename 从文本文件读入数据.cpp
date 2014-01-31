/*================================Program Description===================================
程序名称：从文本文件读入数据.cpp
程序目的：练习从文本文件读入数据
Writeen By Dong-Hong-Yan(2012-5-16)
========================================================================================*/

#include<iostream>
#include<fstream>         //使用文件包含   文件的输入和输出流类
using namespace std;

//【主程序】
int main( void )   {
    fstream infile;        //创建一个文件输入输出流对象
    infile.open("E:/test.txt", ios::in );     //文件位置和打开方式（是“读打开”）
    if( !infile )  {
        cout << "Error occured while opening test.txt" << endl;
        return 0;
    }
    char textline[80];
    while( !infile.eof() )  {        //当文件结束时，默认值是-1
        infile.getline( textline, sizeof( textline ) );  //将文件内容（前80个）读入数组
        cout << textline <<endl;                         //在输出数组显示
    }
    infile.close();       //文件的关闭
    return 0;
}
