// 将两个有序的链表合并为一个新链表，要求新的链表是通过拼接两个链表的节点来生成的。

#include <iostream>
using namespace std;

struct myList{
    int val;
    myList* next;
    
    myList(int x, myList* node): val(x), next(node){}
};

myList* merge(myList* head1, myList* head2){
    myList dummyHead(0, nullptr);
    myList* cur = &dummyHead;
    while(head1!=nullptr && head2!=nullptr){
        if(head1->val <= head2->val){
            cur->next = head1;
            head1 = head1->next;
            cur = cur->next;
        }
        else{
            cur->next = head2;
            head2 = head2->next;
            cur = cur->next;
        }
        if(head1 == nullptr) cur->next = head2;
        if(head2 == nullptr) cur->next = head1;
    }
    return dummyHead.next;
}

void printList(myList* head){
    while(head != nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    myList head1(1, new myList(2, new myList(4, nullptr)));
    myList head2(1, new myList(3, new myList(4, nullptr)));

    myList* newHead = merge(&head1, &head2);
    printList(newHead);

    system("pause");
    return 0;
}