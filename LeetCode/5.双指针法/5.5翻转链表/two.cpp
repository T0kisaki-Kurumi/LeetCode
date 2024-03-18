// 206. 反转链表
// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

// 示例 1：
// 输入：head = [1,2,3,4,5]
// 输出：[5,4,3,2,1]

// 示例 2：
// 输入：head = [1,2]
// 输出：[2,1]

// 示例 3：
// 输入：head = []
// 输出：[]
 
// 提示：

// 链表中节点的数目范围是 [0, 5000]
// -5000 <= Node.val <= 5000

// 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

int main(){
    vector<int> a = {1,2,3,4,5};
    Solution s;
    ListNode* list = testVector2LinkedList(a);
    printTestLinkedList(list);
    printTestLinkedList(s.reverseList(list));
    system("pause");
    return 0;
}