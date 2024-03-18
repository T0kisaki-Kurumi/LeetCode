#include <iostream>
#include <vector>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(ListNode* next): next(next){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class MyLinkedList {
public:


    MyLinkedList() {
        _dummyHead = new ListNode();
        _size = 0;
    }
    
    // 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。注意index是从0开始的，0就是头结点。
    int get(int index) {
        if(index < 0 or index >= _size){
            return -1;
        }
        ListNode* cur = _dummyHead->next;
        while(index--){ //注意是index--，不是--index，否则index大于0时结果错误，等于0时死循环
            cur = cur->next;
        }
        return cur->val;
    }
    
    // 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
    void addAtHead(int val) {
        ListNode* tmp = new ListNode(val, _dummyHead->next);
        _dummyHead->next = tmp;
        _size++; //别忘了_size
    }
    
    // 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
    void addAtTail(int val) {
        ListNode* cur = _dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        ListNode* tmp = new ListNode(val);
        cur->next = tmp;
        _size++;
    }
    
    // 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。
    // 如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。
    // 如果 index 比长度更大，该节点将 不会插入 到链表中。
    void addAtIndex(int index, int val) {
        if(index >= 0 && index <=_size){
            ListNode* tmp = new ListNode(val);
            ListNode* cur = _dummyHead;
            while(index--){
                cur = cur->next;
            }
            tmp->next = cur->next;
            cur->next = tmp;
            _size++;
        }
    }
    
    // 如果下标有效，则删除链表中下标为 index 的节点。
    void deleteAtIndex(int index) {
        if(index >= 0 && index <_size){
            ListNode* cur = _dummyHead;
            while(index--){
                cur = cur->next;
            }
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
            tmp = nullptr; // 也就是被delete后，如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针,如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
            _size--;
        }
    }

    // 打印链表
    void printLinkedList(){
        ListNode* cur = _dummyHead;
        while(cur->next != nullptr){
            std::cout<<cur->next->val<<" ";
            cur = cur->next;
        }
        std::cout<<std::endl;
    }

private:
    ListNode* _dummyHead;
    int _size;
};

ListNode* testVector2LinkedList(std::vector<int> a){
    ListNode* head = nullptr;
    ListNode* pre = nullptr;
    for(int i=0; i<a.size(); i++){
        ListNode* cur = new ListNode(a[i]);
        if(i == 0){
            head = cur;
            pre = cur;
        } else{
            pre->next = cur;
            pre = cur;
        }
    }
    return head;
}

void printTestLinkedList(ListNode* head){
    ListNode* cur = head;
    while(cur != nullptr){
        std::cout<<cur->val<<" ";
        cur = cur->next;
    }
    std::cout<<std::endl;
}