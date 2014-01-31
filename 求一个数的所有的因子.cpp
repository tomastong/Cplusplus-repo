/*--------------Program  Description-----------
程序名称：求一个数的所有因子.cpp
程序目的：求一个数的所有因子 
Written By Dong-Hong yan（WANT Studio）
=================================================*/

#include<iostream>
//在c++中一般不用<stdlib.h>而在文件前加c
#include<cstdlib>
//前两个都是c++的关键词，std是，如（string class,
//以及cout,cin这两个iostream类对象）都被封装在命名空间std里
using namespace std;

int main()
{
	int n;

	cout<<"Enter a positive integer:";
	cin>>n;
	//如果需要在屏幕上显示的家双引号，

	cout<<"Number  "<<n<<" factors";
	for(int k=1;k<=n;k++)
		if(n%k==0)
			cout<<k<<" ";
	cout<<endl;
   
		return 0;
	    
}
