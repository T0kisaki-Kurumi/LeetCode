#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s = "123456789";
    reverse(s.begin()+5, s.begin()+3);
    cout<<s;
    // string::iterator cur = s.begin();
    // cur++;
    // cout<<*cur;
    system("pause");
    return 0;
}