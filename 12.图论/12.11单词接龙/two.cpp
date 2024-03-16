// 127. 单词接龙
// 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：

// 每一对相邻的单词只差一个字母。
//  对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
// sk == endWord
// 给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。

// 示例 1：
// 输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// 输出：5
// 解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。

// 示例 2：
// 输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// 输出：0
// 解释：endWord "cog" 不在字典中，所以无法进行转换。

// 提示：

// 1 <= beginWord.length <= 10
// endWord.length == beginWord.length
// 1 <= wordList.length <= 5000
// wordList[i].length == beginWord.length
// beginWord、endWord 和 wordList[i] 由小写英文字母组成
// beginWord != endWord
// wordList 中的所有字符串 互不相同

#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    unordered_map<string, int> umap;
    vector<vector<int>> edge;

    int addWord(string& s){
        if(umap.find(s) == umap.end()){
            umap.insert({s, umap.size()});
            edge.push_back({});
        }
        return umap[s];
    }

    void addEdge(string& s){
        int index1 = addWord(s);
        for(char& c: s){
            char tmp = c;
            c = '*';
            int index2 = addWord(s);
            edge[index1].push_back(index2);
            edge[index2].push_back(index1);
            c = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        addEdge(beginWord);
        for(string& s: wordList){
            addEdge(s);
        }
        // for(auto p: umap){
        //     cout<<p.first<<" "<<p.second<<endl;
        // }
        if(umap.find(endWord) == umap.end()) return 0;
        vector<int> dis(umap.size(), -1);
        dis[umap[beginWord]] = 0;
        queue<int> q;
        q.push(0);
        int targetIndex = umap[endWord];
        while(!q.empty()){
            int curIndex = q.front(); q.pop();
            for(int nextIndex: edge[curIndex]){
                // cout<<curIndex<<" "<<nextIndex<<" "<<dis[curIndex]<<endl;
                if(nextIndex == targetIndex){
                    return (dis[curIndex] + 1) / 2 + 1;
                }
                if(dis[nextIndex] == -1){
                    dis[nextIndex] = dis[curIndex] + 1;
                    q.push(nextIndex);
                }
            }
        }
        return 0;
    }
};

int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList{"hot","dot","dog","lot","log","cog"};
    Solution sol;
    int res = sol.ladderLength(beginWord, endWord,wordList);
    cout<<res<<endl;
    system("pause");
    return 0;
}