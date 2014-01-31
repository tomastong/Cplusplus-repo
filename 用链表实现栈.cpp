/*=========================Program Description================================
程序名称:用链表实现栈.cpp
程序目的:栈可以用数组或链表实现，使用数组实现栈不是一种好办法，因为它需要预定
         义数组的大小，用链表定义栈是可取的，这是由于动态分配的原因！
Written By Dong-Hong-Yan(2012-4-30)
==============================================================================*/

#include<iostream>
#include<string>

using namespace std;

class Information  {
    public:
        Information( string sInfoName )  {             //从键盘读取数据信息
            this->sInfoName = sInfoName;
            cout << "\n   输入数据 : ";
            cin >> sData;
        }
        string Disp_info()  {                         //显示结点数据信息
            return sData;
            }
    private:
        string sInfoName;
        string sData;         //数据
};

class Node  {
    public:
        Node * NEXT;           //指向下一个结点的节点指针（information）
        Node( string sNodeName, Node * NEXT = NULL ): INFO( sNodeName )  {
            this->sNodeName = sNodeName;
            this->NEXT = NEXT;
        }
        string Disp_Node()  {
            cout << "\n   ";
            return sNodeName;
        }
    private:
        string sNodeName;              //结点标示名称
        Information INFO;              //节点数据信息
};

class Stack  {                         //定义一个Stack类
    public:
        Stack()  {              //构造函数
            TOP = NULL;
        }
        ~Stack()  {             //析构函数
            while ( TOP != NULL )  {
                TOP = TOP->NEXT;
                delete TOP;
            }
        }
        void Push( string str ); //增加结点
        void Pop();              //删除当前节点
        void Traverse();
    private:
        Node * TOP;                  //栈顶
};

void Stack::Push( string str )  {     //增加结点到栈顶
    Node * n = new Node( str );
    if( TOP == NULL )  {              //创建栈的第一个结点
        n->NEXT = NULL;
        TOP = n;
        return ;             //函数返回，不再向下执行
    }
    else {
        n->NEXT = TOP;
        TOP == n;
    }
}

void Stack::Pop() {          //删除栈顶结点
    if( TOP == NULL ) {
        cout << "\n  栈不存在！！！  " << endl;
        return ;
    }
    Node * TEMP;
    TEMP = TOP;
    TOP = TOP->NEXT;
    delete TEMP;
}

void Stack::Traverse()  {    //遍历栈（浏览所有节点信息）
    if( TOP == NULL )  {
        cout << "\n   栈不存在！！！ " << endl;
    }
    else {
        Node * TEMP;
                            //循环显示所有节点信息
        for( TEMP = TOP; TEMP != NULL; TEMP = TEMP->NEXT )  {
            cout << TEMP->Disp_Node() << endl; //显示节点标示
        }
    }
}

//【主函数】
int main()  {
    Stack stObj;
    string data;
    cout << " \n\n**********************《栈操作》********************* " <<endl;
    char cCmd;
    do {
        cout << "\n   加入(A)  抹去(D)  浏览(T)  退出(E):";
        cin >> cCmd;
        switch( cCmd )  {
            case 'A' :
            case 'a' :
                {
                    cout << "\n   输入姓名 ：";
                    cin >> data;
                    stObj.Push( data );
                    break;
                }
            case 'D' :
            case 'd' :
                {
                    stObj.Pop();
                    break;
                }
            case 'T' :
            case 't' :
                {
                    stObj.Traverse();
                    break;
                }
            case 'E' :
            case 'e' :
                {
                    cout << " \n**********************《操作完毕》********************* ";
                    break;
                }
            default:
                cout << "\n    输入错误，重新选择菜单 ：";
        }
    }
    while ( cCmd != 'E' && cCmd != 'e' );
    return 0;
}















