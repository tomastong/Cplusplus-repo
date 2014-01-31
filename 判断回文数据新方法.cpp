#include <iostream>
using namespace std;

int main()
{
    int num1=0;
    int num2=0;
    int Temp;

    int i;         // 取得元素的各个位值

    cout << "请输入一个整数：";
    cin >> num1;

    Temp = num1;

    cout << "这个整数的逆向数值为:";
    while(num1>0)
    {
        i = num1 % 10;
        num1 /= 10;
        num2 = num2*10 +i;
    }
    cout << num2 << endl;

    if (Temp == num2)
    {
        cout << "该数是回文数据\n";
    }
    else
    {
        cout << "该数不是回文数据\n";
    }
    return 0;
}
