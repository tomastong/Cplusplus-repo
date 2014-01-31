/*=============================Program Description==========================
程序名称：类的组合.cpp
程序要求：格式如下：
            请输入年  月  日  2012 5 10
            请输入时  分  秒  8 12 12
            请输入事件安排的编号  年  月  日  时  分  秒
                8 2012 5 16 23 59 59
            c++作业开始于:  2012年5月10日8时12分12秒
            C++作业截止于:  Lab8  2012年5月16日  23时59分59秒
Written By Dong-Hong-Yan(2012-5-12)
============================================================================*/

#include<iostream>
#include<string>
using namespace std;

class Period  {
    public:
        Period()  {}
        Period( int year, int month, int day ) {
            this->year = year;
            this->month = month;
            this->day = day;
        }
        ~Period()  {}
        void Input()  {

            cin >> year >> month >> day;
        }
        int GetYear()  {return year;}
        int GetMonth()  {return month;}
        int GetDay()  {return day;}
    private:
        int year;
        int month;
        int day;
};

class Time  {
    public:
        Time()  {}
        Time( int hour, int minute, int second ) {
            this->hour = hour;
            this->minute = minute;
            this->second = second;
        }
        ~Time()  {}
        void Input()  {

            cin >> hour >> minute >> second;
        }
        int GetHour()  {return hour;}
        int GetMinute()  {return minute;}
        int GetSecond()  {return second;}
    private:
        int hour;
        int minute;
        int second;
};

class Major  {
    public:
        Major()  {}
        Major( Period period, Time time )  {
            this->period = period;
            this->time = time;
        }
        void Input()  {
            cout << "请输入年  月  日" << endl;
            period.Input();

            year_1 = period.GetYear();
            month_1 = period.GetMonth();
            day_1 = period.GetDay();

            cout << "请输入时  分  秒" << endl;
            time.Input();

            hour_1 = time.GetHour();
            minute_1 = time.GetMinute();
            second_1 = time.GetSecond();

            cout << "请输入事件安排的编号  年  月  日  时  分  秒" << endl;
            cin >> num;period.Input();time.Input();
        }
        void Output()  {
            cout << "\n\nc++作业开始于:  " << year_1 << "年"
                 << month_1 << "月" << day_1 << "日"
                 << hour_1 << "时" << minute_1 << "分"
                 << second_1 << "秒" <<endl;
            cout << "C++作业截止于:  Lab" << num << "  "
                 << period.GetYear() << "年" << period.GetMonth() << "月"
                 << period.GetDay() << "日  " << time.GetHour() << "时"
                 << time.GetMinute() << "分" << time.GetSecond() << "秒" <<endl;    ;
        }
    private:
        int num;

        int year_1, month_1, day_1;
        int hour_1, minute_1, second_1;

        Period period;
        Time time;
};
int main()  {
   Major major;

   major.Input();
   major.Output();

   return 0;
}
