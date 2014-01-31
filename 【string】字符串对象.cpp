/*==============================Program Description==================================
程序名称：string字符串对象.cpp
程序目的：通过例子对string类不同的方法进行简单了解
Written by Dong-Hong-Yan(2012-4-28)
=====================================================================================*/

#include<iostream>     //包含头文件
#include<string>       //包含头文件
using namespace std;

//【主程序】
int main()  {
    string str1;           //构造函数string(), str1 = ?
    string str2("efg");    //构造函数string( char *ch ), str2 =efg
    string str3(str2);     //构造函数string( string str ), str1 = str2

    str1 = 'a';                 //将一个字符赋给string对象，str1=a
    str2 = "bcde";              //将一个字符数组赋给string对象，str2=efg
    str3 = str2;                //将一个string对象赋给另一个string对象，str3=bcde
    str3 = str1 + str2;         //串的连接 str3=abcdef
    str3 += '!';                //串的连接 str3=abcdef！
    char ch1 = str3[1];         //字符串下标，ch1=b
    char ch2 = str3.at(1);      //字符串下标，ch2=b
    str3[2] = 'x';              //串的连接，str3=abxdef
    str3.at(2) = 'y';           //串的连接，str3=abydef
    string str4;
    str4 = str3.substr(1, 3);   //substr(1, 3)，返回子串str4=byd
    int isize = str3.size();    //size()返回串元素个数isize=7
    int ileng = str4.size();    //length()返回串元素个数ileng=7
    cout << "isize = " << isize << endl;
    cout << "ileng = " << ileng << endl;
    cout << "str3 = " << str3 << endl;
    cout << "str4 = " << str4 << endl;
    return 0;
}

/*【心得】
1、函数substr( int, int )可以从一个字符串中提取并返回子串，第一个参数为在原始
   字符串的起始位置(计数从0开始)，第二个参数是子串的字符个数
2、可以用字符串的下标运算符[]或成员函数at( int )，来检测字符串的某个字符或修改
   字符串的某个字符
3、字符串的比较，string串对象支持所有的关系运算符，可以把两个字符串对象或
   字符串对象和以空字符结尾的字符数组进行比较！
   if( str1==str2 )   if( str1 < "abcd")*/
