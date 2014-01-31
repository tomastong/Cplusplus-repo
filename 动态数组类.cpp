/*=============================Program Description===================================
程序名称;动态数组类.cpp
程序目的：用动态申请内存的方法，来申请类数组
written By Dong-Hong-Yan(2012-4-19)
=====================================================================================*/

#include<iostream>
#include<cassert>
using namespace std;

//【Point类】
class Point {
    public:
        Point(int x = 0, int y = 0) :x(x), y(y)  {}
        int getX() const  {return x;}
        int getY() const  {return y;}
        void move(int newX, int newY)  {
            x = newX;
            y = newY;
        }
    private:
        int x, y;
};

class ArrayOfPoints  {
    public:
        ArrayOfPoints(int size) :size(size)  {
            points = new Point[size];
        }
        ~ArrayOfPoints()  {
            cout << "Deleting..." <<endl;
            delete [] points;     //删除动态创建的对象数组，在中间加[]符号
        }

        //获得下标为index的数组元素
        Point &element(int index)  {       //如果数组下标越界，程序终止
            assert(index >= 0 && index < size);
            return points[index];
        }
    private:
        Point * points; //指向动态数组首地址
        int size;       //数组大小

};

//【主程序】
int main()  {
    int count;

    cout << "Please enter the count of points: ";
    cin >> count;

    ArrayOfPoints points(count);          //创建对象数组

    points.element(0).move(5, 0);         //访问数组元素的成员
    points.element(1).move(15, 20);       //访问数组元素的成员
    points.element(5).move(5, 0);         //如果输入的是小于5，则数组下标越界，程序终止

    return 0;
}
