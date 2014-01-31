/*===================================Program Description================================
程序名称：查找给定字符或字符串.cpp
程序目的：锻炼其它“查找函数”。
Written By Dong-Hong-Yan(2012-5-19)
========================================================================================*/

#include<iostream>
#include<cstring>
using namespace std;

//【主程序】
int main()  {
    char str[] = "The Mississippi is a long river.";
    cout << "str = \" " << str << " \" \n";
    char * p = strchr( str, ' ' );
    cout << "strchr( str, ' ' ) points to str[" << p-str << "].\n";
    p = strchr( str, 's' );
    cout << "strchr( str, 's' ) points to str[" << p-str << "].\n";
    p = strrchr( str, 's' );
    cout << "strrchr( str, 's' ) points to str[" << p-str << "].\n";
    p = strstr( str, "is" );
    cout << "strctr( str, \"is\" ) points to str[" << p-str << "].\n";
    p = strstr( str, "isi" );
    if( p == NULL )
    cout << "strctr( str, \"isi\" ) returns NULL\n";

    return 0;
}
/*【心得】
1、char * strchr( const char * string, int c );
   在字符串string中，查找字符c出现的第一个位置，如果没有找到c，则返回NULL。
2、char * strrchr( const char * string, int c );
   在字符串string中，查找字符c出现的最后一个位置。
3、char * strshr( const char * string, const char * strCharSet );
   在字符串string中，查找字符串strCharSet第一次出现位置。*/
