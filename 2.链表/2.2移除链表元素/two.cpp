// 203.移除链表元素

// 题意：删除链表中等于给定值 val 的所有节点。

// 示例 1： 输入：head = [1,2,6,3,4,5,6], val = 6 输出：[1,2,3,4,5]

// 示例 2： 输入：head = [], val = 1 输出：[]

// 示例 3： 输入：head = [7,7,7,7], val = 7 输出：[]

#include <iostream>
#include <vector>
#include "../MyLinkedList.cpp"
using namespace std;

class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = dummyHead;
        while(cur->next){
            if(cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            } else{
                cur = cur->next;
            }
            
        }
        ListNode* newHead = dummyHead->next;
        delete dummyHead;
        return newHead;
    }
};

int main(){
    ListNode* head = testVector2LinkedList(vector<int>{1,2,6,3,4,5,6});
    printTestLinkedList(head);
    int val = 6;
    Solution s;
    ListNode* newHead = s.removeElements(head, val);
    ListNode* curNode = newHead;
    printTestLinkedList(newHead);
    system("pause");
    return 0;
}