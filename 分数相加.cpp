#include <iostream>
#include <cstdio>
#include <cstdlib>


using namespace std;


struct Fraction
{
    int nume;  //分子
    int deno;  //分母

//友元输入输出函数
  /*  friend istream &operator>>( istream &in, const Fraction &frac )
    {
      char op;
        in >>nume >>op >>deno;   //输入分数
    }

    friend ostream &operator<<( ostream &out, const Fraction &frac )
    {
        out <<nume <<"/" <<deno;  //输出分数
    }*/

    void GetFraction( )    //输入函数
    {
      char op;
      scanf("%d%c%d", &nume, &op , &deno);
     // cin >>nume >>op >>deno;
    }

    void PutFraction( )   //输出函数
    {
      if( deno % nume )
        cout <<nume <<"/" <<deno <<endl;
       // printf("%d/%d\n",nume,deno);
      else
        cout <<deno/nume <<endl;
       // printf("%d\n",deno%nume);
    }


    void Simply( )
    {
      int temp, m, n;
      if( deno < nume )
      {
        n = deno;
        m = nume;
      }
      else
      {
        m= deno;   //分母
        n = nume;   //分子
      }
      while( temp = m%n )
      {
        //temp = m%n;
        m = n;
        n = temp;
      }   //最大公约数是n

      deno /= n;
      nume /= n;
     // cout <<nume <<endl;
     // cout <<deno <<endl;
      //cout <<n<<endl;    /////////////
    }

    Fraction operator+( const Fraction &frac )
    {                /*this*/
      Fraction newF;
        newF.deno = deno * frac.deno;      //结果的分母
        newF.nume = nume * frac.deno + frac.nume*deno;
       // cout <<newF.deno <<endl;   //调试过程
       // cout <<newF.nume <<endl;   //调试过程
        newF.Simply( );         //化简该分数

        return newF;
    }

    Fraction operator-( const Fraction &frac )
    {
      Fraction newF;
        newF.deno = deno * frac.deno;
        newF.nume = nume*frac.deno - frac.nume*deno;

        newF.Simply( );         //化简该分数

        return newF;
    }
};




//主函数
int main( )
{
    //cout <<"-------分数相加减-------" <<endl <<endl;  //程序功能提示

  char op, reply;
  Fraction frac1, frac2, frac;
  int count = 0;
    while( 1 )
    {
      frac1.GetFraction( );
      scanf("%c",&op);
      frac2.GetFraction( );
      scanf("%c",&reply);
      if( frac1.deno == 0 || frac2.deno == 0 )
      {
        printf("Case %d:\n", ++count);
        printf("FALSE\n");
      //  return 1;
      }
      else
      {


        switch( op )
        {
          case '+': frac = frac1+frac2; break;
          case '-': frac = frac1-frac2; break;
        }
        printf("Case %d:\n", ++count);
        frac.PutFraction( );  //输出结果
      }
    }


}
