#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

TreeNode* vector2Tree(const vector<int>& vec){
    vector<TreeNode*> vecTree(vec.size(), nullptr);
    TreeNode* root = nullptr;
    for(int i=0; i<vec.size(); i++){
        if(vec[i] != -1){
            TreeNode* node = new TreeNode(vec[i]);
            vecTree[i] = node;
            if(i == 0) root = node; 
        }
    }
    // 二叉树最后一层无需遍历
    for(int i=0; i*2+1<vec.size(); i++){
        if(vecTree[i]){
            vecTree[i]->left = vecTree[i*2+1];
            if(i*2+2 < vec.size()){
                vecTree[i]->right = vecTree[i*2+2];
            }
        }
    }
    return root;
}