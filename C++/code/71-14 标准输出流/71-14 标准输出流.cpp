#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

void test1(){
    cout.put('a').put('\n');
    char buf[] = "hello world\n";
    cout.write(buf, strlen(buf));
}

void test2(){
    int num = 99;
    cout.width(10); //设置输出宽度
    cout.fill('*'); //空缺处填充

    // 对齐方式，默认为右
    cout.setf(ios::left);
    // cout.setf(ios::right);
    // cout.setf(ios::internal); //符号在左，数字在右

    // 设置基数，dec十进制，hex十六进制，oct八进制
    // 使用前要先卸载当前基数。卸载unsetf，设置setf
    cout.unsetf(ios::dec);
    cout.setf(ios::hex);
    // cout.setf(ios::oct);

    // 显示进制，0x 十六进制，0 八进制
    // cout.setf(ios::showbase);
    cout<<num<<endl;
}

void test3(){
    int num = 99;
    cout<<setw(10)
        <<setfill('#')
        <<setiosflags(ios::showbase)
        <<setiosflags(ios::left)
        <<hex
        <<num
        <<endl;
}

int main(){
    // test1();
    // test2();
    test3();

    system("pause");
    return 0;
}