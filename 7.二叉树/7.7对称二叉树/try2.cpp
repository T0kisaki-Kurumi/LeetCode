// 101. 对称二叉树
// 给你一个二叉树的根节点 root ， 检查它是否轴对称。

// 示例 1：
// 输入：root = [1,2,2,3,4,4,3]
// 输出：true

// 示例 2：
// 输入：root = [1,2,2,null,3,null,3]
// 输出：false

// 提示：

// 树中节点数目在范围 [1, 1000] 内
// -100 <= Node.val <= 100

// 进阶：你可以运用递归和迭代两种方法解决这个问题吗？

#include <iostream>
#include <queue>
#include <vector>
#include "../MyTree.cpp"

using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // 迭代法
        if(root == nullptr) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();
            if(left == nullptr && right == nullptr) continue;
            if(left == nullptr || right == nullptr || left->val != right->val) return false;
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};

int main(){
    vector<int> vec{1,2,2,3,4,4,3};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    bool res = s.isSymmetric(root);
    cout<<res;
    system("pause");
    return 0;
}