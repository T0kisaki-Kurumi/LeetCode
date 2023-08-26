// 110. 平衡二叉树
// 给定一个二叉树，判断它是否是高度平衡的二叉树。

// 本题中，一棵高度平衡二叉树定义为：

// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

// 示例 1：
// 输入：root = [3,9,20,null,null,15,7]
// 输出：true

// 示例 2：
// 输入：root = [1,2,2,3,3,null,null,4,4]
// 输出：false

// 示例 3：
// 输入：root = []
// 输出：true

// 提示：

// 树中的节点数在范围 [0, 5000] 内
// -104 <= Node.val <= 104

#include <iostream>
// #include <cmath>
#include "../MyTree.cpp"

using namespace std;

class Solution {
public:
    int getHeight(TreeNode* root){
        if(root == nullptr) return 0;
        int leftHeight = getHeight(root->left);
        if(leftHeight == -1) return -1;
        int rightHeight = getHeight(root->right);
        if(rightHeight == -1) return -1;
        return abs(leftHeight - rightHeight) <= 1 ? max(leftHeight, rightHeight)+1 : -1;
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};

int main(){
    vector<int> vec{1,2,3,4,5,6};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    bool depth = s.isBalanced(root);
    cout<<depth;
    system("pause");
    return 0;
}