// 700. 二叉搜索树中的搜索
// 给定二叉搜索树（BST）的根节点 root 和一个整数值 val。

// 你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。

// 示例 1:
// 输入：root = [4,2,7,1,3], val = 2
// 输出：[2,1,3]

// 示例 2:
// 输入：root = [4,2,7,1,3], val = 5
// 输出：[]

// 提示：

// 数中节点数在 [1, 5000] 范围内
// 1 <= Node.val <= 107
// root 是二叉搜索树
// 1 <= val <= 107

#include <iostream>
#include <vector>
#include "../MyTree.cpp"

using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != nullptr){
            if(root->val == val) return root;
            else if(root->val > val) root = root->left;
            else root = root->right;
        }
        return root;
    }
};

int main(){
    TreeNode* root = vector2Tree(vector<int>{4,2,7,1,3});
    int val = 2;
    Solution s;
    TreeNode* res = s.searchBST(root, val);
    printTree(res);
    system("pause");
    return 0;
}