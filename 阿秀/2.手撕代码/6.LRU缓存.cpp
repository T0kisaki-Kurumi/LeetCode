// https://leetcode.cn/problems/lru-cache/

// 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
// 实现 LRUCache 类：
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

#include <iostream>
#include <unordered_map>

using namespace std;

class DoubleListNode{
public:
    int key;
    int value;
    DoubleListNode* pre;
    DoubleListNode* next;

public:
    DoubleListNode(): key(0), value(0), pre(nullptr), next(nullptr){}
    DoubleListNode(int key, int value): key(key), value(value), pre(nullptr), next(nullptr){}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->m_capacity = capacity;
        dummyHead = new DoubleListNode();
        dummyTail = new DoubleListNode();
        dummyHead->next = dummyTail;
        dummyTail->pre = dummyHead;
    }

    void removeNode(DoubleListNode* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
        delete node;
    }

    void addToHead(DoubleListNode* node){
        node->pre = dummyHead;
        node->next = dummyHead->next;
        dummyHead->next->pre = node;
        dummyHead->next = node;
    }

    void moveToHead(DoubleListNode* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
        addToHead(node);
    }
    
    int get(int key) {
        if(umap.count(key) == 0){
            return -1;
        }
        DoubleListNode* cur = umap[key];
        moveToHead(cur);
        return cur->value;
    }
    
    void put(int key, int value) {
        if(umap.count(key)){
            DoubleListNode* cur = umap[key];
            cur->value = value;
            moveToHead(cur);
        }
        else{
            if(umap.size() == m_capacity){
                int deleteKey = dummyTail->pre->key;
                removeNode(dummyTail->pre);
                umap.erase(deleteKey); // 别忘了哈希表也要删掉
            }
            DoubleListNode* cur = new DoubleListNode(key, value);
            umap[key] = cur;  // 别忘了哈希表也要加上
            addToHead(cur);
        }
    }

    int m_capacity;
    DoubleListNode* dummyHead;
    DoubleListNode* dummyTail;
    unordered_map<int, DoubleListNode*> umap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){

    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    cout<<lRUCache->get(1)<<endl;    // 返回 1
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout<<lRUCache->get(2)<<endl;    // 返回 -1 (未找到)
    lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout<<lRUCache->get(1)<<endl;    // 返回 -1 (未找到)
    cout<<lRUCache->get(3)<<endl;    // 返回 3
    cout<<lRUCache->get(4)<<endl;    // 返回 4

    system("pause");
}