class Singleton
{
protected:
    Singleton()
    {
        pthread_mutex_init(&mutex);
    }
public:
    static Singleton *instance();
    static pthread_mutex_t mutex;
}
pthread_mutex_t Singleton::mutex;
Singleton *Singleton::instance()
{
    pthread_mutex_lock(&mutex);
    static Singleton obj;
    pthread_mutex_unlock(&mutex);
    return &obj;
}

/*这里简单介绍一下静态变量：

         当我们每创建一个类对象，类成员变量就会多出一份，各个对象间的成员变量不能共享，是各自独立的变量。但是，我们有些时候需要定义一个成员变量，使其在各个类对象之间关联起来。也就是说这个变量是所有的类共有，这就是静态变量。静态变量的特性和全局变量特性相同，生命周期为程序运行期，不依赖于任何实例的对象。

引申静态成员函数：

静态成员函数属于整个类所有，因为静态成员函数并不属于某个对象，所以我们可以通过类名来直接访问公有静态成员函数。也可以通过对象名访问公有成员函数。
*/