/*==============================Program Description====================================
程序名称:虚基类及其派生类的构造函数.cpp
程序目的:使用虚基类排除程序中易出现的不必要的错误，也是累赘！
         //建立Derived类对象d时，通过Derived类的构造函数初始化列表，不仅直接调用虚基类
         构造函数Base0，对从Base0继承的成员var0进行了初始化，而且还调用了直接基类Base1
         和Base2，而Base1和Base2的初始化列表中也都有对Base0的初始化，这样岂不是对var0
         初始化了3次？？？？？
Written By Dong-Hong-Yan(2012-5-15)
=======================================================================================*/

#include<iostream>
using namespace std;

//定义类Base0
class Base0  {
    public:
        Base0( int var ): var0( var )  {}
        int var;
        void fun() { cout << "Member Of Base0 " << endl; }
};

//定义类Base1
class Base1 : virtual public Base0 {           //Base0为虚基类，派生Base1
    public:                          //新增外部接口
        Base1( int var ): Base0( var )  {}
        int var1;
};

//定义类Base2
class Base2 :  virtual public Base0 {          //Base0为虚基类，派生Base2
    public:                          //新增外部接口
        Base2( int var ): Base0( var )  {}
        int var2;
};

//定义类Derived
class Derived : public Base1, public Base2  {
    public:                          //新增外部接口


        Derived( int var ): Base0( var ), Base1( var ), Base2( var )   {}
        int var;
        void fun() { cout << "Member Of Derived " << endl; }
};

//【主程序】
int main()  {
    Derived d(1);                        //定义Derived类对象d
    d.var = 2;
    d.fun();

    return 0;
}

/*【心得】：构造一个类的对象的一般顺序是
1、如果该类有直接或间接的虚基类，则先执行虚基类的构造函数。
2、如果该类有其它基类，则按照它们在继承声明列表中的次序，分别执行他们的构造函数，
   但在构造过程中，不在执行他们的虚基类构造函数。
3、在复制构造函数里，
   类兼容性规则在这里，可以用派生类的对象，去初始化基类的引用，因为当函数
   的形参是基类的引用时，实参可以是派生类的对象


二、 using 的另一个功能是将一个作用域的名字引入到另一个作用域中！
      class Derived2 :public Base1{
       public:
        using Base0::var;
        using Base0::fun();}
*/
