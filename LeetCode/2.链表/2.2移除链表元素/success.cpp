// 203.移除链表元素

// 题意：删除链表中等于给定值 val 的所有节点。

// 示例 1： 输入：head = [1,2,6,3,4,5,6], val = 6 输出：[1,2,3,4,5]

// 示例 2： 输入：head = [], val = 1 输出：[]

// 示例 3： 输入：head = [7,7,7,7], val = 7 输出：[]

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        //虚拟头结点（哨兵节点）
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = dummyHead;
        while(cur->next != nullptr){  // cur != nullptr是为了防止头节点都删完了，cur变成nullptr
            if(cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            } else{
                cur = cur->next;
            }
        }
        // 注意：
        // 1. 不能直接return head，因为head可能已经被删了
        // 2. 切记把dummyhead也删了
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};



int main(){
    ListNode* f = new ListNode(6);
    ListNode* e = new ListNode(5, f);
    ListNode* d = new ListNode(4, e);
    ListNode* c = new ListNode(3, d);
    ListNode* b = new ListNode(6, c);
    ListNode* a = new ListNode(2, b);
    ListNode* head = new ListNode(1, a);

    int val = 6;

    Solution s;
    ListNode* newHead = s.removeElements(head, val);
    ListNode* curNode = newHead;
    while(curNode != nullptr){
        cout<<curNode->val<<" ";
        curNode = curNode->next;
    }
    system("pause");
    return 0;
}