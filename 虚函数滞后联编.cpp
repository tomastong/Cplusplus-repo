/*=======================Program Description==============================
程序名称：对虚函数操作.cpp
程序目的：虚函数滞后联编
Written By Dong-Hong-Yan(2012-5-12)
==========================================================================*/

#include<iostream>
using namespace std;

class  Publication   {
    public:
        string title;
        float price;
        virtual void getData(string name, float rate, int temp) {
            title=name;
            price=rate;
        }
        virtual void putData() {
            cout << "Title: " << title << endl;
            cout << "Price " << price << endl;
        }
};

//对基类的虚函数，进行添加操作，多输入或多输出了一些添加的变量
class book : public Publication  {
        public:
            int pagecount;
            void getData(string name, float rate,int pages) {
                Publication::getData(name,rate,pages);  //对另一个类进行传参操作
                pagecount=pages;
            }
            void putData() {
            Publication::putData();
            cout << "PageCount: " << pagecount << endl;
            }
};

//对基类的虚函数，进行添加操作，多输入或多输出了一些添加的变量
class tape : public Publication {
    public:
        int playTime;
        void getData(string name, float rate, int timer) {
        Publication::getData(name, rate, timer);  //对另一个类进行传参操作
        playTime=timer;
        }
        void  putData() {
        Publication::putData();
        cout << "PlayTime: " << playTime << endl;
        }
};

//【主程序】
int main() {
    Publication * p;

    p = new book;
    p->getData("book ", 100, 1);
    p->putData();
    delete p;

    p = new tape;
    p->getData("type ", 50, 2);
    p->putData();
    delete p;

    return 0;
}

/*【心得】
1、与基类的虚函数有相同的参数个数；
2、其参数的类型与基类的虚函数的对应参数类型相同；
3、其返回值或者与基类虚函数的相同，或者都返回'指针'或'引用'，并且
   派生类虚函数所返回的指针或引用的基类型是基类中被替换的虚函数
   所返回的指针或引用的基类型的子类型。
   */
