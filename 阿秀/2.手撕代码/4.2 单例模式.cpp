// 线程安全的懒汉模式
class Singleton {
public:
    static Singleton& getInstance();
 
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
 
private:
    Singleton();
};

//第一次调用时候，创建实例对象
Singleton& Singleton::getInstance() {
    static Singleton instance;
    return instance;
}
Singleton::Singleton() {
    // 构造函数
}

// 常规加锁的懒汉模式
class Singleton {
public:
    // 获取单例实例的静态方法
    static Singleton* getInstance();
    // 删除拷贝构造函数和赋值运算符重载，确保单例的唯一性
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
private:
    // 私有构造函数，防止外部实例化
    Singleton();
 
    static Singleton* instance; // 单例实例指针
    static std::mutex mutex;    // 互斥锁
};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mutex;
 
Singleton::Singleton() {
    // 构造函数
}
Singleton* Singleton::getInstance() {
    if (instance == nullptr) {
        std::lock_guard<std::mutex> lock(mutex); // 加锁
 
        if (instance == nullptr) {
            instance = new Singleton();
        }
    }
    return instance;
}


// 饿汉模式
class Singleton {
public:
    static Singleton* getInstance();
private:
    Singleton();
    ~Singleton();
    Singleton(const Singleton &signal);
    const Singleton &operator=(const Singleton &signal);
private:
    // 唯一的单例对象
    static Singleton *instance_;
};