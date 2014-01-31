/*-------------Program Description------------
程序名称：Dice_game.cpp
程序目的：每轮两次，第一轮和为7、11胜，结束！和为
2、3、12负，结束！和为其他，作为自己点数，直到新一轮的和
等于第一轮的点数，胜，若出现7，负！
Written By Dong-Hong Yan(WANT Studio)
----------------------------------------------*/


#include<iostream>
//在c++中，这里用到随机函数，用头文件stdlib，一般在前加一个c，当然math也是
#include<cstdlib>
#include<cTime>
using namespace std;

//投色子，计算和数，输出和数
int rollDice()  {
	int die1=1+rand()%6;
	int die2=1+rand()%6;
	int sum=die1+die2;
	cout<<"player rolled "<<die1<<"+"<<die2<<"="<<sum<<endl;
	return sum;
}

//定义枚举类型
enum GameStatus{WIN,LOSE,PLAYER};

//主程序
int main()  {
	int sum,myPoint;
	GameStatus status;

	unsigned seed;
	cout<<"Please enter an unsigned integer:";

	//输入随机数种子
	//cin>>seed;

	//将种子通过系统函数传给rand()，这时去掉cin>>seed,添加#include<cTime>,直接
	//写一个srand((unsigned)time(NULL)); 即可，系统随机分配，不用操作
	//srand(rand());
    srand((unsigned)time(NULL));
	sum=rollDice();  //第一轮投色子，计算和数
	switch(sum)  {

	//如果和为7或11，状态为WIN
	case 7:
	case 11:
		status=WIN;
		break;

	//如果和为2、3、12为负，状态为LOSE
	case 2:
	case 3:
	case 12:
		status=LOSE;
		break;

		//其它情况，游戏尚无结果，状态为PLAYER，记下点数，为下一轮做准备
	default:
		status=PLAYER; //status是状态意思
		myPoint=sum;
		cout<<"Point is "<<myPoint<<endl;
		break;
	}

	while(status==PLAYER)  {
		sum=rollDice();
		if(sum==myPoint)
			status=WIN;
		else if(sum==7)
			status=LOSE;
	}


	if(status==WIN)
		cout<<"player wins"<<endl;
	else
		cout<<"Player loses"<<endl;

	return 0;
}
