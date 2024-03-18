// 105. 从前序与中序遍历序列构造二叉树
// 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

// 示例 1:
// 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// 输出: [3,9,20,null,null,15,7]

// 示例 2:
// 输入: preorder = [-1], inorder = [-1]
// 输出: [-1]

// 提示:

// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder 和 inorder 均 无重复 元素
// inorder 均出现在 preorder
// preorder 保证 为二叉树的前序遍历序列
// inorder 保证 为二叉树的中序遍历序列

#include <iostream>
#include <vector>
#include "../../MyTree.cpp"

using namespace std;

class Solution {
private:
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder, int beginPre, int endPre, int beginIn, int endIn){
        if(beginPre > endPre) return nullptr;
        int rootVal = preorder[beginPre];
        TreeNode* root = new TreeNode(rootVal);
        int rootPos;
        for(rootPos=beginIn; rootPos<=endIn; ++rootPos){
            if(inorder[rootPos] == rootVal) break;
        }
        root->left = traversal(preorder, inorder, beginPre+1, beginPre+1 + (rootPos-1 - beginIn), beginIn, rootPos-1);
        root->right = traversal(preorder, inorder, beginPre+1 + (rootPos-1 - beginIn) + 1, endPre, rootPos+1, endIn);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        return traversal(preorder, inorder, 0, size-1, 0, size-1);
    }
};

int main(){
    Solution s;
    vector<int> inorder{3,9,20,15,7};
    vector<int> postororder{9,3,15,20,7};
    TreeNode* root = s.buildTree(inorder, postororder);
    printTree(root);
    system("pause");
    return 0;
}