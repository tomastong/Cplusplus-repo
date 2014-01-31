/*================================================Program Description==================================================
程序名称：Lab4：动态分布数组内存.cpp
程序目的：用动态对象数组实现一个简单的学生成绩管理系统。
          定义一个学生类，有姓名、学号、性别、四门功课（Math、English、C、Computer）和平均分等私有数据成员。
          用该学生类定义学生对象，学生信息由键盘输入；求出每个学生的平均分；然后显示每个学生的姓名、学号、四门课成绩和平均分。
程序要求：1. 用动态对象数组实现；
          2. 学生姓名的定义为：char *name；
          3. 用构造函数实现学生信息的初始化；
          4. 平均分的计算要用一个单独的函数实现；
          5. 请严格按照下面的格式进行输入输出。
Written By Dong-Hong yan（2012-3-29） 
=======================================================================================================================*/ 

//Lab4.cpp程序实例 
#include<iostream>
using namespace std;

//声明一个学生类 
class Student {
      //公有成员 
    public:
        //在类中声明并定义信息初始化函数（构造函数） 
        Student() {
        name=new char[10];
        }
        //在类中声明并定义信息输入函数 
        void input()  {
            cin>>name>>stu_num>>sex>>Math>>English>>C>>Computer;
        }
        //在类中声明并定义平均分计算函数 
        void aver()  {
            Average=(Math+English+C+Computer)/4.0;
        }
        //在类中声明并定义信息输出函数 
        void output()  {
        cout<<name<<" "<<stu_num<<" "<<sex<<" "<<Math<<" "<<English<<" "<<C<<" "<<Computer<<" "<<Average<<endl;
        }
        //在类中声明并定义析构函数函数 
        ~Student() {
        delete [] name ;  //用delete删除new申请的空间，如果是数组，中间加一个[] 
        }
        
        //私有成员 
    private:
        int stu_num;                //学生学号 
        char *name,sex;             //姓名，性别 
        int Math,English,C,Computer;//各科成绩 
        double Average;             //总科目的平均分 
};


//【主程序】 
int main()  {
    int num;   //输入学生信息条数 
    int i;     //定义循环索引 
    
    //输入输出提示信息 
    cout<<"Please Input the Number of Students:"<<endl;
    cin>>num;
    cout<<"Please input "<<num<<" student info: Name  ID  Sex  Math  English  C  Computer"<<endl;
    
    //动态申请类对象数组【注意：申请的时候用的是类指针】 
    Student *info=new Student[num];
    for(i=0;i<num;i++)  {
    info[i].input();    //调用类成员函数 
    info[i].aver();     //调用类成员函数 
    }
    
    //输入输出提示信息 
    cout<<"Student Information you input:"<<endl;
    cout<<"Name  ID  Sex  Math  English  C  Computer  Average"<<endl;
    //循环输出学生个人信息 
    for(i=0;i<num;i++)  {
    info[i].output();
    }
    delete [] info;    //删除动态申请的类数组
    //system("pause");是编译结果暂停一下，可以看编译结果 
    system("pause");
    return 0;
}

/*心得：  
1.编程序时，尽量将类和变量的定义写在一块（今后还可能写入.h文件中），而将类的实现即函数等全写在类外（今后还可能写入.cpp文件中），这样结构清晰。
2.另外关于构造函数，如果构造函数没有形参，不用传值，可以令一些私有成员(非字符型)直接等于0或（字符型）为'\0'；如果有形参，则将
  参数传给私有成员(但前提是必须给形参初始化或者在主函数中，用类名进行类的对象声明及初始化如Student stu(3,2,1);)。一个类中构造函数可以有多个，
  分为有参和无参的，如果主函数调用无参构造函数，则直接写Student stu;即可，不用写Student stu();
3.是关于用指针动态申请内存空间，必须用的是指针，如： name=new char[10];和Student *info=new Student[num];，用指针申请后，对该内存空间输入值或
  其它信息，记住用的是指针名（int *p，p才是指针名）直接输入输出即可*/ 












