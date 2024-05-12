#include <iostream>
#include <vector>
using namespace std;

inline void getnext(vector<int>& next, string& s){
    int j = -1;
    next[0] = j;
    for(int i=1; i<s.size(); ++i){
        while(j>=0 && s[i]!=s[j+1]) j=next[j];
        if(s[i] == s[j+1]) ++j;
        next[i] = j;
    }
}

inline bool kmp(string& source, string& target){
    int len1 = source.size();
    int len2 = target.size();
    if(len2 > len1) return false;
    vector<int> next(len2);
    getnext(next, target);
    // for(int i:next) cout<<i<<" ";
    // cout<<endl;

    int j = -1;
    for(int i=0; i<2*len1; ++i){
        while(j>=0 && source[i%len1]!=target[j+1]) j = next[j];
        if(source[i%len1] == target[j+1]) ++j;
        if(j == len2-1) return true;
    }
    return false;
}

int main() {
    int t = 3;
    string source, target;
    while(t--){
        cin>>source>>target;
        if(kmp(source, target)) cout<<1;
        else cout<<0;
    }
    system("pause");
}
// 64 位输出请用 printf("%lld")