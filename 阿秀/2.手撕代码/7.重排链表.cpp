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
    ListNode* findMid(ListNode* head){
        if(head == nullptr) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){
        if(head == nullptr) return head;
        ListNode* pre = nullptr;
        while(head){
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }

    void mergeList(ListNode* head1, ListNode* head2){
        while(head1 && head2){
            ListNode* tmp1 = head1->next;
            ListNode* tmp2 = head2->next;
            head1->next = head2;
            head2->next = tmp1;
            head1 = tmp1;
            head2 = tmp2;
        }
    }

    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        ListNode* mid = findMid(head);
        ListNode* tmp = mid;
        mid = mid->next;
        tmp->next = nullptr;
        ListNode* cur1 = head;
        ListNode* cur2 = reverseList(mid);
        // printList(cur2);
        mergeList(cur1, cur2);
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
    s.reorderList(n1);
    printList(n1);
    system("pause");
	return 0;
}