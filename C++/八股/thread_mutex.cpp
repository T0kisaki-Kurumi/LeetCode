#include <iostream>
#include <thread> //包含std::thread类以及std::this_thread命名空间。管理线程的函数和类在该头文件中有声明；
#include <mutex> //包含了与互斥量相关的类以及其他类型的函数；
#include <condition_variable> //包含与条件变量相关的类，包括std::condition_variable和std::condition_variable_any
#include <atomic> //包含std::atomic和std::atomic_flag类，以及一套C风格的原子类型和与C兼容的原子操作的函数；
#include <future> //包含两个Provider类（std::promise和std::package_task）和两个Future类（std::future和std::shared_future）以及相关的类型和函数；
#include <vector>

using namespace std;

// mutex
void test1(){
	vector<int> arr;
    mutex mtx;
	thread t1([&] {
		for (int i = 0; i < 100; i++) {
            mtx.lock();
			arr.push_back(1);
            mtx.unlock();
		}
	});
	thread t2([&] {
		for (int i = 0; i < 100; i++) {
            mtx.lock();
			arr.push_back(2);
            mtx.unlock();
		}
	});
	t1.join();
	t2.join();
    for(int i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

// lock_guard
void test2(){
    vector<int> arr;
    mutex mtx;
    thread t1([&](){
        for(int i=0; i<100; ++i){
            lock_guard<mutex> grd(mtx); //lock_guard 严格在析构时 unlock()，而不能提前释放
            arr.push_back(1);
        }
    });
    thread t2([&](){
        for(int i=0; i<100; ++i){
            lock_guard<mutex> grd(mtx);
            arr.push_back(2);
        }
    });
    t1.join();
    t2.join();
    for(int i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

// unique_lock 可以提前解锁，因为额外存储了一个 flag 表示是否已经被释放，会在析构检测这个 flag，如果没有释放，则调用 unlock()，否则不调用
void test3(){
    vector<int> arr;
    mutex mtx;
    thread t1([&](){
        for(int i=0; i<10; ++i){
            unique_lock<mutex> grd(mtx);
            arr.push_back(1);
        }
    });
    thread t2([&](){
        for(int i=0; i<10; ++i){
            unique_lock<mutex> grd(mtx);
            arr.push_back(2);
            grd.unlock();
            // grd.lock();  // 如果需要还可以再次上锁，但是已有锁的情况下再上锁会出错
        }
    });
    thread t3([&](){
        for(int i=0; i<10; ++i){
            unique_lock<mutex> grd(mtx, defer_lock); // 传入defer_lock后，需要手动调用 grd.lock() 才能上锁
            grd.lock();
            arr.push_back(3);
            grd.unlock();
        }
    });
    t1.join();
    t2.join();
    t3.join();
    for(int i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

// 多个对象时lock_guard的写法，可以加{}控制互斥量的解锁时机
void test4(){
    vector<int> arr1;
    mutex mtx1;
    vector<int> arr2;
    mutex mtx2;
    thread t1([&]{
        {
            for(int i=0; i<10; ++i){
                lock_guard<mutex> grd(mtx1);
                arr1.push_back(1);
            }
        }
        {
            for(int i=0; i<10; ++i){
                lock_guard<mutex> grd(mtx2);
                arr2.push_back(3);
            }
        }
    });
    thread t2([&]{
        {
            for(int i=0; i<10; ++i){
                lock_guard<mutex> grd(mtx1);
                arr1.push_back(2);
            }
        }
        {
            for(int i=0; i<10; ++i){
                lock_guard<mutex> grd(mtx2);
                arr2.push_back(4);
            }
        }
    });
    t1.join();
    t2.join();
    for(int i: arr1){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i: arr2){
        cout<<i<<" ";
    }
    cout<<endl;
}

// try_lock
void test5(){
    mutex mtx;
    if (mtx.try_lock())
        printf("succeed\n");
    else
        printf("failed\n");

    if (mtx.try_lock())
        printf("succeed\n");
    else
        printf("failed\n");

    mtx.unlock();
}

// 死锁
void test6(){
    mutex mtx1;
    mutex mtx2;
    thread t1([&]{
        mtx1.lock();
        cout<<"t1获得mtx1"<<endl;
        this_thread::sleep_for(chrono::seconds(1));
        mtx2.lock();
        cout<<"t1获得mtx2"<<endl;
    });
    thread t2([&]{
        mtx2.lock();
        cout<<"t2获得mtx2"<<endl;
        this_thread::sleep_for(chrono::seconds(1));
        mtx1.lock();
        cout<<"t2获得mtx1"<<endl;
    });
    t1.join();
    t2.join();
};

// 死锁2
void test7(){
    mutex mtx1;
    mutex mtx2;
    thread t1([&]{
        for(int i=0; i<100; ++i){
            cout<<"t1: "<<i<<endl;
            mtx1.lock();
            cout<<"t1获得mtx1"<<endl;
            mtx2.lock();
            cout<<"t1获得mtx2"<<endl;
            mtx2.unlock();
            cout<<"t1释放mtx2"<<endl;
            mtx1.unlock();
            cout<<"t1释放mtx1"<<endl;
        }
    });
    thread t2([&]{
        for(int i=0; i<100; ++i){
            cout<<"t2: "<<i<<endl;
            mtx2.lock();
            cout<<"t2获得mtx2"<<endl;
            mtx1.lock();
            cout<<"t2获得mtx1"<<endl;
            mtx1.unlock();
            cout<<"t2释放mtx1"<<endl;
            mtx2.unlock();
            cout<<"t2释放mtx2"<<endl;
        }
    });
    t1.join();
    t2.join();
};

// 解决死锁1
void test8(){
    mutex mtx1;
    mutex mtx2;
    thread t1([&]{
        for(int i=0; i<100; ++i){
            cout<<"t1: "<<i<<endl;
            mtx1.lock();
            cout<<"t1获得mtx1"<<endl;
            mtx2.lock();
            cout<<"t1获得mtx2"<<endl;
            mtx2.unlock();
            cout<<"t1释放mtx2"<<endl;
            mtx1.unlock();
            cout<<"t1释放mtx1"<<endl;
        }
    });
    thread t2([&]{
        for(int i=0; i<100; ++i){
            cout<<"t2: "<<i<<endl;
            mtx1.lock();
            cout<<"t2获得mtx1"<<endl;
            mtx2.lock();
            cout<<"t2获得mtx2"<<endl;
            mtx2.unlock();
            cout<<"t2释放mtx2"<<endl;
            mtx1.unlock();
            cout<<"t2释放mtx1"<<endl;
        }
    });
    t1.join();
    t2.join();
}

int main(){
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    test8();

    system("pause");
    return 0;
}