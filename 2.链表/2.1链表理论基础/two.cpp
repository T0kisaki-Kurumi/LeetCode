#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(ListNode* next): val(0), next(next){}
    ListNode(int x, ListNode* next): val(0), next(next){}
};

int main(){
    int a = 1;
    ListNode *head = new ListNode(5);
    ListNode *second = new ListNode(10);
    head -> next = second;
    cout<<head->val<<endl;
    cout<<head->next->val<<endl;
    system("pause");
    return 0;
}