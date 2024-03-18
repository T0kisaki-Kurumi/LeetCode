// 236. 二叉树的最近公共祖先
// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

// 示例 1：
// 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// 输出：3
// 解释：节点 5 和节点 1 的最近公共祖先是节点 3 。

// 示例 2：
// 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// 输出：5
// 解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。

// 示例 3：
// 输入：root = [1,2], p = 1, q = 2
// 输出：1

// 提示：

// 树中节点数目在范围 [2, 105] 内。
// -109 <= Node.val <= 109
// 所有 Node.val 互不相同 。
// p != q
// p 和 q 均存在于给定的二叉树中。

#include <iostream>
#include <vector>
#include <cmath>
#include "../MyTree.cpp"

using namespace std;

class Solution {
private:
    TreeNode* traversal(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == p || root == q || root == nullptr){
            return root;
        }
        TreeNode* left = traversal(root->left, p, q);
        TreeNode* right = traversal(root->right, p, q);
        if(left && right) return root;
        // if(left == nullptr && right) return right;
        // if(left && right == nullptr) return left;
        // return nullptr;

        //简化写法
        return left ? left : right;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root, p, q);
    }
};

int main(){
    TreeNode* root = vector2Tree(vector<int>{3,5,1,6,2,0,8,-1,-1,7,4});
    Solution s;
    TreeNode* res = s.lowestCommonAncestor(root, root, root->left->right);
    printTree(res);
    system("pause");
    return 0;
}