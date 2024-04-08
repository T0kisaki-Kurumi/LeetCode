// 215. 数组中的第K个最大元素

// 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

// 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

// 示例 1:
// 输入: [3,2,1,5,6,4], k = 2
// 输出: 5

// 示例 2:
// 输入: [3,2,3,1,2,4,5,5,6], k = 4
// 输出: 4

// 提示：

// 1 <= k <= nums.length <= 105
// -104 <= nums[i] <= 104

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int quickSort(vector<int>& nums, int k, int l, int r){
        // if(l == r) return nums[l];
        int randPos = l + (rand()%(r-l+1));
        swap(nums[l], nums[randPos]);
        int key = nums[l];
        int curL = l+1, curR = r;
        while(1){
            while(curL<=curR && nums[curL]>key) ++curL;
            while(curL<=curR && nums[curR]<key) --curR;
            if(curL <= curR){
                swap(nums[curL], nums[curR]);
                ++curL;
                --curR;
            }
            else break;
        }
        swap(nums[l], nums[curR]);
        if(curR == k-1) return nums[curR];
        else if(curR > k-1) return quickSort(nums, k, l, curR-1);
        else return quickSort(nums, k, curR+1, r);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int res = quickSort(nums, k, 0, nums.size()-1);
        return res;
    }
};

// class Solution {
// public:
//     int quickselect(vector<int> &nums, int l, int r, int k) {
//         if (l == r)
//             return nums[k];
//         int partition = nums[l], i = l - 1, j = r + 1;
//         while (i < j) {
//             do i++; while (nums[i] > partition);
//             do j--; while (nums[j] < partition);
//             if (i < j)
//                 swap(nums[i], nums[j]);
//         }
//         if (k <= j)return quickselect(nums, l, j, k);
//         else return quickselect(nums, j + 1, r, k);
//     }

//     int findKthLargest(vector<int> &nums, int k) {
//         int n = nums.size();
//         return quickselect(nums, 0, n - 1, k-1);
//     }
// };

int main(){
    vector<int> nums{3,2,1,5,6,4};
    int k = 2;
    // vector<int> nums{1,2,3,4,5,1,1,1,1,1,1,1};
    // int k = 10;
    Solution s;
    int res = s.findKthLargest(nums, k);
    cout<<res<<endl;

    // vector<int> v1{}

    system("pause");
    return 0;
}