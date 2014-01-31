#include<iostream>
using namespace std;

#ifndef _HEAD_H       //这两串字符保持一致即可，不需要固定的某些
#define _HEAD_H

class X;            //前向引用声明

class Y  {
	public:
		int g( X &p);     //把int g( X &p);的完整定义如果写上面，那么类X没有完整定义
};                        //所以将函数声明放在上面，定义写在类X的完整定义后



class X  {
	public:
		X( int i ) {
			this->i = i;
		}
		friend class Z;
		friend int h( X &p);
		friend int Y::g( X &p);       //如果想声明一个类中，其成员函数为另一个
    private:                          //类的友元函数时通过该类名::函数名，进行声明
		int i;
};

//调用一个类的成员函数，或友元类的私有成员，必须通过类的对象进行访问

int Y::g( X &p )  { return p.i + 1; }

class Z  {
	public:
		int f( X &p)  { return p.i + 5; }
};

int h( X &p)  {
	return p.i + 10;
}

#endif
