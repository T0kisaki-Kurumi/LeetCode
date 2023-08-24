// 515. 在每个树行中找最大值
// 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。

// 示例1：
// 输入: root = [1,3,2,5,3,null,9]
// 输出: [1,3,9]

// 示例2：
// 输入: root = [1,2,3]
// 输出: [1,3]

// 提示：

// 二叉树的节点个数的范围是 [0,104]
// -231 <= Node.val <= 231 - 1

#include <iostream>
#include <vector>
#include <queue>
#include "../../MyTree.cpp"

using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int curMax = INT_MIN;
            while(size--){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                curMax = cur->val > curMax ? cur->val : curMax;
            }
            res.push_back(curMax);
        }
        return res;
    }
};

int main(){
    vector<int> vec{1,3,2,5,3,-1,9};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    vector<int> res = s.largestValues(root);
    for(int i: res){
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}