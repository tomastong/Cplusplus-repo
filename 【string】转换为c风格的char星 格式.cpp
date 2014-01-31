/*==================================Program Description================================
程序名称：转换为c风格的char *格式.cpp
程序目的：使string类的成员函数转换为c风格的char * 形式
Written By Dong-Hong-Yan(2012-5-19)
=======================================================================================*/

#include<iostream>
#include<string>

using namespace std;

int main()  {
    string str( "STRINGS" );
    const char * ptr1 = 0;
    int length = str.length();
    char * ptr2 = new char[ length + 1 ];  //动态分配一个字符数组，包括null结束符
    str.copy( ptr2, length, 0 );         //将str中所有字符复制到分配内存中
    ptr2[ length ] = '\0';                  //添加null终止符
    cout << "string s is " << str << "\nstr converted to a C-Style string is "
         << str.c_str() << "\nptr1 is ";
    ptr1 = str.data();                     //使用成员函数data
    for( int i = 0; i < length; i++ )
        cout << * (ptr1 + i );
    cout << "\nptr2 is " << ptr2 << endl;       // 使用指针输出
    delete [] ptr2;
    return 0;
}
