// 84. 柱状图中最大的矩形
// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

// 求在该柱状图中，能够勾勒出来的矩形的最大面积。

// 示例 1:
// 输入：heights = [2,1,5,6,2,3]
// 输出：10
// 解释：最大的矩形为图中红色区域，面积为 10

// 示例 2：
// 输入： heights = [2,4]
// 输出： 4

// 提示：

// 1 <= heights.length <=105
// 0 <= heights[i] <= 104

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int curLen = 0;
        int curMin = 0;
        int len = heights.size();
        for(int i=0; i<len; ++i){
            if(heights[i] == 0){
                curLen = 0;
                curMin = 0;
            }
            else{
                curLen++;
                curMin = (curMin == 0 ? heights[i] : min(curMin, heights[i]));
                res = max(res, curLen * curMin);
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums{2,1,5,6,2,3};
    Solution sol;
    cout<<sol.largestRectangleArea(nums)<<endl;
    system("pause");
    return 0;
}