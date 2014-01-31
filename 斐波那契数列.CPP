/*=========Program Description=========
程序名称：quote_pass.cpp
程序目的：练习引用传递-费波纳契数列
Written By Dong-Hong Yan
=======================================*/

#include<iostream>
using namespace std;

//引用传递
void faconi(int n, int &elem)  {
	int f1=1;
	int f2=1;
	if(n==1||n==2)
		elem=1;
	else
		//少执行两次循环
		n-=2;
		while( n--) {
		elem=f1+f2;
		f2=f1;
		f1=elem;
	}
}

//主程序
int main()  {
	int index;
	int elem;
	cout<<"Please ente the index (>=3) :";
	cin>>index;
	faconi(index,elem);
	cout<<"The munber "<<index<<" is :"<<elem<<endl;
	return 0;
}