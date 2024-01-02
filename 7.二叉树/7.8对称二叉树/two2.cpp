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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return root;
        stack<TreeNode*> st1, st2;
        st1.push(root->left);
        st2.push(root->right);
        while(!st1.empty()){
            TreeNode* cur1 = st1.top(); st1.pop();
            TreeNode* cur2 = st2.top(); st2.pop();
            if(cur1 == nullptr && cur2 != nullptr) return false;
            if(cur1 != nullptr && cur2 == nullptr) return false;
            if(cur1 == nullptr && cur2 == nullptr) continue;
            if(cur1->val != cur2->val) return false;
            st1.push(cur1->left);
            st1.push(cur1->right);
            st2.push(cur2->right);
            st2.push(cur2->left);
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