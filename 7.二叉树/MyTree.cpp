#include <vector>
#include <queue>

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

void printTree(TreeNode* root){
    queue<TreeNode*> q;
    if(root) q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            TreeNode* cur = q.front();
            if(cur->val != INT_MIN) cout<<cur->val<<" ";
            else cout<<"* ";
            q.pop();
            if(cur->val != INT_MIN){
                if(cur->left) q.push(cur->left);
                else q.push(new TreeNode(INT_MIN));
                if(cur->right) q.push(cur->right);
                else q.push(new TreeNode(INT_MIN));
            }
        }
        cout<<endl;
    }
}

struct Node{
    int val;
    vector<Node*> children;
    Node(){}
    Node(int _val): val(_val){}
    Node(int _val, vector<Node*> _children): val(_val), children(_children){}
};