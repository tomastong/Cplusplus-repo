#include<iostream>
#include<fstream>
#include<cstdlib>             //文件包含，用到abort()函数

using namespace std;

int main()  {
    ofstream file("file.txt", ios::app);        //如果再这里追加，只能用ofstram定义，fstream就不行
    if(!file) {
        cout << "File open error !" << endl;
        abort();
    }
    file << "How about you ?" << endl;           //追加内容
    file.close();      //文件流关闭

    return 0;
}

