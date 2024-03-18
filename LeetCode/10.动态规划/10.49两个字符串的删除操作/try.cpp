// 583. 两个字符串的删除操作
// 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

// 每步 可以删除任意一个字符串中的一个字符。

// 示例 1：
// 输入: word1 = "sea", word2 = "eat"
// 输出: 2
// 解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"

// 示例  2:
// 输入：word1 = "leetcode", word2 = "etco"
// 输出：4

// 提示：

// 1 <= word1.length, word2.length <= 500
// word1 和 word2 只包含小写英文字母

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1));
        for(int i=0; i<=len1; ++i) dp[i][0] = i;
        for(int j=0; j<=len2; ++j) dp[0][j] = j;
        for(int i=1; i<=len1; ++i){
            for(int j=1; j<=len2; ++j){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
                }
            }
            // for(auto i: dp){
            //     for(auto j: i){
            //         cout<<j<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
        }
        return dp[len1][len2];
    }
};

int main(){
    // string s = "leetcode";
    // string t = "etco";
    string s = "sea";
    string t = "eat";
    Solution sol;
    cout<<sol.minDistance(s, t);
    system("pause");
    return 0;
}