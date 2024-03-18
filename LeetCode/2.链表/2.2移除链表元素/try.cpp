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
        //头节点单独处理
        while(head != nullptr && head->val == val){
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        //处理非头节点
        ListNode* cur = head;
        while(cur != nullptr && cur->next != nullptr){  // cur != nullptr是为了防止头节点都删完了，cur变成nullptr
            if(cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            } else{
                cur = cur->next;
            }
        }
        return head;
    }
};



int main(){
    ListNode* head = new ListNode(1);
    ListNode* a = new ListNode(2);
    ListNode* b = new ListNode(6);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    ListNode* f = new ListNode(6);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

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