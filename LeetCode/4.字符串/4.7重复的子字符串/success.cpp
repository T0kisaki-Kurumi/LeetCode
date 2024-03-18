// 459. 重复的子字符串
// 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

// 示例 1:
// 输入: s = "abab"
// 输出: true
// 解释: 可由子串 "ab" 重复两次构成。

// 示例 2:
// 输入: s = "aba"
// 输出: false

// 示例 3:
// 输入: s = "abcabcabcabc"
// 输出: true
// 解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)

// 提示：

// 1 <= s.length <= 104
// s 由小写英文字母组成

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void getNext(int *next, const string& s){
        int j = -1;
        next[0] = j;
        for(int i=1; i<s.size(); i++){
            while(j>=0 && s[j+1]!=s[i]){
                j = next[j];
            }
            if(s[j+1] == s[i]){
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        int next[s.size()];
        getNext(next, s);
        if(next[s.size()-1] == -1) return false;
        int subLen = s.size() - (next[s.size()-1] + 1);
        return s.size() % subLen == 0;
    }
};

int main(){
    string s = "abcabcabcabc";
    Solution sol;
    cout<<sol.repeatedSubstringPattern(s);
    system("pause");
    return 0;
}