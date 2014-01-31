/*==============================Program Description==================================
程序名称：大于运算符重载.cpp
程序目的：经常比较两个对象的大小，这是直接用到大于运算符重载
Written by Dong-Hong-Yan(2012-4-28)
=====================================================================================*/

#include<iostream>
#include<string>
using namespace std;

class Length  {
    public:

        Length( int, int );
        bool operator > ( Length );

    private:

        int iFeet;
        int iInch;
};   //分号必不可少的

//定义有参构造函数
Length::Length( int iFeet, int iInch )  {

    this->iFeet = iFeet;
    this->iInch = iInch;
}

//在这里定义函数类型为int或者为布尔型都可以
bool Length::operator > ( Length N )  {

    cout << "\n比较运算符函数operator > ()被重载 " << endl;

    if( iFeet > N.iFeet )

        return true;

    else if( iFeet < N.iFeet )

        return false;

        else if( iInch > N.iInch )

            return true;

            else

                return false;
}

//【主函数】
int main()  {
    Length L1(3, 10);
    Length L2(4, 6);
    if(L1 > L2)
        cout << "对象L1 > 对象L2" << endl;
    else
        cout << "对象L1 < 对象L2" << endl;

    return 0;
}
