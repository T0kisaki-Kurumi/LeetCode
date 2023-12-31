// 144. 二叉树的前序遍历
// 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

// 示例 1：
// 输入：root = [1,null,2,3]
// 输出：[1,2,3]

// 示例 2：
// 输入：root = []
// 输出：[]

// 示例 3：
// 输入：root = [1]
// 输出：[1]

// 示例 4：
// 输入：root = [1,2]
// 输出：[1,2]

// 示例 5：
// 输入：root = [1,null,2]
// 输出：[1,2]

// 提示：

// 树中节点数目在范围 [0, 100] 内
// -100 <= Node.val <= 100

// 进阶：递归算法很简单，你可以通过迭代算法完成吗？

#include <vector>
#include <iostream>
#include <stack>
#include "../../MyTree.cpp"

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            if(cur != nullptr){
                st.pop();
                if(cur->right != nullptr) st.push(cur->right);
                if(cur->left != nullptr) st.push(cur->left);
                st.push(cur);
                st.push(nullptr);
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
    vector<int> res = s.preorderTraversal(root);
    for(int i: res){
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}