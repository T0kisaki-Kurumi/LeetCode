// 669. 修剪二叉搜索树
// 给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。修剪树 不应该 改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在 唯一的答案 。

// 所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。

// 示例 1：
// 输入：root = [1,0,2], low = 1, high = 2
// 输出：[1,null,2]

// 示例 2：
// 输入：root = [3,0,4,null,2,null,null,1], low = 1, high = 3
// 输出：[3,2,null,1]

// 提示：

// 树中节点数在范围 [1, 104] 内
// 0 <= Node.val <= 104
// 树中每个节点的值都是 唯一 的
// 题目数据保证输入是一棵有效的二叉搜索树
// 0 <= low <= high <= 104

#include <iostream>
#include <vector>
#include "../MyTree.cpp"

using namespace std;

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 迭代
        if(root == nullptr) return root;
        // 不要和下面这样写，因为在移动过程中可能从小于low立即变成大于high
        // while(root != nullptr && root->val > high){
        //     root = root->right;
        // }
        // while(root != nullptr && root->val < low){
        //     root = root->left;
        // }
        while(root != nullptr && (root->val < low || root->val > high)){
            if(root->val < low) root = root->right;
            else root = root->left;
        }
        TreeNode* cur = root;
        while(cur){
            while(cur->left && cur->left->val < low){
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }
        cur = root;
        while(cur){
            while(cur->right && cur->right->val > high){
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }
};

int main(){
    TreeNode* root = vector2Tree(vector<int>{3,0,4,-1,2,-1,-1,-1,-1,1});
    int low = 1;
    int high = 3;
    Solution s;
    TreeNode* res = s.trimBST(root, low, high);
    printTree(res);
    system("pause");
    return 0;
}