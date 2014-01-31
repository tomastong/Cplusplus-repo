/*================================Program Description====================================
程序名称：学生通讯录程序.cpp
程序目的：用来存储学生的名字、电话号码及电子信箱等信息！
Written By Dong-Hong-Yan(2012-5-6)
=========================================================================================*/

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

//定义学生信息类
class Student  {
    public:
        Student( string sName )  {            //用来从键盘读取数据信息
            cout << "\n********输入《" << sName << "》信息********\n";
            this->sName = sName;
            cout << "   通信地址 ：";
            cin >> sAddree;
            cout << "   电话号码 : ";
            cin >> sPhone;
            cout << "   手机号码 : ";
            cin >> sMobile;
            cout << "   电子信箱 ：";
            cin >> sEmail;
            cout << "\n********输入《" << sName << "》完毕********\n";
        }
        Student( string sName, string sAddree, string sPhone,
                 string sMobile, string sEmail )      //用来从文件读取数据信息
        {
            this->sName = sName;
            this->sAddree = sAddree;
            this->sPhone = sPhone;
            this->sMobile = sMobile;
            this->sEmail = sEmail;
        }
        void Display()  {              //显示个人数据信息
            cout << "\n********显示《" << sName << "》信息********\n";
            cout << "1、姓名是：" << sName << endl;
            cout << "2、地址是：" << sAddree << endl;
            cout << "3、电话是：" << sPhone << endl;
            cout << "4、手机是：" << sMobile << endl;
            cout << "5、邮箱是：" << sEmail << endl;
            cout << "\n********显示《" << sName << "》完毕********\n";
        }
        bool Cmpkey( string str )  {          //从链表中查找相关数据
            if( sName == str )  return true;
            if( sPhone == str )  return true;
            if( sMobile == str )  return true;
            if( sEmail == str )  return true;

            return false;
        }
        void Modify()  {          //修改结点数据
            do  {
                cout << "\n********《修改通讯录信息》********\n";
                cout << "1、姓名是：" << sName << endl;
                cout << "2、地址是：" << sAddree << endl;
                cout << "3、电话是：" << sPhone << endl;
                cout << "4、手机是：" << sMobile << endl;
                cout << "5、邮箱是：" << sEmail << endl << endl;
                int iChoice;
                cout << "   选择要修改项目的编号（1-5）：" << endl;
                cout << "   按任意其它键退出修改，输入：";
                cin >> iChoice;
                switch( iChoice )  {
                    case 1:
                        cout << "   输入修改后的姓名：";
                        cin >> sName;
                        break;
                    case 2:
                        cout << "   输入修改后的地址：";
                        cin >> sAddree;
                        break;
                    case 3:
                        cout << "   输入修改后的电话：";
                        cin >> sPhone;
                        break;
                    case 4:
                        cout << "   输入修改后的手机：";
                        cin >> sMobile;
                        break;
                    case 5:
                        cout << "   输入修改后的邮箱：";
                        cin >> sEmail;
                        break;
                    default:
                        break;
                }
                if( iChoice >= 1 && iChoice <= 5 )  {
                    cout << "   还要继续修改其它选项吗（y/n）";
                    char cChoice;
                    cin >> cChoice;
                    if( cChoice == 'y' || cChoice == 'Y')
                        continue;
                    else  {
                        cout << "********《修改通讯录完毕》********\n";
                        break;
                    }
                }

            } while(1);
        }
        string GetName() {          //用于访问私有成员变量sName
            return sName;
        }
        string GetPhone() {         //用于访问私有成员变量sPhone
            return sPhone;
        }
        string GetMobile() {        //用于访问私有成员变量sMobile
            return sMobile;
        }
        string GetEmail() {         //用于访问私有成员变量sEmail
            return sEmail;
        }
    private:
        string sName;             //姓名
        string sAddree;           //地址
        string sPhone;            //电话
        string sMobile;           //手机
        string sEmail;            //邮箱
};

int main()  {
    Student stu( "Dong" );
    stu.Display();
    stu.Modify();
    stu.Display();
    return 0;
}
