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
private:
    vector<vector<bool>> isPalindrome;
    void computePalindrome(const string& s){
        isPalindrome.resize(s.size(), vector<bool>(s.size(), false));
        for(int i=s.size()-1; i>=0; --i){
            for(int j=i; j<s.size(); ++j){
                if(i == j) isPalindrome[i][j] = true;
                else if(j == i+1) isPalindrome[i][j] = (s[i] == s[j]);
                else isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i+1][j-1]);
            }
        }
    }
    vector<vector<string>> res;
    vector<string> path;
    void backtracking(const string& s, int cur){
        if(cur >= s.size()){
            res.emplace_back(path);
            return;
        }
        for(int i=cur; i<s.size(); ++i){
            if(isPalindrome[cur][i]) path.emplace_back(s.substr(cur, i-cur+1));
            else continue;
            backtracking(s, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        computePalindrome(s);
        backtracking(s, 0);
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