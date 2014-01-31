/*--------------Program  Description-----------
程序名称：Hannt.cpp
程序目的：将a针盘移动c针盘，借助b针，每次一个，保持大在下小在上
Written By Dong-Hong yan（WANT Studio）
=================================================*/

#include<iostream>
//定义变量空间，如果没有定义std，可以再函数前加std，如std::cout即可，或者在头文件加一个".h"
using namespace std;

//把src针的最上面一个盘子移动到dest针上
//定义函数，输出步骤
void move(char src,char dest)
{
	cout<<src<<"-->"<<dest<<endl;
}

//把n个盘子从src（A）针移动到dest（c）针，以medium（b）针作为中间媒介,三个位置记住，功能却不变 
void hanoi(int n,char src,char medium,char dest)
{
	if(n==1)
		move(src,dest);
	else
	{
        //把n-1个盘子从src（A）针移动到medium（b）针，以dest（c）针作为中间媒介,三个位置记住，功能却不变 
		hanoi(n-1,src,dest,medium);
		move(src,dest);
		//把n个盘子从medium（b）针移动到dest（c）针，以src（A）针作为中间媒介,三个位置记住，功能却不变 
		hanoi(n-1,medium,src,dest);
	}
}


//主函数
int main()
{
	int m;//所有的盘子总数
	cout<<"Enter the number of diskes:";
	cin>>m;
	cout<<"the steps to moving "<<m<<" diskes:"<<endl;
	hanoi(m,'A','B','C');
	return 0;
}
