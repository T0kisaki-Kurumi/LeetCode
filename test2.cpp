#include <vector>
#include <iostream>
#include <queue>

using namespace std;


int main(){
    string s;
    string y = "aeiou";
    cin>>s;
    int num1 = 0, num2 = 0;
    for(char& c: s){
        if(y.find(c) != string::npos) ++num1;
        else ++num2;
    }
    int left = 0;
    int right = num1 - num2;

    int res = 0;
    string cur = "";
    for(char& c: s){
        cur += c;
        if(y.find(c) != string::npos){
            ++left;
            --right;
        }
        else{
            --left;
            ++right;
        }
        if(left == right){
            ++res;
            cout<<cur<<endl;
        }
    }
    cout<<res<<endl;
    
    // system("pause");
    return 0;
}