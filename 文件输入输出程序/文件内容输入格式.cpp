#include<iostream>
#include<fstream>
#include<cstdlib>             //文件包含，用到abort()函数

using namespace std;

//【主函数】
int main()  {
    fstream file("file.txt", ios::in);       //构造输入流对象
    if(!file) {
        cout << "File open error !" << endl;
        abort();        //终止程序
    }
    char array[50];
    while(!file.eof())  {                  //将文本内容读取      eof是文本结束的标志
        file.getline(array, sizeof(array));       //使用getline函数读取
        cout << array << endl;          //sizeof(array)测试数组的长度
    }
    file.close();         //文件流对象关闭

    return 0;
}
