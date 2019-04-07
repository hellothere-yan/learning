class Singleton
{
private:
    Singleton();
    Singleton(const Singleton&);
    static Singleton * p;
public:
    Singleton * instance();
}
Singleton::Singleton(){}
Singleton::Singleton(const Singleton&){}//复制构造函数
Singleton *Singleton::p=new Singleton;
Singleton *Singleton::instance()
{
    return p;
}

/*注意：
1）饿汉模式，顾名思义，需要提前喂食，也即是提前加载。采用静态初始化的方式，提前加载实例化对象，但是由于提前加载，也就提前占用了系统资源，导致内存开销大。

2）此处没有加锁为什么也是线程安全的？因为程序在刚加载的时候就创建了实例，并且返回他，以后如果再次运行到这里，返回的就是之前加载时创建的实例，所以不会导致多线程安全问题。

3)类指针要声明为静态的，否则不可以在类外进行赋值操作。
*/