#include "log.h"

int main(){
    Log* log = Log::get_instance();
    // // 同步
    // log->init("log.txt");
    // log->write_log(0, "aaabbb");
    // log->flush();

    // 异步
    log->init("log.txt", 8129, 50000, 10);
    log->write_log(0, "cccddd");
    log->flush_log_thread(nullptr);

    return 0;
}