// 135. 分发糖果
// n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

// 你需要按照以下要求，给这些孩子分发糖果：

// 每个孩子至少分配到 1 个糖果。
// 相邻两个孩子评分更高的孩子会获得更多的糖果。
// 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

// 示例 1：
// 输入：ratings = [1,0,2]
// 输出：5
// 解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。

// 示例 2：
// 输入：ratings = [1,2,2]
// 输出：4
// 解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
//      第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。

// 提示：

// n == ratings.length
// 1 <= n <= 2 * 104
// 0 <= ratings[i] <= 2 * 104

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        // int pre_index = 0;  //上一个递增序列的结尾的序号（不是糖果数）
        int pre = 1;  //上一个递增序列的结尾的糖果数
        int decline = 0;  //当前递减序列长度
        int cur = 1; //当前糖果数
        int sum = 1;
        int len = ratings.size();
        for(int i=1; i<len; ++i){
            if(ratings[i]>ratings[i-1]){
                cur += 1;
                sum += cur;
                decline = 0;
                pre = cur;
            }
            else if(ratings[i]==ratings[i-1]){
                cur = 1;
                sum += cur;
                decline = 0;
                pre = cur;
            }
            else{
                ++decline;
                if(decline == pre) ++decline;
                sum += decline;
                cur = 1;
            }
        }
        return sum;
    }
};

int main(){
    vector<int> ratings{1,3,2,2,1};
    Solution sol;
    cout<<sol.candy(ratings);
    system("pause");
    return 0;
}