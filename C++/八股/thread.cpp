#include <iostream>
#include <thread> //包含std::thread类以及std::this_thread命名空间。管理线程的函数和类在该头文件中有声明；
#include <mutex> //包含了与互斥量相关的类以及其他类型的函数；
#include <condition_variable> //包含与条件变量相关的类，包括std::condition_variable和std::condition_variable_any
#include <atomic> //包含std::atomic和std::atomic_flag类，以及一套C风格的原子类型和与C兼容的原子操作的函数；
#include <future> //包含两个Provider类（std::promise和std::package_task）和两个Future类（std::future和std::shared_future）以及相关的类型和函数；
#include <vector>

using namespace std;

thread_local int i;

// 创建thread
void test1(){
    auto func = [&](int x){
        i = x;
        ++i;
        this_thread::sleep_for(chrono::seconds(1));
        cout<<this_thread::get_id()<<" : "<<i<<endl;
    };
    i = 9;
    thread t1(func, 1);
    thread t2(func, 2);
    thread t3(func, 3);
    cout<<this_thread::get_id()<<" : "<<i<<endl;
    t1.join();
    t2.join();
    t3.join();
}

// steady_clock  system_clock  high_resolution_clock
void test2(){
    auto t3 = chrono::steady_clock::now();
    this_thread::sleep_for(chrono::seconds(1));
    auto t4 = chrono::steady_clock::now();
    auto diff_st = t4 - t3;
    auto us2 = chrono::duration_cast<chrono::microseconds>(diff_st).count();
    cout<<us2<<endl;

    auto t1 = chrono::high_resolution_clock::now();  //高精度的steady_clock
    this_thread::sleep_for(chrono::seconds(1));
    auto t2 = chrono::high_resolution_clock::now();
    auto diff_hr = t2 - t1;
    auto us1 = chrono::duration_cast<chrono::microseconds>(diff_hr).count();
    cout<<us1<<endl;
}

// yield函数
void test3(){
    auto func = [](){
        for(int i=0; i<10000; ++i){
            this_thread::yield();  // 主动由运行态退让出已经抢到的时间片，并转为就绪态(Ready)。但会马上参与到下一轮 CPU 的抢夺中
            cout<<this_thread::get_id()<<" : "<<i<<endl;
        }
    };
    thread t1(func);
    thread t2(func);
    t1.join();
    t2.join();
}

// join函数
void test4(){
    auto download = [](string file) {
        for (int i = 0; i < 10; i++) {
            cout << "Downloading " << file << " (" << i * 10 << "%)..." << endl;
            this_thread::sleep_for(chrono::milliseconds(400));
        }
        cout << "Download complete: " << file << endl;
    };
    thread t1(download, "test.txt");
    auto print = [](){
        string name;
        cout<<"enter a str: ";
        cin>>name;
        cout<<"Hi, "<<name<<endl;
    };
    print();

    cout<<"等待子线程结束"<<endl;
    t1.join();
    cout<<"子线程已结束"<<endl;
}

// detach函数
void test5(){
    auto download = [](string file) {
        for (int i = 0; i < 10; i++) {
            cout << "Downloading " << file << " (" << i * 10 << "%)..." << endl;
            this_thread::sleep_for(chrono::milliseconds(400));
        }
        cout << "Download complete: " << file << endl;
    };

    thread t1(download, "hello.zip");
    t1.detach();  // 虽然detach了，但是当进程结束时还是会直接退出，本质原因是没有调用join函数
}

// 线程池
// thread类的构造函数：
// 默认构造函数 		thread() noexcept;
// 初始化构造函数 	template <class Fn, class... Args>
// explicit thread(Fn&& fn, Args&&... args);
// 拷贝构造函数 [deleted] 	thread(const thread&) = delete;
// Move 构造函数 	thread(thread&& x) noexcept;
class ThreadPool{
private:
    vector<thread> m_pool;
public:
    void push(thread t){
        m_pool.push_back(move(t));
    }
    ~ThreadPool(){
        for(thread& t: m_pool){
            t.join();
        }
    }
};

void test6(){
    auto download = [](string file) {
        for (int i = 0; i < 10; i++) {
            cout << "Downloading " << file << " (" << i * 10 << "%)..." << endl;
            this_thread::sleep_for(chrono::milliseconds(400));
        }
        cout << "Download complete: " << file << endl;
    };
    ThreadPool pool;
    thread t(download, "hello.zip");
    pool.push(move(t));
}

// joinable函数
void test7(){
    cout<<boolalpha;
    thread t1;
    cout<<t1.joinable()<<endl;  // false，默认构造不能join
    thread t2([](){});
    cout<<t2.joinable()<<endl;  // true
    thread t3(move(t2));
    cout<<t2.joinable()<<endl;  // false，move后原线程不能join
    cout<<t3.joinable()<<endl;  // true，move后新线程可以join
    t3.join();
    cout<<t3.joinable()<<endl;  // false，已经join或detach的线程不能再次join
}

int main(){
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    test7();

    system("pause");
    return 0;
}