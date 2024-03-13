// 647. 回文子串
// 相关企业
// 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

// 回文字符串 是正着读和倒过来读一样的字符串。

// 子字符串 是字符串中的由连续字符组成的一个序列。

// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

// 示例 1：
// 输入：s = "abc"
// 输出：3
// 解释：三个回文子串: "a", "b", "c"

// 示例 2：
// 输入：s = "aaa"
// 输出：6
// 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"

// 提示：

// 1 <= s.length <= 1000
// s 由小写英文字母组成

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        int res = 0;
        vector<vector<int>> dp(len, vector<int>(len));
        for(int i=len-1; i>=0; --i){
            for(int j=i; j<len; ++j){
                if(s[i] == s[j]){
                    if(i==j || i+1==j){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                    res += dp[i][j];
                }
            }
        }
        return res;
    }
};

int main(){
    string s = "aaa";
    Solution sol;
    cout<<sol.countSubstrings(s);
    system("pause");
    return 0;
}