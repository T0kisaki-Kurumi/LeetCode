
#include <iostream>
#include <regex>

using namespace std;

int main(){
    // string s = "  wo chao ying kang hua 666    ";
    // string p = R"([^ ]+)";
    string s = "  wo*chao*yin***  kang*hua 666    ";
    string p = R"([^ \*]+)";
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