/*========Program Description========
程序名称：type_rectanarea.cpp
程序目的：运用类求矩形面积
Written By Dong-Hong Yan
=====================================*/

#include<iostream>
using namespace std;

class Rectan  {
public:
	Rectan(double nlength=1.0,double nwidth=1.0) {
	length=nlength;
	width=nwidth
	}
	void input()  {
		cin>>length>>width;
	}
	double area( double length,double width) {
		return length*width;
	} 
	void output()  {
		cout<<"The result of tectangle is "<<area(length,width)<<endl;
	}
private:
	double length,width;

};

int main()  {

	int length,width;
	Rectan newarea();
	cout<<"Please enter the length,width of rectangle:";
	newarea.input();
	newarea.area(length,width);
	newarea.output();
	return 0;

}