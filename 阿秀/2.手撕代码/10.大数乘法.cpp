#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string multi(string& s1, string& s2){
    int len1 = s1.size();
    int len2 = s2.size();
    int mul[len1 + len2];
    memset(mul, 0, sizeof(mul));
    for(int i=len2-1; i>=0; --i){
        if(s2[i] == '0') continue;
        for(int j=len1-1; j>=0; --j){
            mul[i+j+1] += ((s1[j]-'0') * (s2[i]-'0'));
        }
    }
    for(int i=len1+len2-1; i>0; --i){
        if(mul[i] > 9){
            mul[i-1] += (mul[i]/10);
            mul[i] %= 10;
        }
    }

    // for(int i: mul){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    
    string res = "";
    int start = (mul[0]==0 ? 1:0);
    for(int i=start; i<len1+len2; ++i){
        res += (char)(mul[i] + '0');
    }

    return res;
}

int main(){
    string s1 = "5486346464";
    string s2 = "84888";

    string res = multi(s1, s2);
    cout<<res<<endl;

    system("pause");
    return 0;
}