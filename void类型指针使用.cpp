/*================================Program Description==============================
程序名称：
程序目的：
Written By Dong-Hong-Yan(2012-4-18)
===================================================================================*/

#include<iostream>
using namespace std;

//【主函数】
int main()  {
    //void voidObject;     错，不能声明void类型的变量

    void *pv;            //对，可以声明void类型的指针
    int i = 5;
    pv = &i;             //void类型的指针指向整型变量
                         //void指针一般只在指针所指向的数据类型不确定时用
    int *pint = static_cast< int * >(pv);   //在这里尖括号里是指针的类型

    cout << " *pint = " << *pint << endl;

    return 0;
}
