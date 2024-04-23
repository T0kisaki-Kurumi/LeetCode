#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
 
std::queue<int> buffer;            // 共享的缓冲区，用于生产者和消费者之间的数据传递
std::mutex mtx;                    // 互斥锁，用于保护对缓冲区的并发访问
std::condition_variable cv;        // 条件变量，用于通知消费者新数据的可用性
 
// 生产者函数
void producer() {
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));  // 模拟生产延迟
        int data = i;  // 生产数据
        {
            std::unique_lock<std::mutex> lock(mtx);  // 获取互斥锁
            buffer.push(data);  // 将数据放入缓冲区
        }
        cv.notify_one();  // 通知等待的消费者数据已准备好
    }
}
 
// 消费者函数
void consumer() {
    for (int i = 0; i < 10; ++i) {
        int data;
        {
            std::unique_lock<std::mutex> lock(mtx);  // 获取互斥锁
            cv.wait(lock, [] { return !buffer.empty(); });  // 等待数据可用
            data = buffer.front();  // 从缓冲区中取出数据
            buffer.pop();  // 从缓冲区中移除数据
        }
        std::cout << "Consumed: " << data << std::endl;  // 处理数据
    }
}
 
int main() {
    std::thread producerThread(producer);  // 创建生产者线程
    std::thread consumerThread(consumer);  // 创建消费者线程
    
    producerThread.join();  // 等待生产者线程结束
    consumerThread.join();  // 等待消费者线程结束
    
    return 0;
}