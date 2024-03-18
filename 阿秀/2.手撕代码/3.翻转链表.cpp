// 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
// 输入: 1->2->3->4->5->NULL 输出: 5->4->3->2->1->NULL

#include <iostream>
using namespace std;

struct myList{
    int val;
    myList* next;
    
    myList(int x, myList* node): val(x), next(node){}
};

void printList(myList* head){
    while(head != nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

myList* reverseList(myList* head){
    myList* dummyHead = nullptr;
    myList* pre = dummyHead;
    myList* cur = head;
    while(cur != nullptr){
        myList* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

int main(){
    myList head(1, new myList(2, new myList(4, new myList(5, nullptr))));

    myList* newHead = reverseList(&head);
    printList(newHead);

    system("pause");
    return 0;
}