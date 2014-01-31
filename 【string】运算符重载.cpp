/*==================================Program Description================================
程序名称：【string】运算符重载.cpp
程序目的：基于char * 设计一个字符串类MyString，并且具有构造函数、析构函数、复制构造函数、
          重载运算符"+","=","+=","[]",尽可能完善它，是之满足各种需要！
Written By Dong-Hong-Yan（2012-5-7）
=======================================================================================*/

#include <iostream>
#include <string>
using namespace std;

class my
{
public:
    my(){}
    my(const char * s){str=s;}
    my(const my & s){str=s.str;}
    my(const string & s){str=s;}
    my operator =(const my & s){this->str=s.str;return * this;}
    char operator [](int index) const{return str[index];}
    bool operator ==(const my & s){return s.str==str;}
    bool operator !=(const my & s){return s.str!=str;}
    bool operator <(const my & s){return str<s.str;}
    bool operator >(const my & s){return str>s.str;}
    string operator += (const my & b){return (str = str + b.str );}

private:
    string str;
};

int main()
{
 my a="abc",b;
 b="def";
 cout<< a + b <<endl;
 cout<<a[2]<<endl;
 my c;
 a+=b;
 cout << a << endl;
 return 0;
}

















