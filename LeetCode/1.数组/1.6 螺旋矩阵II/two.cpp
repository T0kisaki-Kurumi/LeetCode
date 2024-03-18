// 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

// 示例:

// 输入: 3 输出: [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ]

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int dir[4][2] = {{1,0}, {0,-1}, {-1,0}, {0,1}};

    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        for(int i=0; i<n; ++i){
            res[0][i] = i+1;
        }
        if(n==1) return res;
        int cur_dir = 0;
        int cur_num = n+1;
        int num = n-1;
        int x = 0;
        int y = n-1;
        while(num > 0){
            for(int i=0; i<num; i++){
                x += dir[cur_dir%4][0];
                y += dir[cur_dir%4][1];
                res[x][y] = cur_num++;
            }
            cur_dir++;
            for(int i=0; i<num; i++){
                x += dir[cur_dir%4][0];
                y += dir[cur_dir%4][1];
                res[x][y] = cur_num++;
            }
            cur_dir++;
            num--;
        }
        return res;
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