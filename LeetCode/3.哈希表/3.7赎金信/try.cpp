// 383. 赎金信
// 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

// 如果可以，返回 true ；否则返回 false 。

// magazine 中的每个字符只能在 ransomNote 中使用一次。

// 示例 1：
// 输入：ransomNote = "a", magazine = "b"
// 输出：false

// 示例 2：
// 输入：ransomNote = "aa", magazine = "ab"
// 输出：false

// 示例 3：
// 输入：ransomNote = "aa", magazine = "aab"
// 输出：true

// 提示：

// 1 <= ransomNote.length, magazine.length <= 105
// ransomNote 和 magazine 由小写英文字母组成

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int cur = 0;
        for(int i=0; i<ransomNote.length(); i++){
            while(cur < magazine.length() && magazine[cur] < ransomNote[i]){
                cur++;
            }
            if(cur >= magazine.length()){
                return false;
            }
            if(magazine[cur] > ransomNote[i]){
                return false;
            }
            if(magazine[cur] == ransomNote[i]){
                cur++;
            }
        }
        return true;
    }
};

int main(){
    string s1 = "aa";
    string s2 = "aab";
    Solution s;
    cout<<s.canConstruct(s1, s2);
    system("pause");
    return 0;
}