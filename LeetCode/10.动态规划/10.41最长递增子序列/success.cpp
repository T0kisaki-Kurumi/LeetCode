// 300. 最长递增子序列
// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

// 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

// 示例 1：
// 输入：nums = [10,9,2,5,3,7,101,18]
// 输出：4
// 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

// 示例 2：
// 输入：nums = [0,1,0,3,2,3]
// 输出：4

// 示例 3：
// 输入：nums = [7,7,7,7,7,7,7]
// 输出：1

// 提示：

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1; //记录当前的最长子序列长度
        int n = nums.size();
        vector<int> d(n+1, 0); //记录长度为i的子序列的最后一个数的最小取值
        d[1] = nums[0];
        for(int i=0; i<n; ++i){
            if(nums[i] > d[len]){
                ++len;
                d[len] = nums[i];
            }
            else{
                int l=1, r=len, cur=0;
                while(l<=r){
                    int mid = (l+r) >> 1;
                    if(d[mid]<nums[i]){
                        cur = mid;
                        l = mid + 1;
                    }
                    else{
                        r = mid - 1;
                    }
                }
                d[cur+1] = nums[i];
            }
            for(int j=1; j<=len; ++j){
                cout<<d[j]<<" ";
            }
            cout<<endl;
        }
        return len;
    }
};

int main(){
    // vector<int> nums{10,9,2,5,3,7,101,18};
    vector<int> nums{3,5,6,2,5,4,19,5,6,7,12};
    Solution sol;
    cout<<sol.lengthOfLIS(nums);
    system("pause");
    return 0;
}