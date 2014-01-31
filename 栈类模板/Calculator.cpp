//Calculator.cpp

#include"Calculator.h"
#include<iostream>
#include<sstream>
#include<cmath>

using namespace std;

void Calculator::enter( double num )  {  //将操作数压入栈
    s.push( num );
}

//连续将两个操作数弹出栈，放在opnd1和opnd2中
//如果栈中没有两个操作数，则返回false并输出相关信息
bool Calculator::getTwoOperands( double &opnd1, double &opnd2 )  {
    if( s.isEmpty() ) {                      //检查栈是否为空
        cerr << "Missing operand! " << endl;
        return false;
    }
    opnd1 = s.pop();                 //将右操作数弹出栈
    if( s.isEmpty() )  {
        cerr << "Missing operand! " << endl;
        return false;
    }
    opnd2 = s.pop();                 //将左操作数弹出栈
    return true;
}

//执行运算
void Calculator::compute( char op )  {
    double operand1, operand2;
    bool result = getTwoOperands( operand1, operand2 );   //将两个操作数弹出栈

    if( result )  {               //如果成功，执行运算，并将运算结果压入栈
        switch(op)  {
        case '+':
            s.push( operand2 + operand1 );
            break;
        case '-':
            s.push( operand2 - operand1 );
            break;
        case '*':
            s.push( operand2 * operand1 );
            break;
        case '/':
            if( operand1 == 0 ) {        //检查除数是否为0
                cerr << "Divided by 0!" << endl;
                s.clear();               //除数为0时，清空栈
            }
            else
            s.push( operand2 / operand1 );
            break;
        case '^':
            s.push( pow( operand2, operand1 ) );
            break;
        default:
            cerr << "Unrecongnized operator! " << endl;
        }
        cout << "=" << s.peek() << " ";       //输出本次运算结果
    }
    else
            s.clear();          //操作数不够，清空栈
}

//工具函数，用于将字符串转换为实数
inline double stringToDouble( const string &str )  {
    istringstream stream( str );      //字符串输入流
    double result;
    stream >> result;
    return result;
}

//读入并处理后缀表达式
void Calculator::run()  {
    string str;
    while( cin >> str, str != "q" )  {
        switch( str[0] )  {
            case 'c':                   //遇“c”清空操作数栈
                s.clear();
                break;
            case '-':                   //遇“-”需判断是减号还是负号
                if( str.size() > 1 )    //若字符串长度大于1，说明读到的是负数的符号
                    enter( stringToDouble( str ) );   //将字符串转换为整数，压入栈
                else
                    compute( str[0] );         //若是减号，则执行计算
                    break;
            case '+':                 //遇到其他操作符时
            case '*':
            case '/':
            case '^':
                compute( str[0] );    //执行计算
                break;
            default:                          //若读入的是操作数，转换为整型后，压入栈
                enter( stringToDouble( str ) );
                break;
        }
    }
}

//清空栈操作
void Calculator::clear()  {
    s.clear();
}
