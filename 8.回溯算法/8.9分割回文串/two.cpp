// 131. 分割回文串
// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

// 回文串 是正着读和反着读都一样的字符串。

// 示例 1：
// 输入：s = "aab"
// 输出：[["a","a","b"],["aa","b"]]

// 示例 2：
// 输入：s = "a"
// 输出：[["a"]]

// 提示：

// 1 <= s.length <= 16
// s 仅由小写英文字母组成

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome[17][17] = {false};
    vector<vector<string>> res;
    vector<string> path;

    void computePalindrome(string& s){
        int len = s.size();
        for(int i=len-1; i>=0; --i){
            for(int j=i; j<len; ++j){
                if(j == i) isPalindrome[i][j] = true;
                else if(j == i+1) isPalindrome[i][j] = (s[i] == s[j]);
                else isPalindrome[i][j] = (isPalindrome[i+1][j-1] && (s[i] == s[j]));
            }
        }
    }

    void backtracking(string& s, int cur, int len){
        if(cur >= len){
            res.push_back(path);
            return;
        }
        for(int i=cur; i<len; ++i){
            if(isPalindrome[cur][i]){
                path.push_back(s.substr(cur, i-cur+1));
                backtracking(s, i+1, len);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int len = s.size();
        computePalindrome(s);
        // for(int i=0; i<len; ++i){
        //     for(int j=0; j<len; ++j){
        //         cout<<isPalindrome[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        backtracking(s, 0, len);
        return res;
    }
};

int main(){
    string str = "aab";
    Solution s;
    vector<vector<string>> res = s.partition(str);
    for(auto i: res){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}