/*==========================Program Description============================
程序名称：便捷的字符串输出，处理字符串操作符“#”.cpp
程序目的：了解字符串操作符#的使用格式 ：       #s    #宏形参
Written By Dong-Hong-Yan(2012-5-27)
===========================================================================*/

#include<iostream>
using namespace std;

#define sout(s)  cout << #s << endl;
#define dout(s, v)  cout << #s << v << endl;

int main()  {
    sout( this is a string );
    sout( that is a word );
    sout("zrf" is a string );
    dout(cout << #s << endl;,"cout << #s << endl");
    sout(a=10000);

    return 0;
}
/*【心得】
1、字符串操作符组合#s仅用于#define引入的宏定义中，旨在将相应的宏实参
   转换为字符串常数。
2、字符串操作符将带参的宏定义的实参文本串置于双引号之内，实参左右最
   外两边的空白被忽略。
3、这种将实参文本串置于双引号之内的预处理功能，方便程序输入输出处理！*/
