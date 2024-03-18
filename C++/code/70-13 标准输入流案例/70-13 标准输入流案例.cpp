#include <iostream>
#include <string>
#include <numeric>
using namespace std;

void test1(){
    cout<<"输入一个数字或字符串："<<endl;
    char c = cin.peek();
    if('0'<=c && c<='9'){
        int num;
        cin>>num;
        cout<<"输入的是数字"<<num<<endl;
    }
    else{
        char buf[1024] = {0};
        cin>>buf;
        cout<<"输入的是字符串"<<buf<<endl;
    }
}

void test2(){
    cout<<"请输入0-10之间的数字："<<endl;
    int num;
   while (true) {
        cin >> num;
        if (cin.fail() || num < 0 || num > 10) {
            cin.clear(); // 清除错误状态
            cin.sync();
            // cin.ignore(); // 忽略之前的输入
            cout << "输入无效，请重新输入0-10之间的数字：" << endl;
        } else {
            cout << "输入正确，数字为" << num << endl;
            break;
        }
    }
}

int main(){
    // test1();
    test2();

    system("pause");
    return 0;
}