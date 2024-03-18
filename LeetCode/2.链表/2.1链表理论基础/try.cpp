#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main(){
    int a = 1;
    ListNode *head = new ListNode(5);
    ListNode *second = new ListNode(10);
    head -> next = second;
    cout<<head->val<<endl;
    cout<<head->next->val;
    system("pause");
    return 0;
}