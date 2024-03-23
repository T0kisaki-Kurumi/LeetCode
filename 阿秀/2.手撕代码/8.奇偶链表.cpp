// 328. 奇偶链表
// 给定单链表的头节点 head ，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。

// 第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。

// 请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。

// 你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* head2 = head->next;
        ListNode* cur1 = head;
        ListNode* cur2 = head->next;
        while(cur1->next && cur1->next->next){
            cur1->next = cur2->next;
            cur2->next = cur1->next->next;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        cur1->next = head2;
        return head;
    }
};


int main(){
    ListNode* n9 = new ListNode(9, nullptr);
    ListNode* n8 = new ListNode(8, n9);
    ListNode* n7 = new ListNode(7, n8);
    ListNode* n6 = new ListNode(6, n7);
    ListNode* n5 = new ListNode(5, n6);
    ListNode* n4 = new ListNode(4, n5);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(1, n2);

    Solution s;
    printList(n1);
    ListNode* head = s.oddEvenList(n1);
    printList(head);
    system("pause");
	return 0;
}