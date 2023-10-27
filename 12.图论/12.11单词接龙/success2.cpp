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
    unordered_map<string, int> wordId;
    vector<vector<int>> edge;
    int curId = 0;

    void addWord(string& word){
        if(!wordId.count(word)){
            wordId[word] = curId++;
            edge.emplace_back();
        }
    }

    void addEdge(string& word){
        addWord(word);
        int id1 = wordId[word];
        for(char& c: word){
            char tmp = c;
            c = '*';
            addWord(word);
            int id2 = wordId[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1); //建立边
            c = tmp;
        }
    }

    // 双向BFS
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        addEdge(beginWord);
        for(string& word: wordList){
            addEdge(word);
        }
        if(!wordId.count(endWord)) return 0;

        vector<int> disBegin(curId, INT_MAX);
        int beginId = wordId[beginWord];
        disBegin[beginId] = 0;
        queue<int> queBegin;
        queBegin.push(beginId);

        vector<int> disEnd(curId, INT_MAX);
        int endId = wordId[endWord];
        disEnd[endId] = 0;
        queue<int> queEnd;
        queEnd.push(endId);

        while (!queBegin.empty() && !queEnd.empty()) {
            int queBeginSize = queBegin.size();
            for (int i = 0; i < queBeginSize; ++i) {
                int nodeBegin = queBegin.front();
                queBegin.pop();
                if (disEnd[nodeBegin] != INT_MAX) {
                    return (disBegin[nodeBegin] + disEnd[nodeBegin]) / 2 + 1;
                }
                for (int& it : edge[nodeBegin]) {
                    if (disBegin[it] == INT_MAX) {
                        disBegin[it] = disBegin[nodeBegin] + 1;
                        queBegin.push(it);
                    }
                }
            }

            int queEndSize = queEnd.size();
            for (int i = 0; i < queEndSize; ++i) {
                int nodeEnd = queEnd.front();
                queEnd.pop();
                if (disBegin[nodeEnd] != INT_MAX) {
                    return (disBegin[nodeEnd] + disEnd[nodeEnd]) / 2 + 1;
                }
                for (int& it : edge[nodeEnd]) {
                    if (disEnd[it] == INT_MAX) {
                        disEnd[it] = disEnd[nodeEnd] + 1;
                        queEnd.push(it);
                    }
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