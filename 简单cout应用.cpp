#include<iostream>
//#include<string>
using namespace std;

int main()
{
	string user_name;
	cout<<"Please enter your first name:";
	cin>>user_name;


	//在这里'\n'没有用双引号括起来，表明其是发挥作用的，换行，当然也可以endl;
	cout<<'\n'<<"Hello,"<<user_name<<"...and goodbye!\n";

	return 0;
}