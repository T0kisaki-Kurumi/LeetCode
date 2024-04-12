// 124. 二叉树中的最大路径和
// 二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

// 路径和 是路径中各节点值的总和。

// 给你一个二叉树的根节点 root ，返回其 最大路径和 。

// 示例 1：
// 输入：root = [1,2,3]
// 输出：6

// 解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6

// 示例 2：
// 输入：root = [-10,9,20,null,null,15,7]
// 输出：42
// 解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42

// 提示：

// 树中节点数目范围是 [1, 3 * 104]
// -1000 <= Node.val <= 1000

#include <iostream>
#include <vector>
#include <stack>
#include "../7.二叉树/MyTree.cpp"

using namespace std;

class Solution {
public:
    int res = INT_MIN;

    int maxNode(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = max(maxNode(root->left), 0);
        int right = max(maxNode(root->right), 0);
        int sum = left + right + root->val;
        res = max(res, sum);
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root){
        maxNode(root);
        return res;
    }
};

int main(){
    TreeNode* node = vector2Tree(vector<int>{-10,9,20,-1,-1,15,7});
    Solution s;
    int res = s.maxPathSum(node);
    cout<<res<<endl;

    system("pause");
    return 0;
}