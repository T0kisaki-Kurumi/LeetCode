#include <iostream>
#include <vector>
using namespace std;

<<<<<<< HEAD
inline void getnext(vector<int>& next, string& s){
    int j = -1;
    next[0] = j;
    for(int i=1; i<s.size(); ++i){
        while(j>=0 && s[i]!=s[j+1]) j=next[j];
        if(s[i] == s[j+1]) ++j;
        next[i] = j;
    }
}
=======
int main(){
<<<<<<< HEAD
    string s1 = "abc";
    string s2 = "尹康华";
    cout<<s1.length()<<" "<<s2.length()<<endl;
=======
<<<<<<< HEAD
    
=======
    string s = "abcdefa\
    aaaa";
    cout<<s<<endl;
>>>>>>> 9a5334f478d7c112a17e6fa630f4a844b5a11df3
>>>>>>> c0e343edf0d368cfca3a2d833f4b676086d0b808
>>>>>>> 6d02d044872792fef4fbdf9e420b6346d6bdd0a1

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