/*-------------Program Description------------
程序名称：rec_Permut.cpp
程序目的：用递归方法求排列组合，用公式
Cn m=Cn-1 m+Cn-1 m-1
Written By Dong-Hong Yan(WANT Studio)
----------------------------------------------*/


#include<iostream>
using namespace std;

//计算从n个人里选k个人的组合数，递归调用
int comm(int n,int k)  {
	if(k>n)
		return 0;
	else if(n==k||k==0)
		return 1;
	else
		return comm(n-1,k)+comm(n-1,k-1);

}

int main() {
	int n,k;
	cout<<"Please enter two integers n and k:";
	cin>>n>>k;
	cout<<"C(n,k)="<<comm(n,k)<<endl;
	return 0;
}

