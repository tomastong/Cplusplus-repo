#include<iostream>
using namespace std;

//【Boat类】定义 
class Boat {
      public:                    //外部接口 
             Boat(int weight = 0, int height = 0) :weight(weight), height(height)  {}         //构造函数 
             Boat(Boat &p);
			 int GetWeight()  {                         //返回重量函数 
			 return weight;
			 }
             friend  int GetTotalWeight();             //友元函数的声明 
      private:                  //私有数据 
              int weight;       // 定义Boat类属性重量 
              int height;       //定义Boat类属性高度 
              
      };                       //不可忘记分号 
 
 //定义Boat类复制构造函数     
Boat::Boat(Boat &p)  {
                weight = p.weight;
                height = p.height;
                }
//【Car类】 
class Car  {
      public:                                       //外部接口 
             Car(int weight = 0, int width = 0) :weight(weight), width(width) {}
             Car(Car &p); 
			 int GetWeight()  {                  //返回属性重量 
			 return weight;
			 }
             friend int GetTotalWeight();           //友元函数声明 
      private:                                       //私有数据 
              int weight;                //定义Car类属性重量 
              int width;                 //定义Car类属性宽度 
      };                //不可忘记分号 
      
//定义Car类复制构造函数 
 Car::Car(Car &p)  {
              weight = p.weight;
              width = p.width;
              }
    
 //定义友元函数，参数为类对象             
 int GetTotalWeight(Boat &p1, Car &p2)  {
     int x=p1.GetWeight()+p2.GetWeight();
     return x;
     }

//【主程序】 
int main()  {
    int total;                  //定义total接收友元函数返回值 
    Boat boat(50, 30);          //定义并初始化boat 
    Car car(40, 20);            //定义并初始化car 
    total = GetTotalWeight(boat, car);
    cout<<"The total weight is : "<<total<<endl;
    system("pause");
    return 0;
    } 
