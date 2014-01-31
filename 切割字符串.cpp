#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string  str;
    cout << "请输入一段字符串：";
    getline(cin, str, '\n');

    char *p;
    char * buffer = &str[0];
    char *delims  = " ";
    p = strtok(buffer, delims);                     //这里调用切割字符串函数char *strtok(char *s, char * delims)
                                                    //前面为母串，后面为切割的界限，p为返回值，最后要制空
    while(p != NULL)
    {
        cout << p << endl;
        p = strtok(NULL, delims);
    }
    /*string  x, y, z;
    int     i = 0;

    cin >>  str;
        while(str[i++] != ' ')
            x += str[i];
        while(str[i++] == ' ')
            continue;
        while(str[i++] != ' ')
            y += str[i];
        while(str[i++] != ' ')
            continue;
        while(str[i++] != ' ')
            z += str[i];
        while(str[i++] == '\0')
            break;

        cout << x << endl
             << y << endl
             << z << endl;*/

    return 0;
}
