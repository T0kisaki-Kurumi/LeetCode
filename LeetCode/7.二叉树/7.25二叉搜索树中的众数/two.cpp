// 501. 二叉搜索树中的众数
// 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。

// 如果树中有不止一个众数，可以按 任意顺序 返回。

// 假定 BST 满足如下定义：

// 结点左子树中所含节点的值 小于等于 当前节点的值
// 结点右子树中所含节点的值 大于等于 当前节点的值
// 左子树和右子树都是二叉搜索树

// 示例 1：
// 输入：root = [1,null,2,2]
// 输出：[2]

// 示例 2：
// 输入：root = [0]
// 输出：[0]

// 提示：

// 树中节点的数目在范围 [1, 104] 内
// -105 <= Node.val <= 105

// 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）

#include <iostream>
#include <vector>
#include <cmath>
#include "../MyTree.cpp"

using namespace std;

class Solution {
public:
    vector<int> res;
    int maxNum = 0;
    int curNum = 0;
    int pre = INT_MAX;
    void traversal(TreeNode* root){
        if(root == nullptr) return;
        traversal(root->left);
        if(root->val == pre) ++curNum;
        else{
            curNum = 1;
            pre = root->val;
        }
        if(curNum == maxNum){
            res.push_back(root->val);
        }
        else if(curNum > maxNum){
            res.clear();
            res.push_back(root->val);
            maxNum = curNum;
        }
        traversal(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return res;
    }
};

int main(){
    TreeNode* root = vector2Tree(vector<int>{1,-1,2,-1,-1,2});
    Solution s;
    vector<int> res = s.findMode(root);
    for(int i: res){
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}