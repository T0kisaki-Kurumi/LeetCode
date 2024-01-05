// 404. 左叶子之和
// 给定二叉树的根节点 root ，返回所有左叶子之和。

// 示例 1：
// 输入: root = [3,9,20,null,null,15,7] 
// 输出: 24 
// 解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

// 示例 2:
// 输入: root = [1]
// 输出: 0

// 提示:

// 节点数在 [1, 1000] 范围内
// -1000 <= Node.val <= 1000

#include <iostream>
#include <string>
#include "../MyTree.cpp"

using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        int cur = (root->left && root->left->left==nullptr && root->left->right==nullptr) ? root->left->val : 0;
        return cur + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

int main(){
    vector<int> vec{3,9,20,-1,-1,15,7};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    int res = s.sumOfLeftLeaves(root);
    cout<<res;
    system("pause");
    return 0;
}