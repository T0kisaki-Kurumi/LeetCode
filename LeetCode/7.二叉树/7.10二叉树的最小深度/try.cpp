// 111. 二叉树的最小深度
// 给定一个二叉树，找出其最小深度。

// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

// 说明：叶子节点是指没有子节点的节点。

// 示例 1：
// 输入：root = [3,9,20,null,null,15,7]
// 输出：2

// 示例 2：
// 输入：root = [2,null,3,null,4,null,5,null,6]
// 输出：5

// 提示：

// 树中节点数的范围在 [0, 105] 内
// -1000 <= Node.val <= 1000

#include <iostream>
#include <vector>
#include <queue>
#include "../MyTree.cpp"

using namespace std;

class Solution {
public:
    int res = INT_MAX;

    void getHeight(TreeNode* root, int depth){
        if(root == nullptr) return;
        if(depth > res) return;
        if(root->left == nullptr && root->right == nullptr){
            res = min(res, depth);
        }
        if(root->left) getHeight(root->left, depth+1);
        if(root->right) getHeight(root->right, depth+1);
    }

    int minDepth(TreeNode* root) {
        // 递归法
        if(root == nullptr) return 0;
        getHeight(root, 1);
        return res;
    }
};

int main(){
    vector<int> vec{3,9,20,-1,-1,15,7};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    int depth = s.minDepth(root);
    cout<<depth;
    system("pause");
    return 0;
}