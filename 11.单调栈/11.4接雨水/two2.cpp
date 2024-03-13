// 42. 接雨水
// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

// 示例 1：
// 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出：6
// 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

// 示例 2：
// 输入：height = [4,2,0,3,2,5]
// 输出：9

// 提示：

// n == height.length
// 1 <= n <= 2 * 104
// 0 <= height[i] <= 105

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> maxL(len);
        vector<int> maxR(len);
        maxL[0] = height[0];
        maxR[len-1] = height[len-1];
        for(int i=1; i<len; ++i){
            maxL[i] = max(maxL[i-1], height[i]);
        }
        for(int i=len-2; i>=0; --i){
            maxR[i] = max(maxR[i+1], height[i]);
        }
        int res = 0;
        for(int i=0; i<len; ++i){
            res += (min(maxL[i], maxR[i]) - height[i]);
        }
        return res;
    }
};

int main(){
    vector<int> nums{4,2,0,3,2,5};
    Solution sol;
    cout<<sol.trap(nums)<<endl;
    system("pause");
    return 0;
}