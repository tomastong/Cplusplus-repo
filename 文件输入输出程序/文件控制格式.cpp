#include<iostream>
#include<iomanip>             //文件包含，格式控制文件

using namespace std;
//【主函数】
int main() {
    int a = 123;
    char *pt = "China";
    double pi = 3.14286798;

    cout << "dec:" << dec << a << endl;        //格式控制，只对右侧数据有效
    cout << "hex:" << hex << a << endl;
    cout << "oct:" << oct << a << endl;

    cout << setw(10) << pt << endl;
    cout << setfill('#') << setw(10) << pt << endl;   //填充字符

    cout << "pi = " << pi << endl;
    cout << "pi = " << setprecision(7) << pi << endl;
    cout << "pi = " << setprecision(3) <<pi << endl;

    return 0;
}

//如本例，3.14286798,按照setprecision（7）{该函数是用来设置实数精度}，答案3.142868（不带小数点）
//一般不写格式的话，默认是setprecision（6）
//用setw(n)控制输出时，n必须大于（数据有效个数+小数点），然后左补空格
