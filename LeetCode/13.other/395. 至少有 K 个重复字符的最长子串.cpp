// 395. 至少有 K 个重复字符的最长子串

// 给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
// 如果不存在这样的子字符串，则返回 0。

// 示例 1：
// 输入：s = "aaabb", k = 3
// 输出：3
// 解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。

// 示例 2：
// 输入：s = "ababbc", k = 2
// 输出：5
// 解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。

// 提示：

// 1 <= s.length <= 104
// s 仅由小写英文字母组成
// 1 <= k <= 105

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void computeCount(string& s, vector<vector<int>>& count){
        int len = s.size();
        vector<int> cur(26, 0);
        for(int i=0; i<len; ++i){
            ++cur[s[i]-'a'];
            count.emplace_back(cur);
        }
    }

    vector<int> computeCur(vector<vector<int>>& count, int l, int r){
        vector<int> res(26, 0);
        if(l == 0){
            for(int i=0; i<26; ++i){
                res[i] = count[r][i];
            }
        }
        else{
            for(int i=0; i<26; ++i){
                res[i] = count[r][i] - count[l-1][i];
            }
        }

        return res;
    }

    vector<string> split(string& s, int i){
        vector<string> res;
        int cur = 0;
        int tail;
        while((tail = s.find(i+'a', cur)) != s.npos){
            res.push_back(s.substr(cur, tail-cur));
            cur = tail+1;
        }
        if(cur != s.size()) res.push_back(s.substr(cur));
        return res;
    }

    bool check(vector<int>& vec, int k){
        for(int& i: vec){
            if(i>0 && i<k) return false;
        }
        return true;
    }

    int dfs(string& s, vector<vector<int>>& count, int l, int r, int k){
        if(r-l+1 < k) return 0;
        int res = 0;
        vector<int> curCount = computeCur(count, l, r);
        if(check(curCount, k)) res = r-l+1;
        else{
            vector<int> splitSet;
            for(int i=0; i<26; ++i){
                if(curCount[i] > 0 && curCount[i] < k){
                    splitSet.push_back(i);
                }
            }
            for(int i: splitSet){
                int curL = l;
                vector<string> sub = split(s, i);

                // cout<<s<<endl;
                // for(string& s: sub) cout<<s<<" ";
                // cout<<endl;

                for(string& s: sub){
                    res = max(res, dfs(s, count, curL, curL+s.size()-1, k));
                    curL += (s.size()+1);
                }
            }
        }

        return res;
    }

    int longestSubstring(string s, int k) {
        vector<vector<int>> count;
        computeCount(s, count);
        // int j=0;
        // for(auto& vec: count){
        //     cout<<j++<<endl;
        //     for(int i=0; i<26; ++i){
        //         if(vec[i]) cout<<(char)(i+'a')<<": "<<vec[i]<<endl;
        //     }
        //     cout<<endl;
        // }

        int res = dfs(s, count, 0, s.size()-1, k);

        return res;
    }
};


int main(){
    string str = "aaaaaaaaaaaabcdefghijklmnopqrstuvwzyz";
    int k = 3;
    Solution s;
    cout<<s.longestSubstring(str, k)<<endl;
    system("pause");
}