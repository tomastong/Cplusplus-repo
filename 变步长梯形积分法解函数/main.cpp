//main.cpp  文件三，主函数


#include<iostream>
#include"Trapzint.h"      //类定义头文件
#include<iomanip>

using namespace std;

//【主程序】
int main() {
    Myfunction f;        //定义Myfunction类对象
    Trapz trapz(f);      //定义Trapz对象

    //计算并输出积分结果
    cout << "TRAPZ Int : " << setprecision(7) << trapz(0, 2, 1e-7) << endl;

    return 0;
}

//函数setprecision（int）设置浮点数的小数位数（包括小数点）  头文件iomanip
//函数setw（int）设置域宽，右对齐（包括小数点）iomanip
