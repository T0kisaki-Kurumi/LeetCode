// 108. 将有序数组转换为二叉搜索树
// 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。

// 高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

// 示例 1：
// 输入：nums = [-10,-3,0,5,9]
// 输出：[0,-3,9,-10,null,5]
// 解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：

// 示例 2：
// 输入：nums = [1,3]
// 输出：[3,1]
// 解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。

// 提示：

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums 按 严格递增 顺序排列

#include <iostream>
#include <vector>
#include "../MyTree.cpp"

using namespace std;

class Solution {
public:
    TreeNode* traversal(vector<int>& nums, int l, int r){
        if(l > r) return nullptr;
        int mid = (l + r) >> 1;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = traversal(nums, l, mid-1);
        cur->right = traversal(nums, mid+1, r);
        return cur;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversal(nums, 0, nums.size()-1);
    }
};

int main(){
    vector<int> nums{-10,-3,0,5,9};
    Solution s;
    TreeNode* res = s.sortedArrayToBST(nums);
    printTree(res);
    system("pause");
    return 0;
}