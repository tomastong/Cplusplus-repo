/*=====================================Program Description============================================
程序名称:模板函数应用.cpp
程序目的:要求并掌握模板函数声明形式：
         template<模板参数表>  class 类名 {类成员声明}
Written By Dong-Hong-Yan(2012-5-30)
======================================================================================================*/

#include<iostream>
#include<cstdlib>
using namespace std;

struct Student {            //结构体Student
    int id;                 //学号
    float gpa;              //平均分
};
//提高代码的重用性
template <class T>                         //类模板：实现对任意类型数据进行存取
class Store {
    public:
        Store();                           //默认形式（无形参）的构造函数
        T &getElem();                      //提取数据函数
        void putElem(const T &x);          //存入数据函数
    private:
        T item;                                //item用来存放任意类型的数据
        bool haveValue;                        //haveValue标记item是否已被存入内容
};

template<class T>
Store<T>::Store():haveValue(false) {}        //默认构造函数的实现

template<class T>
T &Store<T>::getElem() {                    //提取数据函数的实现
    if(!haveValue) {                              //如果试图提取未初始化的数据，则终止程序
        cout << "No,item present!" << endl;
        exit(1);                                //是程序完全退出，返回操作系统
    }
    return item;                              //返回item中存放的数据
}

template<class T>
void Store<T>::putElem(const T &x) {     //存入数据的实现
    haveValue = true;                    //将haveValue置为true，表示item已存入数据
    item = x;                            //将x存入item
}

//【主程序】
int main() {
    Store<int>s1, s2;    //定一两个Store<int>类对象，其中数据成员itemitem为int类型
    s1.putElem(3);          //向对象s1中存入数据（初始化对象s1）
    s2.putElem(-7);         //向对象s2中存入数据（初始化对象s2）
    cout << s1.getElem() << " " << s2.getElem() << endl;
                  //输出对象s1和s2的数据成员
    Student g ={1000, 23};          //定义Student类型结构体变量的同时赋予初值
    Store<Student>s3;               //向s3中存入数据（初始化对象s3）
    s3.putElem(g);
    cout << "The student id is " << s3.getElem().id << endl;
                 //输出对象s3的数据成员
    Store<double>d;            //定义Store<double>类对象d，其中数据成员item为double类型
    cout << "Retrieving object d...";
    cout << d.getElem() << endl;          //输出对象d的数据成员

    return 0;
}
