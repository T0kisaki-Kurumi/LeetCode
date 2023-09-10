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
#include <string>

using namespace std;

class Solution {
private:
    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> res;
    void dfs(const string& digits, int index, string cur){
        if(index == digits.size()){
            res.emplace_back(cur);
            return;
        }
        for(char i: letterMap[digits[index]-'0']){
            dfs(digits, index+1, cur+i);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return res;
        dfs(digits, 0, "");
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