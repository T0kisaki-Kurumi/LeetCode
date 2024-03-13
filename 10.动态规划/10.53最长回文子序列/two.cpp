// 516. 最长回文子序列
// 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

// 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

// 示例 1：
// 输入：s = "bbbab"
// 输出：4
// 解释：一个可能的最长回文子序列为 "bbbb" 。

// 示例 2：
// 输入：s = "cbbd"
// 输出：2
// 解释：一个可能的最长回文子序列为 "bb" 。
 
// 提示：

// 1 <= s.length <= 1000
// s 仅由小写英文字母组成

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len));
        for(int i=len-1; i>=0; --i){
            for(int j=i; j<len; ++j){
                if(s[i] == s[j]){
                    if(i==j) dp[i][j] = 1;
                    else dp[i][j] = dp[i+1][j-1] + 2;  // i>j时候dp[i][j]都为0
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][len-1];
    }
};

int main(){
    string s = "bbbab";
    Solution sol;
    cout<<sol.longestPalindromeSubseq(s);
    system("pause");
    return 0;
}