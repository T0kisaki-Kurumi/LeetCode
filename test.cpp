#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
using namespace std;

int main(){
<<<<<<< HEAD
    // const char* a = "54321 6789";
    // int fd = open("E:\\code\\LeetCode\\LeetCode\\test.txt", O_RDWR);
    // if(fd < 0){
    //     perror("open");
    //     system("pause");
    //     return 1;
    // }
    // // int w = write(fd, a, strlen(a));
    // int w = write(fd, a, sizeof(a));
    // cout<<w<<endl;
    // close(fd);
    char buf[1024] = {0};
    cout<<sizeof(buf)<<endl;
=======
    string s = "123456";
    string s1 = "123456";
    cout<<s==s1<<endl;
>>>>>>> 9beccd633dc985aa34f3375aaeadfe90534a0d0a

    system("pause");
}