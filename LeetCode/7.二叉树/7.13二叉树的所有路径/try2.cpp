// 257. 二叉树的所有路径
// 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

// 叶子节点 是指没有子节点的节点。

// 示例 1：
// 输入：root = [1,2,3,null,5]
// 输出：["1->2->5","1->3"]

// 示例 2：
// 输入：root = [1]
// 输出：["1"]

// 提示：

// 树中节点的数目在范围 [1, 100] 内
// -100 <= Node.val <= 100

#include <iostream>
#include <string>
#include <stack>
#include "../MyTree.cpp"

using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        // 迭代法
        vector<string> res;
        stack<TreeNode*> stTree;
        stack<string> stPath;
        if(root){
            stTree.push(root);
            stPath.push(to_string(root->val));
        }
        while(!stTree.empty()){
            TreeNode* cur = stTree.top();
            stTree.pop();
            string curPath = stPath.top();
            stPath.pop();
            // 前序遍历
            if(cur->left == nullptr && cur->right == nullptr){
                res.push_back(curPath);
            }
            if(cur->right){
                stTree.push(cur->right);
                stPath.push(curPath + "->" + to_string(cur->right->val));
            }
            if(cur->left){
                stTree.push(cur->left);
                stPath.push(curPath + "->" + to_string(cur->left->val));
            }
        }
        return res;
    }
};

int main(){
    vector<int> vec{1,2,3,-1,5};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    vector<string> res = s.binaryTreePaths(root);
    for(string str: res){
        cout<<str<<endl;
    }
    system("pause");
    return 0;
}