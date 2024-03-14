#include "log.h"

Log::Log(){
    m_count = 0;
    m_is_async = false; // 初始为同步写
}

Log::~Log(){
    if(m_fp != nullptr){
        fflush(m_fp);
        fclose(m_fp);
    }
    m_fp = nullptr;  //防止悬垂指针
}

bool Log::init(const char* file_name, int log_buf_size, int split_lines, int max_queue_size){
    // 异步日志
    if(max_queue_size >= 1){
        m_is_async = true;
        m_log_queue = new BlockQueue<std::string>(max_queue_size);

        // 创建子线程
        pthread_t pid;
        pthread_create(&pid, nullptr, flush_log_thread, nullptr);
    }

    // 初始化写入内容
    m_log_buf_size = log_buf_size;
    m_buf = new char[m_log_buf_size];

    // 初始化日志最大行数
    m_split_lines = split_lines;

    time_t t = time(nullptr); //系统时
    // struct tm {
    //     int tm_sec;       /* 秒 – 取值区间为[0,59] */
    //     int tm_min;       /* 分 - 取值区间为[0,59] */
    //     int tm_hour;      /* 时 - 取值区间为[0,23] */
    //     int tm_mday;      /* 一个月中的日期 - 取值区间为[1,31] */
    //     int tm_mon;       /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */
    //     int tm_year;      /* 年份，其值等于实际年份减去1900 */
    //     int tm_wday;      /* 星期 – 取值区间为[0,6]，其中0代表星期天，1代表星期一，以此类推 */
    //     int tm_yday;      /* 从每年的1月1日开始的天数 – 取值区间为[0,365]，其中0代表1月1日，1代表1月2日，以此类推 */
    //     int tm_isdst;     /* 夏令时标识符，实行夏令时的时候，tm_isdst为正。不实行夏令时的进候，tm_isdst为0；不了解情况时，tm_isdst()为负。*/
    // };
    struct tm* sys_tm = localtime(&t); //localtime将系统时转化为真实时间
    struct tm my_tm = *sys_tm;  //先赋值给一个临时指针sys_tm， 再赋值给my_tm，保证多线程安全

    // 从后往前找到第一个'/'
    const char* p = strrchr(file_name, '/');
    char full_file_name[512] = {0};

    // 没有找到'/'，即相对路径
    if(nullptr == p){
        // 只写入日志文件名，不写入路径名
        strcpy(log_name, file_name);
        snprintf(
            full_file_name,
            511,
            "%d_%02d_%02d_%s",
            my_tm.tm_year + 1900,  // 年份二位数，默认是19xx年
            my_tm.tm_mon + 1,  //月份是0-11，所以要+1
            my_tm.tm_mday,  //日期是正确的
            log_name
        );
    }
    //绝对路径
    else{
        // 文件名和路径名都写入
        strncpy(log_name, p+1, strlen(p+1));
        strncpy(dir_name, file_name, p-file_name+1); //+1是为了把'/'也保存进路径名？
        snprintf(
            full_file_name,
            511,
            "%s%d_%02d_%02d_%s",
            dir_name,
            my_tm.tm_year + 1900,  // 年份二位数，默认是19xx年
            my_tm.tm_mon + 1,  //月份是0-11，所以要+1
            my_tm.tm_mday,  //日期是正确的
            log_name
        );
    }

    // 初始化当前日期
    m_today = my_tm.tm_mday;

    // "r"：以只读方式打开文件，文件必须存在。如果文件不存在，则返回 NULL。
    // "w"：以写入方式打开文件，若文件存在则将其内容清空，若文件不存在则创建该文件。
    // "a"：以追加方式打开文件，若文件不存在则创建该文件，写入的数据会被追加到文件末尾。
    // "r+"：以读写方式打开文件，文件必须存在。
    // "w+"：以读写方式打开文件，若文件存在则将其内容清空，若文件不存在则创建该文件。
    // "a+"：以读写方式打开文件，若文件不存在则创建该文件，写入的数据会被追加到文件末尾。
    // 此外，还有一些其他参数选项可以与上述选项结合使用，如：
    // "b"：以二进制模式打开文件（例如："rb"、"wb"、"ab"、"r+b"、"w+b"、"a+b"）。
    // "t"：以文本模式打开文件（默认为文本模式，不需要额外指定）。
    m_fp = fopen(full_file_name, "a");
    if(nullptr == m_fp){
        return false;
    }
    return true;
}

void* Log::async_write_log(){
    std::string single_log; //队列中单个日志

    while(m_log_queue->pop(single_log)){
        m_mutex.lock();
        fputs(single_log.c_str(), m_fp);
        fflush(m_fp);
        m_mutex.unlock();
    }
}

void Log::write_log(int level, const char* format, ...){
    struct timeval now;
    gettimeofday(&now, nullptr);
    time_t t = now.tv_sec;
    // time_t t = time(nullptr);
    struct tm *sys_tm = localtime(&t);
    struct tm my_tm = *sys_tm;

    char levels[16] = {0};

    // 分级
    switch (level){
        case 0:
            strcpy(levels, "[debug]:");
            break;
        case 1:
            strcpy(levels, "[info]:");
            break;
        case 2:
            strcpy(levels, "[warn]:");
            break;
        case 3:
            strcpy(levels, "[error]:");
            break;
        default:
            strcpy(levels, "[info]:");
            break;
    }

    m_mutex.lock();

    ++m_count;

    // 如果是新的一天，或当前日志已满，则新建一个日志
    if(m_today != my_tm.tm_mday || m_count % m_split_lines == 0){
        fflush(m_fp);
        fclose(m_fp);
        char tail[16] = {0};
        snprintf(
            tail,
            16,
            "%d_%02d_%02d_",
            my_tm.tm_year,  //因为是tail所以可以随便搞一下，下同
            my_tm.tm_mon,
            my_tm.tm_mday
        );

        char new_log[512] = {0};
        // 新的一天，但有一个bug，如果隔了一个月才写，则不会新建日志，是否可以考虑把年和月也加入私有变量？
        if(m_today != my_tm.tm_mday){
            snprintf(
                new_log,
                511,
                "%s%s%s",
                dir_name,
                log_name,
                tail
            );
            m_today = my_tm.tm_mday;
            m_count = 0;
        }
        // 日志已满
        else{
            snprintf(
                new_log,
                511,
                "%s%s%s.%lld",
                dir_name,
                log_name,
                tail,
                m_count / m_split_lines
            );
            m_fp = fopen(new_log, "a");
        }
    }

    m_mutex.unlock();

    //格式化输出到缓存区中
    va_list arg_list;
    va_start(arg_list, format);  // 第一个va_list类型参数将指向第一个可变参数，第二个参数是参数列表中最后一个非可变参数

    m_mutex.lock();

    // 时间格式化
    int n = snprintf(  // snprintf的返回值是实际写入的字符数
        m_buf,
        48,
        "%d-%02d-%02d %02d:%02d:%02d.%06ld %s ",
        my_tm.tm_year + 1900,
        my_tm.tm_mon + 1,
        my_tm.tm_mday,
        my_tm.tm_hour,
        my_tm.tm_min,
        my_tm.tm_sec,
        now.tv_usec,
        levels
    );
    int m = snprintf(
        m_buf + n,
        m_log_buf_size - n - 2,
        format,
        arg_list
    );
    m_buf[n + m] = '\n';
    m_buf[n + m + 1] = '\0';

    std::string log_str = std::string(m_buf);

    m_mutex.unlock();

    // 异步日志放入队列中
    if(m_is_async && !m_log_queue->full()){
        m_log_queue->push(log_str);
    }
    else{
        m_mutex.lock();
        fputs(log_str.c_str(), m_fp);
        m_mutex.unlock();
    }

    va_end(arg_list);  // 结束可变参数的处理
}

void Log::flush(){
    m_mutex.lock();
    fflush(m_fp);
    m_mutex.unlock();
}