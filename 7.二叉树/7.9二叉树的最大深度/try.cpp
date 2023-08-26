// 104. 二叉树的最大深度
// 给定一个二叉树 root ，返回其最大深度。

// 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

// 示例 1：
// 输入：root = [3,9,20,null,null,15,7]
// 输出：3

// 示例 2：
// 输入：root = [1,null,2]
// 输出：2

// 提示：

// 树中节点的数量在 [0, 104] 区间内。
// -100 <= Node.val <= 100

#include <iostream>
#include <vector>
#include <queue>
#include "../MyTree.cpp"

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // 递归法
        if(root == nullptr) return 0;
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main(){
    vector<int> vec{3,9,20,-1,-1,15,7};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    int depth = s.maxDepth(root);
    cout<<depth;
    system("pause");
    return 0;
}