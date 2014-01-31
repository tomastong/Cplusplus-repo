/*===========================Program Description===========================
程序名称：运算符重载复数类.cpp
程序目的：实现复数的+、-、*、/运算。
程序要求：1. +、*为类运算符；
          2. -、/为友元运算符；
          3. 复数的实部和虚部为实数；
Written By dong-Hong-Yan(2012-5-30)  
===========================================================================*/

#include<iostream>
using namespace std;

class Complex {
    public:
        Complex(double real = 0, double imag = 0)  {
            this->real = real;
            this->imag = imag;
        }
        void input() {
            cout << "请输入一个复数的实部  虚部" << endl;
            cin >> real >> imag;
        }
        void display()  {


            cout << real << " + " << imag << 'i' << endl;
        }
        ~Complex()  {}

      //重载加法运算
        Complex operator + (const Complex &right) const  {
            Complex temp;
            temp.real = real + right.real; temp.imag = imag + right.imag;
            cout << "a + b = " << temp.real << " + " << temp.imag << 'i' <<endl;
            return temp;
        }

      //重载减法运算
        Complex operator - (const Complex &right)  {
            Complex temp;
            temp.real = real - right.real; temp.imag = imag - right.imag;
            if(temp.imag < 0)
                cout << "a - b = " << temp.real << " + (" << temp.imag << ") i" <<endl;
            else
                cout << "a - b = " << temp.real << " + " << temp.imag << "i" <<endl;

            return temp;
        }

      //重载乘法运算
       friend Complex operator * (const Complex &obj, const Complex &right);

      //重载除法运算
        friend Complex operator / (const Complex &obj, const Complex &right);
    private:
        double real;
        double imag;
};

        Complex operator * (const Complex &obj, const Complex &right)  {
            Complex temp;
            temp.real = obj.real * right.real - obj.imag * right.imag;
            temp.imag = obj.imag * right.real + obj.real * right.imag;
            cout << "a * b = " << temp.real << " + " << temp.imag << 'i' << endl;
            return temp;

        }

         Complex operator / (const Complex &obj, const Complex &right)  {
            Complex temp;
            if((right.real * right.real + right.imag * right.imag) == 0)
            {
                cout << "a / b = " << 0 << " + " << 0 << 'i' << endl;
                return 0;
            }
            else {
            temp.real = (obj.real * right.real + obj.imag * right.imag)/(right.real * right.real + right.imag * right.imag);
            temp.imag = (obj.imag * right.real - obj.real * right.imag)/(right.real * right.real + right.imag * right.imag);
            cout << "a / b = " << temp.real << " + " << temp.imag << 'i' << endl;
            return temp;}
        }
//【主程序】
int main() {
    Complex *obj;
    obj = new Complex[6];   //动态申请类数组

    obj[0].input();
    obj[1].input();

    cout << "\n\n复数运算结果为" << endl;
    cout << "a = ";  obj[0].display();
    cout << "b = ";  obj[1].display();

    obj[2]= obj[0] + obj[1];
    obj[3]= obj[0] - obj[1];
    obj[4]= obj[0] * obj[1];
    obj[5]= obj[0] / obj[1];

    return 0;
}
