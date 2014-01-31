#include<iostream>
using namespace std;

//定义外部函数，bool类型，返回true或false
extern bool fibon_elem (int pos,int &elem)  {

	//如果输入错误格式，则返回false
	if(pos<=0||pos>1024)
	{
		elem=0;
		return false;
	}

	elem=1;
	int n_1=1,n_2=1;
	//数列计算过程
	for(int ix=3;ix<=pos;ix++)
	{
		elem=n_1+n_2;
		n_2=n_1;
		n_1=elem;
	}
	return true;
};

//主程序  
int main()  {

	//定义变量pos用来选择数列元素的位置，elem是该位置数值的大小
	int pos,elem;
	//定义变量ch用来选择是否继续循环进行下去
	char ch;
	//定义bool型变量，作为循环条件
	bool more=true;


	while(more)  {
		cout<<"Please enter a position:";
		cin>>pos;

		if(fibon_elem(pos,elem))
			cout<<"Element # "<<pos<<" is "<<elem<<endl;
		else
			cout<<"Sorry,Could not calculate element # "<<pos<<endl;

		//重新给more赋值，判断循环条件
		cout<<"Would you like to try again?(y/n)";
		cin>>ch;
		if(ch!='y'&&ch!='Y')
			//如果不满足，则产生false
			more=false;
	}
	return 0;
}