// 968. 监控二叉树
// 给定一个二叉树，我们在树的节点上安装摄像头。

// 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

// 计算监控树的所有节点所需的最小摄像头数量。

// 示例 1：
// 输入：[0,0,null,0,0]
// 输出：1
// 解释：如图所示，一台摄像头足以监控所有节点。

// 示例 2：
// 输入：[0,0,null,0,null,0,null,null,0]
// 输出：2
// 解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。

// 提示：

// 给定树的节点数的范围是 [1, 1000]。
// 每个节点的值都是 0。

#include <iostream>
#include <vector>
#include <string>
#include "../../7.二叉树/MyTree.cpp"

using namespace std;

class Solution {
private:
    int res;
    int traversal(TreeNode* root){
        //状态：0无覆盖  1有监控  2有覆盖
        if(root == nullptr) return 2;
        int left = traversal(root->left);
        int right = traversal(root->right);
        if(left == 0 || right == 0){
            ++res;
            return 1;
        }
        else if(left == 1 || right == 1){
            return 2;
        }
        else{ // left == 2 && right == 2
            return 0;
        }
    }
public:
    int minCameraCover(TreeNode* root) {
        if(traversal(root) == 0) ++res;
        return res;
    }
};

int main(){
    TreeNode* root = vector2Tree(vector<int>{0,0,-1,0,0});
    Solution sol;
    cout<<sol.minCameraCover(root);
    system("pause");
    return 0;
}