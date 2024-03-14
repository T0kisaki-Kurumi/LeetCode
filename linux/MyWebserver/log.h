#ifndef LOG_H
#define LOG_H

#include <iostream>
#include "blockqueue.h"
#include <cstring>
#include "locker.h"
#include <stdarg.h>

class Log{
private:
    Log();
    ~Log();
    void* async_write_log();  // 异步写日志方法，把一条日志从队列中取出并写入日志文件中

private:
    char dir_name[128];  //路径名
    char log_name[128];  //日志文件名
    int m_split_lines;   //日志最大行数
    int m_log_buf_size;  //日志缓存区大小
    long long m_count;   //当天所有日志的总行数记录（新的一天清零），如果当前日志行数超过最大行数就要新建一个日志
    int m_today;         //当前日期
    FILE* m_fp;          //日志文件指针
    char* m_buf;         //要输出的内容
    BlockQueue<std::string>* m_log_queue;  //阻塞队列
    bool m_is_async;     //是否同步
    Locker m_mutex;      //写日志时候的锁

public:
    // 单例模式，获取日志对象
    static Log* get_instance(){
        static Log instance;
        return &instance;
    }

    // 初始化，包括日志文件、缓冲区大小、日志最大行数、阻塞队列最大容量
    bool init(
        const char* file_name,
        int log_buf_size = 8129,
        int split_lines = 50000,
        int max_queue_size = 0
    );

    // 异步写日志公有方法，调用私有方法
    static void* flush_log_thread(void* arg){
        get_instance()->async_write_log();
    }

    // 将输出内容按照标准格式整理?
    void write_log(int level, const char* format, ...);

    // 强制刷新缓冲区
    void flush();
};

#define LOG_DEBUG(format, ...) if(0 == m_close_log) {Log::get_instance()->write_log(0, format, ##__VA_ARGS); Log::get_instance()->flush();}
#define LOG_INFO(format, ...) if(0 == m_close_log) {Log::get_instance()->write_log(1, format, ##__VA_ARGS); Log::get_instance()->flush();}
#define LOG_WARN(format, ...) if(0 == m_close_log) {Log::get_instance()->write_log(2, format, ##__VA_ARGS); Log::get_instance()->flush();}
#define LOG_ERROR(format, ...) if(0 == m_close_log) {Log::get_instance()->write_log(3, format, ##__VA_ARGS); Log::get_instance()->flush();}


#endif