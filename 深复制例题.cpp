/*=============================Program Description======================================
程序名称：深复制例题.cpp
程序目的：通过例题了解为何需要深复制，以及对象的深复制!
Written By Dong-Hong-Yan(2012-6-13)
========================================================================================*/

#include<iostream>
#include<cassert>           //文件包含

using namespace std;      //命名空间

//定义Point类
class Point {
    public:                   //外部接口
        Point() :x(x), y(y) {                                 //无参的构造函数
            cout << "Default constructor called!." << endl;
        }
        Point(int x, int y) :x(x), y(y) {                     //有参的构造函数
            cout << "Constructor called!." << endl;
        }
        ~Point() {cout << "Destructor called!." <<endl;}   //调用析构函数
        int getX() const {return x;}
        int getY() const {return y;}
        void move(int newX, int newY)  {        //移动函数
            x = newX;
            y = newY;
        }
    private:                       //私有数据成员
        int x, y;
};

//定义动态数组类
class ArrayOfPoints {
    public:
        ArrayOfPoints(const ArrayOfPoints &v);           // 深复制与前复制的异同点
        ArrayOfPoints(int size) :size(size) {
            points = new Point[size];
        }
        ~ArrayOfPoints() {
            cout << "Deleting..." << endl;
            delete [] points;
        }
        Point &element(int index) {         //返回动态申请数组的index元素
            assert(index >= 0 && index < size);
            return points[index];
        }
    private:
        Point * points;
        int size;
};

//深复制函数的定义，对象也复制，两者没有什么关系
ArrayOfPoints::ArrayOfPoints(const ArrayOfPoints &v) {
    size = v.size;
    points = new Point[size];
    for(int i = 0; i <size; i++) {
        points[i] = v.points[i];
    }
}

//【主函数】
int main() {
    int count;
    cout << "Please enter the count of points: ";
    cin >> count;
    ArrayOfPoints pointsArray1(count);
    pointsArray1.element(0).move(5, 10);
    pointsArray1.element(1).move(15, 20);

    ArrayOfPoints pointsArray2 = pointsArray1;
         //这里用到的是深复制，对象也复制
    //而不是两个名字指向同一块内存，分别独立的

    cout << "Copy of pointsArray1: " << endl;
    cout << "Point_0 of array2: " << pointsArray2.element(0).getX() << ","
         << pointsArray2.element(0).getY() << endl;
    cout << "Point_1 of array2: " << pointsArray2.element(1).getX() << ","
         << pointsArray2.element(1).getY() << endl;

    pointsArray1.element(0).move(25, 30);         //这里移动pointArray1的值
    pointsArray1.element(1).move(35, 40);         //却不改变pointArray2的值，则两者无必然联系

    cout << "After the moving of pointsArray1: " << endl;
    cout << "Point_0 of array2 : " << pointsArray2.element(0).getX() << ","
         << pointsArray2.element(0).getY() << endl;
    cout << "Point_1 of array2 : " << pointsArray2.element(1).getX() << ","
         << pointsArray2.element(1).getY() << endl;

    return 0;
}
