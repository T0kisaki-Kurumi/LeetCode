// 513. 找树左下角的值
// 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

// 假设二叉树中至少有一个节点。

// 示例 1:
// 输入: root = [2,1,3]
// 输出: 1

// 示例 2:
// 输入: [1,2,3,4,null,5,6,null,null,7]
// 输出: 7

// 提示:

// 二叉树的节点个数的范围是 [1,104]
// -231 <= Node.val <= 231 - 1 

#include <iostream>
#include <queue>
#include "../MyTree.cpp"

using namespace std;

class Solution {
public:
    int maxDepth = INT_MIN;
    int res;
    void traversal(TreeNode* node, int depth){
        if(node->left == nullptr && node->right == nullptr){
            if(depth > maxDepth){
                // 这边把maxDepth替换掉，确保res等于每一层最左边的值
                maxDepth = depth;
                res = node->val;
            }
        }
        if(node->left) traversal(node->left, depth + 1);
        if(node->right) traversal(node->right, depth + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        // 递归法
        traversal(root, 0);
        return res;
    }
};

int main(){
    vector<int> vec{1,2,3,4,-1,5,6,-1,-1,-1,-1,7};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    int res = s.findBottomLeftValue(root);
    cout<<res;
    system("pause");
    return 0;
}