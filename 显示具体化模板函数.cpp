#include <iostream>
#include <string>

using namespace std;

const int NUMINT = 6;
const int NUMDOUBLE = 4;
const int NUMPOINT = 5;

template <class T>          //模板函数原型
    T maxn(T * array, int n);
template <class T>
    T maxLength(T * array, int n);        //模板函数原型
template <>  string maxLength<string>(string ch[], int n)

/*
1、模板函数显示具体化，首先用template <>打头用以表明是。
2、显示具体化，其中的函数名应该为上面已经声明和定义
  （在后面）了的模板函数的函数名，如maxLength，并在
   该函数名后面的<>内写明要显示化的类型，如string  */
{
 string str;
 str = ch[0];
 for(int i = 1; i < n; i++) {
    if(str.length() < ch[i].length())     //计算字符串的长度用句点
        //法调用相对应的函数，如str.length()
        str = ch[i];   //字符串之间可以用已经重载了的=进行直接赋值
    }
    return str;      //返回字符串
}

int main() {
    int arrayInt[NUMINT] = {1, 2, 3, 4, 5, 6};
    double arrayDouble[NUMDOUBLE] = {1.1, 2.2, 3.3, 4.4};
    int a;
    double b;
    cout << "arrayInt: " << endl;
    for(int i = 0; i < NUMINT; i++)  {
        cout << arrayInt[i] << " ";
    }
    cout << endl;
    cout << "arrayDouble: " << endl;
    for(int i = 0; i < NUMDOUBLE; i++)  {
        cout << arrayDouble[i] << " ";
    }
    cout << endl;
    a = maxn(arrayInt,NUMINT);      //调用模板函数
    b = maxn(arrayDouble,NUMDOUBLE);   //调用模板函数
    cout << "a = " << a << " " << "b = " << b << endl;

//定义字符串数组
    string arrayString[NUMPOINT] = {"abc", "defgh", "dfadfasdfaa", "dfas", "aaaaaaaa"};
    for(int k = 0; k < NUMPOINT; k++) {
        cout << "ROW" << k + 1 << " : " << arrayString[k] << endl;
    }

    //用二维字符数组来存储字符串，效果等价于字符串数组，

    //但尽可能地避免同时使用字符串数组和二维字符数组
    char myc[6][6] = {"abc", "123", "456", "78910", "1112"};
    for(int j = 0; j < 6; j++)  {
        cout << "row" << j + 1 << ":   " << myc[j] << endl;
    }

    //输出利用函数模板显示具体化后返回的字符串地址，即

    //在返回的字符串前面加上去地址符号&即可
    cout << &maxLength(arrayString, NUMPOINT) << endl;

    return 0;
}


template <class T>       //求数组中最大值的模板函数
T maxn(T * array, int n)  {
    T temp;
    temp = array[0];
    for(int i = 1; i < n; i++)  {
        if(temp < array[i])
        temp = array[i];
    }
    return temp;
}

/*【心得】
1、在模板类中，所有的函数都为模板函数！
2、在模板类外定义模板函数时，格式为：
   template<class T, int SIZE>
   void Stack<T, SIZE>::getX()  {}
3、如果需要同一种算法用于不同类型的函数，请用模板，它虽然不能缩短可执行程序，
   但它使生成多个函数定义更简单、更可靠。具体化将覆盖常规模板，而非模板函数
   将覆盖具体化和常规模板。
 ===================================================================================
比如，你定义了一个函数模板
template<typename T>
void func(const T& t)
{
    dosomething(t);
}

但是，当T是整数的时候你不想dosomething，而是想killsomeone，那就需要具体化了。
具体化有2种形式，一种是显式具体化
即定义一个特殊类型的实现
template<>
void func<int>(const int& t)
{
    killsomeone(t);
}
这样，除了int型以外，其他类型仍然按照dosomething来运行

另一种方式是写一个函数来屏蔽模板
比如，定义如下
void func(const int& t)
{
    killsomeone(t);
}
这样，在编译链接时这个函数就屏蔽掉了模板，自动采用定义的函数。
*/

