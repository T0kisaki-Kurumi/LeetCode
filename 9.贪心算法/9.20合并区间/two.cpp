// 56. 合并区间
// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

// 示例 1：
// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

// 示例 2：
// 输入：intervals = [[1,4],[4,5]]
// 输出：[[1,5]]
// 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。

// 提示：

// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(auto& i: intervals){
            if(i[0] > right){
                res.push_back(vector<int>{left, right});
                left = i[0];
                right = i[1];
            }
            else{
                right = max(right, i[1]);
            }
        }
        res.push_back(vector<int>{left, right});
        return res;
    }
};

int main(){
    vector<vector<int>> intervals{vector<int>{1,3},vector<int>{2,6},vector<int>{8,10},vector<int>{15,18}};
    Solution sol;
    vector<vector<int>> res = sol.merge(intervals);
    for(auto i: res){
        for(int j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}