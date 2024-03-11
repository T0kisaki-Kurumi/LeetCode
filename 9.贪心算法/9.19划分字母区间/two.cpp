// 763. 划分字母区间
// 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。

// 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。

// 返回一个表示每个字符串片段的长度的列表。

// 示例 1：
// 输入：s = "ababcbacadefegdehijhklij"
// 输出：[9,7,8]
// 解释：
// 划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
// 每个字母最多出现在一个片段中。
// 像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。

// 示例 2：
// 输入：s = "eccbbbbdec"
// 输出：[10]

// 提示：

// 1 <= s.length <= 500
// s 仅由小写英文字母组成

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int r[26] = {0};
        int len = s.size();
        for(int i=0; i<len; ++i){
            char c = s[i];
            r[c-'a'] = i;
        }
        int begin = 0;
        int index = 0;
        int curR = 0;
        vector<int> res;
        while(index < len){
            curR = max(curR, r[s[index] - 'a']);
            if(index == curR){
                res.push_back(index - begin + 1);
                begin = index + 1;
            }
            ++index;
        }
        return res;
    }
};

int main(){
    string s = "ababcbacadefegdehijhklij";
    Solution sol;
    vector<int> res = sol.partitionLabels(s);
    for(int i: res){
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}