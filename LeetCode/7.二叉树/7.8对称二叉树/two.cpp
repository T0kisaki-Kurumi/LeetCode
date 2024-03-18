// 101. 对称二叉树
// 给你一个二叉树的根节点 root ， 检查它是否轴对称。

// 示例 1：
// 输入：root = [1,2,2,3,4,4,3]
// 输出：true

// 示例 2：
// 输入：root = [1,2,2,null,3,null,3]
// 输出：false

// 提示：

// 树中节点数目在范围 [1, 1000] 内
// -100 <= Node.val <= 100

// 进阶：你可以运用递归和迭代两种方法解决这个问题吗？

#include <iostream>
#include <stack>
#include <vector>
#include "../MyTree.cpp"

using namespace std;

class Solution {
public:
    bool compare(TreeNode* node1, TreeNode* node2){
        if(node1==nullptr && node2!=nullptr) return false;
        if(node1!=nullptr && node2==nullptr) return false;
        if(node1==nullptr && node2==nullptr) return true;
        if(node1->val == node2->val){
            return compare(node1->left, node2->right) && compare(node1->right, node2->left);
        }
        else return false;
    }

    bool isSymmetric(TreeNode* root) {
        // 递归法
        if(root == nullptr) return true;
        return compare(root->left, root->right);
    }
};

int main(){
    vector<int> vec{1,2,2,3,4,4,3};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    bool res = s.isSymmetric(root);
    cout<<res;
    system("pause");
    return 0;
}