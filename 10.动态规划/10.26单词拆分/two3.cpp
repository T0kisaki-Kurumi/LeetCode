// 139. 单词拆分
// 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

// 示例 1：
// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。

// 示例 2：
// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
// 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
//      注意，你可以重复使用字典中的单词。

// 示例 3：
// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出: false

// 提示：

// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s 和 wordDict[i] 仅由小写英文字母组成
// wordDict 中的所有字符串 互不相同

#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        bool dp[len+1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for(int i=1; i<len+1; ++i){
            for(string word: wordDict){
                int curLen = word.size();
                if(i-1+curLen > len) continue;
                dp[i-1+curLen] = dp[i-1+curLen] || (s.substr(i-1, curLen)==word && dp[i-1]);
            }
            // for(int i: dp){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
        }
        return dp[len];
    }
};

int main(){
    string s = "applepenapple";
    vector<string> wordDict{"apple", "pen"};
    Solution sol;
    cout<<sol.wordBreak(s, wordDict);
    system("pause");
    return 0;
}