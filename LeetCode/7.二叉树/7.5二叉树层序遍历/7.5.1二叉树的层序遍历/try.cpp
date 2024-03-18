// 102. 二叉树的层序遍历
// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

// 示例 1：
// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[3],[9,20],[15,7]]

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
#include "../../MyTree.cpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        return res;
    }
};

int main(){
    vector<int> vec{3,9,20,-1,-1,15,7};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    for(auto i: s.levelOrder(root)){
        for(int j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}