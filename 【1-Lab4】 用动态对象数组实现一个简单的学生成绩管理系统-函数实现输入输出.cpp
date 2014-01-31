//【要求分析】 Lab4 用动态对象数组实现一个简单的学生成绩管理系统

//功能：
//用动态对象数组实现一个简单的学生成绩管理系统。
//定义一个学生类.
//姓名-学号-性别-四门功课（Math、English、C、Computer）和平均分等私有数据成员。
//用该学生类定义学生对象-学生信息由键盘输入；
//求出每个学生的平均分；然后显示每个学生的姓名、学号、四门课成绩和平均分。
//要求：
//    1. 用动态对象数组实现；
//    2. 学生姓名的定义为：char *name；
//    3. 用构造函数实现学生信息的初始化；
//    4. 平均分的计算要用一个单独的函数实现；
//    5. 请严格按照下面的格式进行输入输出。



#include <iostream>          //包含头文件isotream
#include <iomanip>          //包含头文件iomanip；便于使用setw()设置输出宽度
#include <cstring>
#include <cstdlib>




using namespace std;   //使用名称域str【所包含的标准输入输出流】

class MyStudent
{
      
  public  : 

    MyStudent( );
    
	MyStudent( char *na, int id, char gen, double ma = -1, double eng = -1, double c = -1, double com = -1 );  

	MyStudent( const MyStudent &student );     

    ~MyStudent( )              
    {
       delete[] name;            
    }



    void CountAverager( );  

    void InStudent( );   

	void OutStudent( );  


  private :  
    char *name;      //姓名
    int idnum;       //xue
	char gender;     //性别
    double math;     //数学成绩
	double english;  //英语
	double cscore;   //C语言成绩
	double computer; //计算机成绩
	double averager; //平均分
};



MyStudent::MyStudent( )
{
}

MyStudent::	MyStudent( char *na, int id, char gen, double ma/*=-1*/, double eng/*=-1*/, double c/*=-1*/, double com/*=-1*/ ) 
{
    name = new char[strlen(na)+1];   //开辟数组 
    strcpy( name, na );                    //复制数组
    idnum = id;                            //学号
    gender = gen;                          //性别
    math = ma;                             //数学成绩 
    english = eng;                         //英语成绩
    cscore = c;                            //C语言成绩
    computer = com;                        //计算机成绩        
}

MyStudent::MyStudent( const MyStudent &student )
{
    name = new char[10];    //开辟单元                  
    strcpy( name, student.name );
    idnum = student.idnum;
	gender = student.gender;
	math = student.math;
	english = student.english;
	cscore = student.cscore;
	computer = student.computer;
    averager = student.averager;
   // delete[] name;
}

void MyStudent::CountAverager( )    
{
    averager = (math+english+cscore+computer)/4;
}

void MyStudent::InStudent( ) 
{
    name = new char[10];     
    cin >>name;
    cin >>idnum;
    cin >>gender;
    cin >>math;
    cin >>english;
    cin >>cscore;
    cin >>computer;   
}

void MyStudent::OutStudent( )         
{
    cout <<name <<"  ";       //输出学生姓名
    cout <<idnum <<"  ";      //输出学生学号
    cout <<gender <<"  ";     //输出学生性别
    cout <<math <<"  ";       //输出学生数学成绩
    cout <<english <<"  ";    //输出学生英语成绩
    cout <<cscore <<"  ";     //输出学生C语言成绩
    cout <<computer <<"  ";   //输出学生计算机成绩
    cout <<averager <<endl;          //输出学生平均分
}




//主函数
int main()
{

	int length;
	cout <<"Please Input the Number of Students:" <<endl;  
    cin >>length;   //输入学生数目

  MyStudent *stu = new MyStudent[length];  //开辟数组单元

    cout <<"Please input " <<length <<" student info: Name  ID  Sex  Math  English  C  Computer" <<endl;
    for( int i = 0; i < length; i++ )   //循环实现输入 
    {
  	  stu[i].InStudent();  
      stu[i].CountAverager( );   //计算平均分			
    }
    cout <<endl;    //执行一次换行 
    
    cout <<"Student Information you input:" <<endl;    //输出信息提示
    cout <<"Name  ID  Sex  Math  English  C  Computer  Average" <<endl;//表头 	
	for( int i = 0; i < length; i++ )
	{
	  stu[i].OutStudent();
	}
    delete[] stu;
    
   // system("pause");
    return 0;
} 






