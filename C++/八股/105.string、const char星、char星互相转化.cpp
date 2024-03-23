#include <iostream>
#include <string.h>
using namespace std;

int main(){
    // a)  string转const char* 
    string s1 = "abc"; 
    const char* c_s1 = s1.c_str(); 

    // b)  const char* 转string，直接赋值即可 
    const char* c_s2 = "abc"; 
    string s2(c_s2);
    // string s2 = c_s2;

    // c)  string 转char* 
    string s3 = "abc"; 
    char* c3; 
    const int len = s3.length(); 
    c3 = new char[len+1]; 
    strcpy(c3,s3.c_str()); 

    // d)  char* 转string 
    char* c4 = "abc"; 
    string s4(c4); 

    // e)  const char* 转char* 
    const char* cpc5 = "abc"; 
    char* pc5 = new char[strlen(cpc5)+1]; 
    strcpy(pc5,cpc5);

    // f)  char* 转const char*，直接赋值即可 
    char* pc6 = "abc"; 
    const char* cpc6 = pc6;

    system("pause");
}