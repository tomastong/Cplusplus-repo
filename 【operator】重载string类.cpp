/*=================================Program Description===========================
程序名称：重载string类-operator.cpp
程序目的：通过运算符重载，创造属于自己的string类
Written By Dong-Hong-Yan（2012-5-13）
=============================================================================*/

#include<iostream>
#include"string1.h"
#include"string2.h"

using namespace std;

int main()  {
    String s1( "happy" ), s2( "birthday" ), s3;

    cout << "s1 is \" " << s1 << " \"; s2 is \" " << s2 << " \";s3 is \" " << s3 << '\"';
    cout << "\nThe results of comparing s2 and s1: " << " s2 == s1 yields "
         << ( s2 == s1 ? "true" : "false" )
         << " s2 != s1 yields "
         << ( s2 != s1 ? "true" : "false" )
         << " s2 > s1 yields "
         << ( s2 > s1 ? "true" : "false" )
         << " s2 < s1 yields "
         << ( s2 < s1 ? "true" : "false" )
         << " s2 >= s1 yields "
         << ( s2 >= s1 ? "true" : "false" )
         << " s2 <= s1 yields "
         << ( s2 <= s1 ? "true" : "false" );

    cout << "\n\nTesting!!! s3 = : ";
    if( !s3 )  {
        cout << "s3 is empty:assigning s1 to s3: \n";
        s3 = s1;
        cout << "s3 is \" " << s3 << " \" ";
    }

    cout << "\n\ns1 += \" to you \" yields\n";
    s1 += " to you ";
    cout << "s1 = " << s1 << "\n\n";

    cout << "The substring of s1 startint at \n"
         << "location 15, s1(15, 0),is : "
         << s1( 15, 0 ) << "\n\n";

    String *s4Ptr = new String( s1 );
    cout << "* s4Ptr = " << * s4Ptr << "\n\n";


    cout << "assignment *s4Ptr = *s4Ptr \n";
    * s4Ptr = * s4Ptr;
    cout << "* s4Ptr = " << s4Ptr << '\n';

    delete s4Ptr;


    s1[ 0 ] = 'H';
    s1[ 6 ] = 'B';
    cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' is : " << s1 << "\n\n";

    cout << "Attempt to assign 'd' to s1[30] yields: " << endl;
    s1[30];

    return 0;
}
