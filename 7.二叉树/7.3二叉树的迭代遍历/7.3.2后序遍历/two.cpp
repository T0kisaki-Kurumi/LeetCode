// 145. 二叉树的后序遍历
// 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。

// 示例 1：
// 输入：root = [1,null,2,3]
// 输出：[3,2,1]

// 示例 2：
// 输入：root = []
// 输出：[]

// 示例 3：
// 输入：root = [1]
// 输出：[1]

// 提示：

// 树中节点的数目在范围 [0, 100] 内
// -100 <= Node.val <= 100

// 进阶：递归算法很简单，你可以通过迭代算法完成吗？

#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include "../../MyTree.cpp"

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top(); st.pop();
            res.emplace_back(cur->val);
            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    vector<int> vec{5,4,6,1,2};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    vector<int> res = s.postorderTraversal(root);
    for(int i: res){
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}