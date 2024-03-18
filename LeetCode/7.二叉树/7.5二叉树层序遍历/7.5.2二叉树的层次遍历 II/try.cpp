// 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

// 示例 1：
// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[15,7],[9,20],[3]]

// 示例 2：
// 输入：root = [1]
// 输出：[[1]]

// 示例 3：
// 输入：root = []
// 输出：[]

// 提示：

// 树中节点数目在范围 [0, 2000] 内
// -1000 <= Node.val <= 1000

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "../../MyTree.cpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> curVec;
            int size = q.size();
            while(size--){
                TreeNode* cur = q.front();
                curVec.push_back(cur->val);
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            res.push_back(curVec);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    vector<int> vec{3,9,20,-1,-1,15,7};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    for(auto i: s.levelOrderBottom(root)){
        for(int j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}