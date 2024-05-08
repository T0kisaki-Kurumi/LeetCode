
#include <iostream>
#include <regex>

using namespace std;

int main(){
    string s = "www-1+2+3dad1-2*3-5*0abcd";
    string p = R"([\+\-]?\d+([\+\-\*/]\d+)*)";
    // cout<<p<<endl;
    regex pattern(p);
    smatch sm;
    while(regex_search(s, sm, pattern)){
        cout<<sm.str()<<endl;
        s = sm.suffix();
    }

    system("pause");
    return 0;
}