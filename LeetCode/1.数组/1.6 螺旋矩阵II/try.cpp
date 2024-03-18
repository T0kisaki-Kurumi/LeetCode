// 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

// 示例:

// 输入: 3 输出: [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ]

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> res(n, vector<int>(n, 0));
        vector<int> dir_y{1,0,-1,0};
        vector<int> dir_x{0,1,0,-1};
        int x = 0;
        int y = -1;
        int curNum = 1;
        for(int i=0; i<2*n-1; i++){
            int curStep = (int)(n-0.5*i);
            for(int j=0; j<curStep; j++){
                x += dir_x[i%4];
                y += dir_y[i%4];
                res[x][y] = curNum;
                curNum++;
            }
        }
        return res;
        // for(int i=0; i<step.size(); i++){
        //     cout<<step[i]<<" ";
        // }
    }
};

int main(){
    int n = 4;
    Solution s;
    vector<vector<int>> res = s.generateMatrix(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}