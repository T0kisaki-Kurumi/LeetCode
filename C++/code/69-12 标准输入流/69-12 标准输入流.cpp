#include <iostream>
#include <string>
using namespace std;

void test1(){
    char c = cin.get();  // 相当于char c;  cin.get(c);
    // char c;
    // cin.get(c);
    cout<<c<<endl;
    c = cin.get();
    cout<<c<<endl;
    c = cin.get();
    cout<<c<<endl;
}

void test2(){
    char buffer[1024];
    // cin.get(buffer, 1024);
    cin.get(buffer, 3);
    cout<<buffer<<endl;
    char c = cin.get();
    cout<<(c == '\n')<<endl;
}

void test3(){
    char buffer[1024];
    cin.getline(buffer, 1024);
    cout<<buffer;
}

void test4(){
    cin.ignore(5);
    char c = cin.get();
    cout<<c<<endl;
}

void test5(){
    char c = cin.peek();
    cout<<c<<endl;
    c = cin.get();
    cout<<c<<endl;
}

void test6(){
    char c = cin.get();
    cin.putback(c);
    char buf[1024];
    cin.getline(buf, 1024);
    cout<<buf<<endl;
}
 
int main(){
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    test6();

    system("pause");
    return 0;
}