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
#include <cmath>

using namespace std;

class Solution {
public:
    vector<string> res;
    bool isValid(string& s){
        int num = atoi(s.c_str());
        if(s.size() == 1) return true;
        int min = pow(10, s.size()-1);
        int max = pow(10, s.size());
        if(!(min<=num && num<max)) return false;
        return 0<=num && num<=255;
    }

    void backtracking(string& s, int cur, int num, string path, int len){
        if(num == 4){
            if(cur == len) res.push_back(path);
            return;
        }
        for(int i=cur; i<len && i<cur+3; ++i){
            string tmp = s.substr(cur, i-cur+1);
            if(isValid(tmp)){
                num == 0 ? backtracking(s, i+1, num+1, tmp, len) : backtracking(s, i+1, num+1, path+'.'+tmp, len);
            }
        }
        // for(int i=0; i<len; ++i){
        //     for(int j=i; j<len; ++j){
        //         string tmp = s.substr(i, j-i+1);
        //         cout<<isValid(tmp)<<" ";
        //     }
        //     cout<<endl;
        // }
    }

    vector<string> restoreIpAddresses(string s) {
        int len = s.size();
        if(len<4 || len>12) return res;
        backtracking(s, 0, 0, "", len);
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