// 707. 设计链表
// 你可以选择使用单链表或者双链表，设计并实现自己的链表。

// 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。

// 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

// 实现 MyLinkedList 类：

// MyLinkedList() 初始化 MyLinkedList 对象。
// int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
// void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
// void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
// void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
// void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
 

// 示例：

// 输入
// ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
// [[], [1], [3], [1, 2], [1], [1], [1]]
// 输出
// [null, null, null, null, 2, null, 3]

// 解释
// MyLinkedList myLinkedList = new MyLinkedList();
// myLinkedList.addAtHead(1);
// myLinkedList.addAtTail(3);
// myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
// myLinkedList.get(1);              // 返回 2
// myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
// myLinkedList.get(1);              // 返回 3

#include <iostream>
using namespace std;

// 约定俗成的顺序：public protected private
class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(): val(0), next(nullptr){}
        ListNode(int x): val(x), next(nullptr){}
        ListNode(ListNode* next): next(next){}
        ListNode(int x, ListNode* next): val(x), next(next){}
    };

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

private:
    ListNode* _dummyHead;
    int _size;
};

int main(){
    MyLinkedList list;
    list.addAtHead(5);
    list.addAtTail(0);
    list.addAtIndex(1,2);
    cout<<list.get(0);
    cout<<list.get(1);
    cout<<list.get(2);
    system("pause");
    return 0;
}