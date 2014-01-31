#ifnedf _ACCUMULATOR_H
#define _ACCUMULATOR_H

#include"date.h"

class Accumulator {            //将某个数值按日累加
    private:
        Date lastDate;            //上次变更数值的日期
        double value;             //数值的当前值
        double sum;               //数值按日累加之和
    public:
        //构造函数date为开始累加的日期， value为初始值
        Accumulator(const Date &date, double value)
            :lastDate(Date), value(value), sum(0) {}

        //获得日期的累加结果
        double getSum(const Date &date) const {
            return sum + value * date.distance(lastDate);
        }
        double getSum(const Date &date) {
            return sum + value * (date - lastDate);
        }

        //在date将数值变为value
        void change(const Date &date, double value) {
            sum = getSum(date);
            lastDate = date;
            this->value = value;
        }

        //初始化，将日期变为date,数值变为value，累加器清零
        void reset(const Date &date, double value) {
            lastDate = date;
            this->value = value;
        }
};

#endif                              //_ACCUMULATOR_H
