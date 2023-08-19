// 145. 二叉树的后序遍历
// 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。

// 示例 1：
// 输入：root = [1,null,2,3]
// 输出：[3,2,1]

// 示例 2：
// 输入：root = []
// 输出：[]

// 示例 3：
// 输入：root = [1]
// 输出：[1]

// 提示：

// 树中节点的数目在范围 [0, 100] 内
// -100 <= Node.val <= 100

// 进阶：递归算法很简单，你可以通过迭代算法完成吗？

#include <vector>
#include <iostream>
#include "../../MyTree.cpp"

using namespace std;

class Solution {
public:
    void traversal(TreeNode* node, vector<int>& res){
        if(!node) return;
        traversal(node->left, res);
        traversal(node->right, res);
        res.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};

int main(){
    vector<int> vec{1,-1,2,-1,-1,3};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    vector<int> res = s.postorderTraversal(root);
    for(int i: res){
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}