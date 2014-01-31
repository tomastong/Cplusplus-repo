/*==============================Program Description=========================
程序名称：三种get函数读取数据.cpp
程序目的：输入输出流的练习！
Written By Dong-Hong-Yan（2012-5-27）
=============================================================================*/

#include<iostream>
using namespace std;

int main()  {
    char ch;
    cout << "请输入一个句子："  << endl;
    ch = cin.get();
    cout << "利用不带参的get（）函数读取结果为：" << ch << endl;
    cin.get(ch);
    cout << "利用带1个参的get（）函数读取结果为：" << ch << endl;
    char chs[30];
    cin.get(chs, 30, '\n');
    cout << "利用带3个参的get（）函数读取结果为：" << chs << endl;

    return 0;
}
/*【心得】
1、不带参的get函数，调用形式：cin.get（）
2、带一个参的get函数，调用形式：cin.get（ch），读取的字符赋给ch
3、带三个参的get函数，调用形式：cin.get（chs，10，‘$’），
   chs字符数组，10表示读入数据个数，‘$’终止符，默认的是‘\n’*/
