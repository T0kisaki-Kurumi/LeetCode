// 19. 删除链表的倒数第 N 个结点
// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

// 示例 1：
// 输入：head = [1,2,3,4,5], n = 2
// 输出：[1,2,3,5]

// 示例 2：
// 输入：head = [1], n = 1
// 输出：[]

// 示例 3：
// 输入：head = [1,2], n = 1
// 输出：[1]

// 提示：

// 链表中结点的数目为 sz
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz

// 进阶：你能尝试使用一趟扫描实现吗？

#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(ListNode* next): val(0), next(next){}
    ListNode(int x, ListNode* next): val(0), next(next){}
};

ListNode* testVector2LinkedList(vector<int> a){
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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        while(n--){
            cur = cur->next;
        }
        while(cur != nullptr){
            cur = cur->next;
            pre = pre->next;
        }
        ListNode* tmp = pre->next;
        pre->next = tmp->next;
        delete tmp;
        tmp = nullptr;
        ListNode* newHead = dummyHead->next;
        delete dummyHead;
        dummyHead = nullptr;
        return newHead;
    }
};

int main(){
    vector<int> a = {1,2,3,4,5};
    int n = 2;
    Solution s;
    ListNode* list = testVector2LinkedList(a);
    printTestLinkedList(list);
    printTestLinkedList(s.removeNthFromEnd(list, n));
    system("pause");
    return 0;
}