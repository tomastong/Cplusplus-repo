/*============================Program Description===================================
程序名称：向量的用法（vector）.cpp
程序目的：问答的方式，通过6种不同的数列，知道前2个数字，猜第3个，回答失败，给出不同
          的慰问
Writeen By Dong-Hong-Yan(2012-4-21)
====================================================================================*/

#include<iostream>
#include<vector>    //用到vector容器，需加头文件#include<vector>
#include<string>
#include<cTime>
#include<cstdlib>
using namespace std;

const int seq_cnt = 6;             //定义数列名称类型为6
const int seq_size = 18;           //定义数列数组长度为18

//这里呢，是定义一个返回值为字符型指针的（常）函数，其中int num_tries为形参
 const char * msg_to_user( int num_tries )  {
      const int rap_cnt = 5;       //定义不同答案回复，有5种

    //静态常量的字符指针，指向常量的指针const int * p=&a;指针类型的常量int * const p=&a;
      static const char * user_msgs[ rap_cnt ] = {
        "Go on, make a guess.\n","Oops! Nice guess but not quite it.\n",
        "Hmm. Sorry. Wrong again!\n", "Ah, this is harder than it looks ,no ? \n",
        "It must be getting pretty frustrating by now ! \n"
         };
      if( num_tries < 0)
         num_tries = 0;
      else
         if( num_tries >= rap_cnt )
            num_tries = rap_cnt - 1;
    return user_msgs[ num_tries ];
    }
//【主函数】
int main()  {

    int num_tries;
    int seq_index;                     //定义数组名字的索引（通过随机函数选择第几个）
    int user_guss;                     //定义用户猜的数值
    int cur_tuple = 0;                 //欲显示之元素的索引值
   // int elem_seq[seq_size];
    int elem_vals[ seq_size ] = { 1, 2, 3,         //Fibonacci
                    3, 4, 7,         //Lucas
                    2, 5, 12,        //Pell
                    3, 6, 10,        //Triangular
                    4, 9, 16,        //Square
                    5, 12, 22         //Pentagonal
                    };
    string seq_names[seq_cnt] = {
    "fibonacci",
    "lucas",
    "pell",
    "triangular",
    "square",
    "pentagonal"
    };
    //用数组elem_vals初始化vector类型的elem_seq
    vector<int>elem_seq(elem_vals, elem_vals+seq_size);

  /*  vector<int> seq_addrs[ seq_cnt ] = { &seq_names[0], &seq_names[1],
    &seq_names[2], &seq_names[3], &seq_names[4], &seq_names[5]
                    };
*/

       srand(( unsigned )time( NULL ));     //使用系统随机函数的种子
       seq_index = rand() % seq_cnt;
       cur_tuple = seq_index;
        static int count = 0;

    while(  cur_tuple < seq_size && count <6 )  {
      static int num_tries = 0;

       cout << "The first two elements of the sequence are: "
            << elem_vals[ 3 * cur_tuple ] << ","
            << elem_vals[ 3 * cur_tuple + 1 ]
            << "\nWhat is the next element ? ";

       cin >> user_guss;
       if(user_guss == elem_vals[ 3 * cur_tuple + 2 ])  {

          cout << "Very good.Yes! " << elem_vals[ cur_tuple + 2]
               << " is the next element in the " << seq_names[ cur_tuple / 3]
               << " sequence.\n" << endl;

         }
       else  {

          const char * receive = msg_to_user(num_tries);
          cout << receive << endl;
          ++num_tries;
        }

        count++;

       srand(( unsigned )time( NULL ));      //使用seed作为随机函数的种子
       seq_index = rand() % seq_cnt;
       cur_tuple = seq_index;

    }

    return 0;
}

