//_H_TRAPZINT

//抽象类Function的定义
class Function  {
    public:
        virtual double operator () ( double x ) const = 0;
        virtual ~Function() {}
};

//公有派生类Myfunction的定义
class Myfunction : public Function  {
    public:
        virtual double operator () ( double x ) const;   //覆盖虚函数
};

//抽象类Integration的定义
class Integration  {
    public:
        virtual double operator () ( double a, double b, double eps ) const = 0;
        virtual ~Integration() {}
};

//公有派生类Trapz的定义
class Trapz : public Integration  {
    public:
        Trapz( const Function &f ) : f(f) {}   //构造函数
        virtual double operator () ( double a, double b, double eps ) const;
    private:
         //私有成员Function类对象指针，不改变指针指向的对象，则定义为常指针
        const Function &f;
};

//如果在头文件声明为虚函数，则在定义时，不必再写
//如果该函数执行后，不改变当前对象的值，则该函数可声明为常函数

