#include <iostream>
#include <crtdbg.h>
using namespace std;

// 使用VStudio可以看到结果
int main(){
    int* a = new int[10];
    _CrtDumpMemoryLeaks();

    // system("pause");
    return 0;
}