#include<iostream>
#include<iomanip>             //文件包含，格式控制文件

using namespace std;
//【主函数】
int main() {
    int a = 21;
    char *pt = "China";
    double pi = 3.12345678;
    cout.setf(ios::dec);
    cout << "dec:" << dec << a << endl;        //格式控制，只对右侧数据有效
    cout.unsetf(ios::dec);

    cout.setf(ios::hex);
    cout << "hex:" << hex << a << endl;          //默认对齐的方式，为右对齐
    cout.unsetf(ios::hex);

    cout.setf(ios::oct);
    cout << "oct:" << oct << a << endl;
    cout.unsetf(ios::oct);

    cout.width(10);
    cout << pt << endl;
    cout.width(10);
    cout.fill('#');
    cout << pt << endl;   //填充字符

    cout.setf(ios::scientific);
    cout << "pi = " << pi << endl;
    cout.unsetf(ios::scientific);

    return 0;
}

//如本例，3.14286798,按照setprecision（7）{该函数是用来设置实数精度}，答案3.142868（不带小数点）
//一般不写格式的话，默认是setprecision（6）

/*
流成员函数                     相同作用的控制符                  作用
precision(n)                   setprecision(n)         设置实数的精度为n
width(n)                       setw(n)                 设置字段宽度
fill(c)                        setfill(c)              设置填充字符
setf()                         setiosflags()           设置输出状态
unsetf()                       unsetiosflags()         终止已设置的输出状态
*/
