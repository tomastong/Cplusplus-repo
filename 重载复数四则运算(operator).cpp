/*===============================Program Description===============================
程序名称：重载复数的四则运算.cpp
程序目的：举一个关于给复数运算 重载复数的四则运算符的例子。复数由实部和虚部构造，可
          以定义一个复数类，然后再在类中重载复数四则运算的运算符。
Written By Dong-Hong-Yan(2012-4-18)
===================================================================================*/
#include   <iostream>
using namespace std;

//定义【complex】类
class   complex
{

    public:

        complex()   {   real=imag=0;   }

        complex(double   r,   double   i)

        {

                real   =   r,   imag   =   i;

        }

        complex   operator   +(const   complex   &c);

        complex   operator   -(const   complex   &c);

        complex   operator   *(const   complex   &c);

        complex   operator   /(const   complex   &c);

        friend   void   print(const   complex   &c);

private:

        double   real,   imag;

};



inline   complex   complex::operator   +(const   complex   &c)

{

        return   complex(real   +   c.real,   imag   +   c.imag);

}



inline   complex   complex::operator   -(const   complex   &c)

{

        return   complex(real   -   c.real,   imag   -   c.imag);

}



inline   complex   complex::operator   *(const   complex   &c)

{

        return   complex(real   *   c.real   -   imag   *   c.imag,   real   *   c.imag   +   imag   *   c.real);

}



inline   complex   complex::operator   /(const   complex   &c)

{

        return   complex((real   *   c.real   +   imag   +   c.imag)   /   (c.real   *   c.real   +   c.imag   *   c.imag),

                        (imag   *   c.real   -   real   *   c.imag)   /   (c.real   *   c.real   +   c.imag   *   c.imag));

}



void   print(const   complex   &c)

{

        if(c.imag <0)

                cout <<c.real<<c.imag << "i ";  //如果c.imag<0的话，那么c.imag已经有负号了，不需要再输出负号了

        else

                cout <<c.real << "+ " <<c.imag << "i ";

}



int   main()

{

        complex   c1(2.0,   3.0),   c2(4.0,   -2.0),   c3;

        print(c2);

        c3   =   c1   +   c2;

        cout << "\nc1+c2= ";

        print(c3);

        c3   =   c1   -   c2;

        cout << "\nc1-c2= ";

        print(c3);

        c3   =   c1   *   c2;

        cout << "\nc1*c2= ";

        print(c3);

        c3   =   c1   /   c2;

        cout << "\nc1/c2= ";

        print(c3);

        c3   =   (c1+c2)   *   (c1-c2)   *   c2/c1;

        cout << "\n(c1+c2)*(c1-c2)*c2/c1= ";

        print(c3);

        cout << endl;

        return 0;

}



     /*   该程序的运行结果为：



        c1+c2=6+1i

        c1-c2=-2+5i

        c1*c2=14+8i

        c1/c2=0.45+0.8i

        (c1+c2)*(c1-c2)*c2/c1=9.61538+25.2308i




        在程序中，类complex定义了4个成员函数作为运算符重载函数。将运算符重载函数说明为类的成员函数格式如下：



        <类名>   operator   <运算符> ( <参数表> )



        其中，operator是定义运算符重载函数的关键字。*/

//////////////////////////////////////////////////////////////////////////////////
/*
    举个例子比较一下
定义一个两个struct对象相加的函数
struct   A{...};
const   A   Add(const   A  &ra, const   A   &b){...};
这样如果想相加两个A类对象，就可以这样
A   a,b,c;
c=Add(a,b);   //如果觉得这样不爽，那么你就可以用operator,继续往下看

const   A   operator+(const   A&   ra,const   A&   rb){...};   //和上面那个Add函数从格式上比较一下
现在就可以这样
c=a+b;
当然还可以实现*,/,多得很
如果你问operator+和Add有什么区别，区别就是“样式更好看”，“operator+重新定义了适合struct   A的+操作”
////
未完，继续，operator的另外一个意义
class   A{
    int   i;
public:
    A(){   i=50;}
};
如果现在要实现class   A和int相加，并返回一个int，例如下面
int   i=a+50;   ?????
可以这样写,在class   A中添加一个GetI之类的成员函数返回A::i的值
class   A{
    int   i;
public:
    A(){   i=50;}
    int   GetI(){return   i;}
};

int   i=a.GetI()+50;   //如果你觉得不爽，你可以用下面的方法
class   A{
    int   i;
public:
    A(){   i=50;}
    friend   const   int   operator+(const   A&   ra,const   int&   rb);
};
这样你就可以用
int   i=a+50;   //但是还是不爽，如果遇到-,*,/，只有都挨个实现
现在有一个更安逸的方法，看
class   A{
    int   i;
public:
    A(){   i=50;}
    operator   int()   const{   return   int(i);}   //将A自动转换为一个int临时对象
};
这样就爽了
A   a;
int   i=a+50;
i=a-15;
都能用
而且还可以，用在这样的函数上void   fun(int   i);
fun(a);同样可行
*/
