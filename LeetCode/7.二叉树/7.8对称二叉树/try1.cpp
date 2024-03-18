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
#include <stack>
#include <vector>
#include "../MyTree.cpp"

using namespace std;

class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right){
        if(left == nullptr && right != nullptr) return false;
        else if(left != nullptr && right == nullptr) return false;
        else if(left == nullptr && right == nullptr) return true;
        else if(left->val != right->val) return false;
        else{
            bool outside = compare(left->left, right->right);
            bool inside = compare(left->right, right->left);
            return outside && inside;
        }
    }

    bool isSymmetric(TreeNode* root) {
        // 递归法
        if(root == nullptr) return true;
        return compare(root->left, root->right);
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