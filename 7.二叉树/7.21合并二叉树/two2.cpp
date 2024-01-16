// 617. 合并二叉树
// 给你两棵二叉树： root1 和 root2 。

// 想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。

// 返回合并后的二叉树。

// 注意: 合并过程必须从两个树的根节点开始。

// 示例 1：
// 输入：root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
// 输出：[3,4,5,5,4,null,7]

// 示例 2：
// 输入：root1 = [1], root2 = [1,2]
// 输出：[2,2]

// 提示：

// 两棵树中的节点数目在范围 [0, 2000] 内
// -104 <= Node.val <= 104

#include <iostream>
#include <vector>
#include "../MyTree.cpp"

using namespace std;

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // 迭代
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;
        root1->val += root2->val;
        queue<TreeNode*> q1, q2;
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty()){
            TreeNode* cur1 = q1.front(); q1.pop();
            TreeNode* cur2 = q2.front(); q2.pop();
            if(cur1->left==nullptr && cur2->left!=nullptr){
                cur1->left = cur2->left;
            }
            else if(cur1->left!=nullptr && cur2->left!=nullptr){
                cur1->left->val += cur2->left->val;
                q1.push(cur1->left);
                q2.push(cur2->left);
            }
            if(cur1->right==nullptr && cur2->right!=nullptr){
                cur1->right = cur2->right;
            }
            else if(cur1->right!=nullptr && cur2->right!=nullptr){
                cur1->right->val += cur2->right->val;
                q1.push(cur1->right);
                q2.push(cur2->right);
            }
        }
        return root1;
    }
};

int main(){
    TreeNode* root1 = vector2Tree(vector<int>{1,3,2,5});
    TreeNode* root2 = vector2Tree(vector<int>{2,1,3,-1,4,-1,7});
    Solution s;
    TreeNode* res = s.mergeTrees(root1, root2);
    printTree(res);
    system("pause");
    return 0;
}