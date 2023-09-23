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
private:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    }
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> intervals(26, vector<int>{-1,-1});
        vector<int> res;
        for(int i=0; i<s.size(); ++i){
            if(intervals[s[i]-'a'][0] == -1){
                intervals[s[i]-'a'][0] = i;
                intervals[s[i]-'a'][1] = i;
            }
            else{
                intervals[s[i]-'a'][1] = i;
            }
        }
        sort(intervals.begin(), intervals.end(), cmp);
        // for(auto vec: intervals){
        //     cout<<vec[0]<<" "<<vec[1];
        //     cout<<endl;
        // }
        // return {};
        int cur = 0;
        while(intervals[cur][0] == -1){
            ++cur;
        }
        int cur_left = intervals[cur][0];
        int cur_right = intervals[cur][1];
        for(int i=cur; i<intervals.size(); ++i){
            if(intervals[i][0] > cur_right){
                res.emplace_back(cur_right - cur_left + 1);
                cur_left = intervals[i][0];
                cur_right = intervals[i][1];
            }
            else{
                cur_right = max(cur_right, intervals[i][1]);
            }
        }
        res.emplace_back(cur_right - cur_left + 1);
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