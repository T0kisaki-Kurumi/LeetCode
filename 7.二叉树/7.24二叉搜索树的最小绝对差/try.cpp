// 530. 二叉搜索树的最小绝对差
// 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

// 差值是一个正数，其数值等于两值之差的绝对值。

// 示例 1：
// 输入：root = [4,2,6,1,3]
// 输出：1

// 示例 2：
// 输入：root = [1,0,48,null,null,12,49]
// 输出：1

// 提示：

// 树中节点的数目范围是 [2, 104]
// 0 <= Node.val <= 105

#include <iostream>
#include <vector>
#include <cmath>
#include "../MyTree.cpp"

using namespace std;

class Solution {
private:
    TreeNode* pre = nullptr;
    int res = INT_MAX;
    void traversal(TreeNode* root){
        if(root == nullptr) return;
        traversal(root->left);
        if(pre != nullptr) res = min(res, abs(pre->val - root->val));
        pre = root;
        traversal(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return res;
    }
};

int main(){
    TreeNode* root = vector2Tree(vector<int>{4,2,6,1,3});
    Solution s;
    int res = s.getMinimumDifference(root);
    cout<<res;
    system("pause");
    return 0;
}