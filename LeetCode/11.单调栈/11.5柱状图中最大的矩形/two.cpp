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
        int len = heights.size();
        vector<int> left(len);
        vector<int> right(len);
        left[0] = -1;
        right[len-1] = len;
        for(int i=1; i<len; ++i){
            int cur = i-1;
            while(cur>=0 && heights[cur]>=heights[i]){
                cur = left[cur];
            }
            left[i] = cur;
        }
        for(int i=len-2; i>=0; --i){
            int cur = i+1;
            while(cur<len && heights[cur]>=heights[i]){
                cur = right[cur];
            }
            right[i] = cur;
        }
        for(int i=0; i<len; ++i){
            res = max(res, heights[i]*(right[i]-left[i]-1));
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