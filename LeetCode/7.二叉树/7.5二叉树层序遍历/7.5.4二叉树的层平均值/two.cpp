// 637. 二叉树的层平均值
// 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。

// 示例 1：
// 输入：root = [3,9,20,null,null,15,7]
// 输出：[3.00000,14.50000,11.00000]
// 解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
// 因此返回 [3, 14.5, 11] 。

// 示例 2:
// 输入：root = [3,9,20,15,7]
// 输出：[3.00000,14.50000,11.00000]

// 提示：

// 树中节点数量在 [1, 104] 范围内
// -231 <= Node.val <= 231 - 1

#include <iostream>
#include <vector>
#include <queue>
#include "../../MyTree.cpp"

using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()){
            int size = q.size();
            double sum = 0;
            for(int i=0; i<size; ++i){
                TreeNode* cur = q.front();
                sum += cur->val; q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            res.push_back(sum / size);
        }
        return res;
    }
};

int main(){
    vector<int> vec{3,9,20,-1,-1,15,7};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    vector<double> res = s.averageOfLevels(root);
    for(auto i: res){
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}