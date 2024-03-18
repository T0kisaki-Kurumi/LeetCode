#include <iostream>
#include <string>
using namespace std;

void test1(){
    string s = "hello";
    s.insert(1,"111");
    cout<<s<<endl;
    s.insert(0, 2, '6');
    cout<<s<<endl;
}

void test2(){
    string s = "hello";
    s.erase(2, 2);
    cout<<s<<endl;
    s.erase(1);
    cout<<s<<endl;
}

void test3(){
    char* str = "hello";
    string s = "world";
    
    char* str2 = const_cast<char*>(s.c_str());
    string s2(str);

    // 隐式类型转换
    string s3 = str;
    // const char* str3 = s;
}

void test4(){
    string s = "12345";
    char& a = s[1];
    a = 'a';
    cout<<s<<endl;
    cout<<(int*)s.c_str()<<endl; //地址

    s = "66666";
    a = 'b';
    cout<<s<<endl;
    cout<<(int*)s.c_str()<<endl; //地址

    s = "66666666666666666666666";
    a = 'b';
    cout<<s<<endl;
    cout<<(int*)s.c_str()<<endl; //地址
}

void test5(){
    string s = "AuiIUHbb";
    for(char& c: s){
        c = toupper(c);
    }
    cout<<s<<endl;
    for(char& c: s){
        c = tolower(c);
    }
    cout<<s<<endl;
}

void test6(){
    
}

int main(){
    // test1();
    // test2();
    // test3();
    // test4();
    test5();
    // test6();

    system("pause");
    return 0;
}