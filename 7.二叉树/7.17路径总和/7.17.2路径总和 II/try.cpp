// 113. 路径总和 II
// 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

// 叶子节点 是指没有子节点的节点。

// 示例 1：
// 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// 输出：[[5,4,11,2],[5,8,4,5]]

// 示例 2：
// 输入：root = [1,2,3], targetSum = 5
// 输出：[]

// 示例 3：
// 输入：root = [1,2], targetSum = 0
// 输出：[]

// 提示：

// 树中节点总数在范围 [0, 5000] 内
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000

#include <iostream>
#include <queue>
#include "../../MyTree.cpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void traversal(TreeNode* root, int targetSum){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr && root->val == targetSum){
            res.push_back(path);
        }
        if(root->left){
            path.push_back(root->left->val);
            traversal(root->left, targetSum - root->val);
            path.pop_back();
        }
        if(root->right){
            path.push_back(root->right->val);
            traversal(root->right, targetSum - root->val);
            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();
        path.clear();
        if(root == nullptr) return res;
        path.push_back(root->val);
        traversal(root, targetSum);
        return res;
    }
};

int main(){
    vector<int> vec{5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,5,1};
    TreeNode* root = vector2Tree(vec);
    int targetSum = 22;
    Solution s;
    vector<vector<int>> res = s.pathSum(root, targetSum);
    for(auto i: res){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}