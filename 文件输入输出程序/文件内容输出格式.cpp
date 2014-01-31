#include<iostream>            //文件包含
#include<fstream>             //流类输入输出文件
#include<cstdlib>

using namespace std;

//主程序
int main() {
    fstream file;               //构造流类对象file
    file.open("file1.txt", ios::out);        //以输出文件格式，打开文本file.txt
    if(!file) {          //构造流类对象存在
        cout << "Open Error!" << endl;
        abort();
    }
    file << "i am a super man !" << endl;      //写入文本
    file.close();    //关闭函数

    return 0;
}
