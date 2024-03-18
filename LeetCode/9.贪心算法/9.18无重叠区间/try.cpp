// 435. 无重叠区间
// 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。

// 示例 1:
// 输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
// 输出: 1
// 解释: 移除 [1,3] 后，剩下的区间没有重叠。

// 示例 2:
// 输入: intervals = [ [1,2], [1,2], [1,2] ]
// 输出: 2
// 解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。

// 示例 3:
// 输入: intervals = [ [1,2], [2,3] ]
// 输出: 0
// 解释: 你不需要移除任何区间，因为它们已经是无重叠的了。

// 提示:

// 1 <= intervals.length <= 105
// intervals[i].length == 2
// -5 * 104 <= starti < endi <= 5 * 104

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int pre_right = intervals[0][1];
        int res = 0;
        for(int i=1; i<intervals.size(); ++i){
            if(intervals[i][0] >= pre_right){
                pre_right = intervals[i][1];
            }
            else{
                ++res;
            }
        }
        return res;
    }
};

int main(){
    vector<vector<int>> intervals{vector<int>{1,2},vector<int>{2,3},vector<int>{3,4},vector<int>{1,3}};
    Solution sol;
    cout<<sol.eraseOverlapIntervals(intervals);
    system("pause");
    return 0;
}