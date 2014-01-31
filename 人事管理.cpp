/*===================================Program  Description======================================
程序名称：人事管理.cpp
程序目的：对人员的信息实现录入和显示，包括编号、性别、出生日期、身份证号等
程序要求：必须为类的组合，声明一个人员类，内嵌日期类-子对象。必须有构造函数、析构函数、复制构造
         函数内联成员函数、带默认形参值的成员函数、类的组合。        
written By Dong-Hong-Yan (2012-4-5)
===============================================================================================*/

#include<iostream>
using namespace std;

//【日期类】 
class Date  {
      public:                //外部接口 
             Date() :year(0), month(0), day(0) {}
             void GetDate();
             int GetYear()
			 {
			   return year;
			 }
			 int GetMonth()
			 {
			    return month;
			 }
			 int GetDay()
			 {
			    return day;
			 }
			 /*void SetYear(int dyear)
			 {
			    //这里可以添加数据校验
				this.year=dyear;
			 }
			 void SetMonth(int dmonth)
			 {
			    this.month=dmonth;
			 }
			 void SetDay(int dday)
			 {
			    this.day=dday;
			 }*/
             ~Date() {} 
			/* string ToString()
			 {
			    char[100] tmp;
				sprintf(tmp,"%d-%d-%d",year,month,day);
				return string(tmp);
			 }*/
      private:          //私有数据 
              int year;      //定义年份 
              int month;     //定义月份 
              int day;       //定义日期 
      };

 //定义内联信息输入函数     
inline void Date::GetDate()  {
     cin>>year>>month>>day;
     }
 
//【人员类】 
class Person  {
      public:
             //构造函数的声明以及定义，可以不同时初始化所有私有成员，更可以不带参，像Date一样 
			 Person(int man_num = 0, char sex = '\0', int id = 0):man_num(man_num), sex(sex), 
             id(id) {}
             Person(Person &p); 
			 void Get_Info();
             void Show_Info();
             ~Person()  {}  		
      private:
              int man_num;     //定义个人编号 
              char sex;        //定义性别 
              Date birth_day;  //定义出生日期 
              int id;          //定义身份证号 
      };

//人员类-复制构造函数的定义      
Person::Person(Person &p): man_num(p.man_num), sex(p.sex), id(p.id) { 
                      birth_day=p.birth_day;
                      }

//人员的输入信息，必须通过嵌套子类，调用子类的输入函数 
void Person::Get_Info()  {
	 cout<<"Please enter your man_num, sex, id, year, month, day:";
     cin>>man_num>>sex>>id;
     birth_day.GetDate();
     }
//人员的输入信息，必须通过嵌套子类,调用子类的输出函数                 
void Person::Show_Info()  {
     cout<<"The information you entered is :"<<endl;
     cout<<man_num<<" ";
     cout<<sex<<" ";
     //cout<<birth_day.year<<" ";
     //cout<<birth_day.month<<" ";
     //cout<<birth_day.day<<" ";
	 //方法1
	 cout<<birth_day.GetYear()<<" ";
	 cout<<birth_day.GetMonth()<<" ";
	 cout<<birth_day.GetDay()<<" ";
	 cout<<id<<endl;
	 /*//方法2
	 cout<<birth_day.ToString();
	 
     cout<<id<<" "<<endl;  
     */  
     }



// 【主程序】
int main()  {
    Date date;        //声明并定义日期类 ，可以不带参数 
    Person man;       //声明并定义人员类，可以不带参数 
    man.Get_Info();
    man.Show_Info();
    system("pause");
    return 0;
    }
      

