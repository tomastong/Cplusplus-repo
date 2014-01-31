typedef double Stack_entry;
#include"stack"
#include<iostream>
using namespace std;

/*
* * *用户命令
   为了实现get_command,我们决定用字符？，=，+，-，*和/表示用户能键入的命令，此处？
   要求用户输入数值，=输出操作结果，剩余的符号分别表示加减乘除。*/

char get_command()  {
char command;
bool waitting = true;
cout << "Select command and press<enter>:";
while(waitting)  {
command = tolower(command);
if(command == '?' || command == '=' || command == '+' || command == '-'
   || command == '*' || command == '/' || command == 'q')
   waitting = false;
else {
    cout << "Please enter a valid(有效) command:" << endl
         << "[?]push to stack=[=]print top" << endl
         << "[+] [-] [*] [/] are arithmetic operations " << endl
         << "[Q]uit." << endl;
    }
}
    return command;
}

/*
* * *执行用户命令
    最后，选择和执行用户命令的工作是函数do_command的任务，这里我们给出了
    do_command函数的简要形式，其中仅仅在它的主要选择语句里编码了一些可能的命令*/

bool do_command(char command, Stack_entry &numbers) {
    /*Pre:The first parameter（参数） specifies（指定） a valid calculator（计算器）
          command.
      Post:The command  specifies by the first parameter has been applied to the
          Stack of numbers given by the second parameter.A result of true is
          returned unless command == 'q'.
      Uses:The class Stack.*/


        double p, q;
        switch(command)  {
        case '?':
            cout << "Enter a real number: "<< flush;
            cin >> p;
            if(numbers.push(p) == overflow)
                cout << "Warning:Stack full, lost" << endl;
            break;
        case '=':
            if(numbers.top(p) == underflow)
                cout << "Stack empty" << endl;
            else
                cout << p << endl;
                break;
        case '+':
            if(numbers.top.(p) == underflow)
                cout << "Stack empty" <<endl;
            else  {
                numbers.pop();
                if(numbers.top(q) == underflow) {
                    cout << "Stack has just one empty." << endl;
                    numbers.push(p);
                }
                else  {
                    numbers.pop();
                    if(numbers.push(p + q) == overflow)
                    cout << "Warning :Stack full, lost result!" << endl;
                }
            }
                break;
        //Add options for further user commands.
        case 'q':
            cout << "Calculation finished.\n";
            return false;
        }
        return true;

    }

//【主程序】
int main()  {
    /*Post:The program has executed(执行) simple arithmetic(算术) commands emtered by the user.
      Uses:The class Stack and the functions introduction,instructions,do_command
      and ,andget command.*/

Stack_entry stored_numbers;
//introduction();
//instructions();

while(do_command(get_command(), stored_numbers));

return 0;
}

