/*===================================================Program Description======================================================
程序名称：【友元】图书管理系统 .cpp
程序目的：用友元实现一个简单的图书管理系统。编写程序，实现从键盘输入4本图书信息、然后显示所输入的4本图书信息；比较图书的价格,
          输出最贵的图书和最便宜的图书；从键盘输入编辑姓名和要修改图书的编号（4本书的编号默认为0、1、2、3），图书编辑修改图书的
          价格为新输入的值。

程序要求：1.首先定义一个图书类。图书包含书名和价格信息，这些信息要求从键盘输入。
          2.定义图书编辑类。图书编辑包含编辑姓名信息，并且可以调整图书价格信息。
          3.考虑使用友元函数与友元类来实现。
输入输出样式:
请输入4本书的信息             ||                   所有数目信息：
书名        价格              ||                    0    《aa》    40
aa 40                         ||                    1    《bb》    41
bb 41                         ||                    2    《cc》    42
cc 42                         ||                    3    《dd》    43
dd 43
最贵的书是----    书名：《dd》  价格：43
最便宜的书是--    书名：《aa》  价格：40
请输入编辑姓名:wang
请输入让编辑修改价格的数目编号:0
请输入 《aa》 的新价格:41
编辑 wang 将 《aa》的价格已经更改为：41
Written By Dong-Hong-Yan (2012-4-12)
==============================================================================================================================*/

#include<iostream>
using namespace std;

const int NUM = 4;

//【图书管理类】
class BookManageSystem  {
      public:
             BookManageSystem(int bookPrice = 0): bookPrice(bookPrice) { }             //构造函数
                                                          //因为是字符串，还有'\0'，故加“1”
                                                                                                  //strlen函数测出的是不包括'\0'的长度
             BookManageSystem(BookManageSystem &p);

             void input();
             void output();

             friend void Compare_MaxPrice();
             friend void Compare_MinPrice();
             friend void Alter();                                                 //友元函数的声明
      private:
              char bookName[20];
              int bookPrice;

      } book[4];              //直接初始化类数组

//复制i构造函数的定义
BookManageSystem::BookManageSystem(BookManageSystem &p)  {

                    bookPrice=p.bookPrice;
                    }
//定义书类信息输入函数
void BookManageSystem::input()  {
          cin>>bookName>>bookPrice;
     }

//定义书类信息输出函数
void BookManageSystem::output()  {

     cout<<"   《"<<bookName<<"》    "<<bookPrice<<endl;
     }

//定义输出最便宜的书信息
void Compare_MaxPrice()  {
    int k = 0;
    for(int i = 0; i < NUM; i++)  {
          if(book[i].bookPrice > book[k].bookPrice)  {
                               k = i;
                               }
           }
    cout<<"最贵的书是----    "<<"书名：《"<<book[k].bookName<<"》  价格："<<book[k].bookPrice<<endl;
    }

//定义输出最便宜的书信息
void Compare_MinPrice()  {
    int k = 0;
    for(int i = 0; i < NUM; i++)  {
          if(book[i].bookPrice < book[k].bookPrice)
                               k = i;
           }
    cout<<"最便宜的书是--    "<<"书名：《"<<book[k].bookName<<"》  价格："<<book[k].bookPrice<<endl;
    }

void Alter()  {
     char manName[10];
     int price;
     int number;

     cout<<"\n\n请输入编辑姓名"<<endl;
     cin>>manName;

     cout<<"请输入让编辑修改价格的数目编号"<<endl;
     cin>>number;

     cout<<"请输入 《"<<book[number].bookName<<"》 的新价格"<<endl;
     cin>>price;

     cout<<"编辑 "<<manName<<" 将 《"<<book[number].bookName<<"》的价格已经更改为：" <<price<<endl;
     }

//【主程序】
int main()  {
    int i;
    cout<<"请输入4本书的信息"<<endl<<"书名        价格"<<endl;

    for(i = 0; i < NUM; i++)  {
            book[i].input();
            }
    cout<<"\n\n所有数目信息："<<endl;
    for(i = 0; i < NUM; i++)  {
            cout<<i<<" ";
            book[i].output();
            }

    Compare_MaxPrice();
    Compare_MinPrice();

    Alter();

    return 0;
    }

