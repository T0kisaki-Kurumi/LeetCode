// 17. 电话号码的字母组合
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

// 示例 1：
// 输入：digits = "23"
// 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

// 示例 2：
// 输入：digits = ""
// 输出：[]

// 示例 3：
// 输入：digits = "2"
// 输出：["a","b","c"]

// 提示：

// 0 <= digits.length <= 4
// digits[i] 是范围 ['2', '9'] 的一个数字。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    unordered_map<char, string> m{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    void backtracking(vector<string>& res, string& cur, string& digits, int pos){
        if(pos == digits.size()){
            res.push_back(cur);
        }
        for(char c: m[digits[pos]]){
            cur.push_back(c);
            backtracking(res, cur, digits, pos+1);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) return res;
        string cur = "";
        backtracking(res, cur, digits, 0);
        return res;
    }
};

int main(){
    string digits = "23";
    Solution s;
    vector<string> res = s.letterCombinations(digits);
    for(auto i: res){
        cout<<i<<endl;
    }
    system("pause");
    return 0;
}