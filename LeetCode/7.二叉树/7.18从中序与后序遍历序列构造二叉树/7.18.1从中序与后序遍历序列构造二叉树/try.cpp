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
private:
    TreeNode* traversal(vector<int>& inorder, int inBegin, int inEnd, vector<int>& postorder, int postbegin, int postEnd){
        if(postbegin == postEnd) return nullptr;
        TreeNode* root = new TreeNode(postorder[postEnd - 1]);
        // 找到root在中序数组中的位置
        int rootIndex;
        for(rootIndex = inBegin; rootIndex < inEnd; rootIndex++){
            if(inorder[rootIndex] == root->val) break;
        }
        int lenLeft = rootIndex - inBegin;
        int lenRight = inEnd - 1 - rootIndex;
        root->left = traversal(inorder, inBegin, inBegin + lenLeft, postorder, postbegin, postbegin + lenLeft);
        root->right = traversal(inorder, rootIndex + 1, rootIndex + 1 + lenRight, postorder, postbegin + lenLeft, postbegin + lenLeft + lenRight);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty()) return nullptr;
        int size = inorder.size();
        return traversal(inorder, 0, size, postorder, 0, size);
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