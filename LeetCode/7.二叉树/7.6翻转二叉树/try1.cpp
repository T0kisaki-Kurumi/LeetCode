// 226. 翻转二叉树
// 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

// 示例 1：
// 输入：root = [4,2,7,1,3,6,9]
// 输出：[4,7,2,9,6,3,1]

// 示例 2：
// 输入：root = [2,1,3]
// 输出：[2,3,1]

// 示例 3：
// 输入：root = []
// 输出：[]

// 提示：

// 树中节点数目范围在 [0, 100] 内
// -100 <= Node.val <= 100

#include <iostream>
#include <stack>
#include <vector>
#include "../MyTree.cpp"

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // 递归法后序遍历
        if(root == nullptr) return root;
        if(root->left) invertTree(root->left);
        if(root->right) invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

int main(){
    vector<int> vec{4,2,7,1,3,6,9};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    TreeNode* res = s.invertTree(root);
    printTree(res);
    system("pause");
    return 0;
}