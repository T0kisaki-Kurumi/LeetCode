// 93. 复原 IP 地址
// 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
// 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

// 示例 1：
// 输入：s = "25525511135"
// 输出：["255.255.11.135","255.255.111.35"]

// 示例 2：
// 输入：s = "0000"
// 输出：["0.0.0.0"]

// 示例 3：
// 输入：s = "101023"
// 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

// 提示：

// 1 <= s.length <= 20
// s 仅由数字组成

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    bool isValidNum(const string& s, int left, int right){
        if(left == right) return true;
        if(s[left]-'0' == 0) return false;
        if(left + 1 == right) return (10*(s[left]-'0') + (s[left+1]-'0') < 256);
        else if(left + 2 == right) return (100*(s[left]-'0') + 10*(s[left+1]-'0') + (s[left+2]-'0') < 256);
        else return false;
    }
    vector<string> res;
    void backtracking(string& s, int startIndex, int num){
        if(num >= 3){
            if(isValidNum(s, startIndex, s.size()-1)) res.emplace_back(s);
            return;
        }
        for(int i=startIndex; i<startIndex+3 && i<s.size()-(4-num)+1; i++){
            if(isValidNum(s, startIndex, i)){
                s.insert(s.begin()+i+1, '.');
                backtracking(s, i+2, num+1);
                s.erase(s.begin()+i+1);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4 || s.size()>12) return res;
        backtracking(s, 0, 0);
        return res;
    }
};

int main(){
    string str = "101023";
    Solution s;
    vector<string> res = s.restoreIpAddresses(str);
    for(auto i: res){
        cout<<i;
        cout<<endl;
    }
    system("pause");
    return 0;
}