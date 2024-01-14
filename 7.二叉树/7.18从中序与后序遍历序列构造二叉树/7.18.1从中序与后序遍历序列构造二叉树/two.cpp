// 106. 从中序与后序遍历序列构造二叉树

// 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

// 示例 1:
// 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// 输出：[3,9,20,null,null,15,7]

// 示例 2:
// 输入：inorder = [-1], postorder = [-1]
// 输出：[-1]

// 提示:

// 1 <= inorder.length <= 3000
// postorder.length == inorder.length
// -3000 <= inorder[i], postorder[i] <= 3000
// inorder 和 postorder 都由 不同 的值组成
// postorder 中每一个值都在 inorder 中
// inorder 保证是树的中序遍历
// postorder 保证是树的后序遍历
// 0 1 2 3 4
#include <iostream>
#include <vector>
#include "../../MyTree.cpp"

using namespace std;

class Solution {
public:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder, int begin_in, int end_in, int begin_po, int end_po){
        if(begin_in > end_in) return nullptr;
        int root_val = postorder[end_po];
        TreeNode* root = new TreeNode(root_val);
        int root_pos;
        for(root_pos=begin_in; root_pos<=end_in; ++root_pos){
            if(inorder[root_pos] == root_val) break;
        }
        root->left = traversal(inorder, postorder, begin_in, root_pos-1, begin_po, begin_po + (root_pos-1 - begin_in));
        root->right = traversal(inorder, postorder, root_pos+1, end_in, begin_po + (root_pos - begin_in), end_po-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        return traversal(inorder, postorder, 0, size-1, 0, size-1);
    }
};

int main(){
    Solution s;
    vector<int> inorder{9,3,15,20,7};
    vector<int> postororder{9,15,7,20,3};
    TreeNode* root = s.buildTree(inorder, postororder);
    printTree(root);
    system("pause");
    return 0;
}