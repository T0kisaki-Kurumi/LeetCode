// 94. 二叉树的中序遍历
// 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

// 示例 1：
// 输入：root = [1,null,2,3]
// 输出：[1,3,2]

// 示例 2：
// 输入：root = []
// 输出：[]

// 示例 3：
// 输入：root = [1]
// 输出：[1]

// 提示：

// 树中节点数目在范围 [0, 100] 内
// -100 <= Node.val <= 100

// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？

#include <vector>
#include <iostream>
#include <stack>
#include "../../MyTree.cpp"

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            if(cur != nullptr){
                st.pop();
                if(cur->right != nullptr) st.push(cur->right);
                st.push(cur);
                st.push(nullptr);
                if(cur->left != nullptr) st.push(cur->left);
            }
            else{
                st.pop();
                cur = st.top(); st.pop();
                res.emplace_back(cur->val);
            }
        }
        return res;
    }
};

int main(){
    vector<int> vec{5,4,6,1,2};
    TreeNode* root = vector2Tree(vec);
    Solution s;
    vector<int> res = s.inorderTraversal(root);
    for(int i: res){
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}