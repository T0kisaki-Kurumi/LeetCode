// 199. 二叉树的右视图
// 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

// 示例 1:
// 输入: [1,2,3,null,5,null,4]
// 输出: [1,3,4]

// 示例 2:
// 输入: [1,null,3]
// 输出: [1,3]

// 示例 3:
// 输入: []
// 输出: []

// 提示:

// 二叉树的节点个数的范围是 [0,100]
// -100 <= Node.val <= 100

#include <iostream>
#include <vector>
#include <queue>
#include "../../MyTree.cpp"

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* cur = q.front(); q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                if(size == 0) res.push_back(cur->val);
            }
        }
        return res;
    }
};

int main(){
    vector<int> vec{1,2,3,-1,5,-1,4};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    vector<int> res = s.rightSideView(root);
    for(int i: res){
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}