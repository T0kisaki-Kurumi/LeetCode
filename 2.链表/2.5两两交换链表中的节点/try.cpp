// 24. 两两交换链表中的节点
// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

 

// 示例 1：


// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]
// 示例 2：

// 输入：head = []
// 输出：[]
// 示例 3：

// 输入：head = [1]
// 输出：[1]
 

// 提示：

// 链表中节点的数目在范围 [0, 100] 内
// 0 <= Node.val <= 100

#include "../MyLinkedList.cpp"
#include <vector>
using namespace std;

class Solution{
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(head);
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        while((cur != nullptr) && (cur->next != nullptr)){
            ListNode* curNext = cur->next;
            pre->next = curNext;
            cur->next = curNext->next;
            curNext->next = cur;
            // cout<<pre->next->val<<" "<<pre->next->next->val<<endl;
            pre = cur;
            cur = cur->next;
        }
        head = dummyHead->next;
        delete dummyHead;
        dummyHead = nullptr;
        return head;
    }
};

int main(){
    vector<int> a{1,2,3,4,5};
    ListNode* head = testVector2LinkedList(a);
    printTestLinkedList(head);
    Solution s;
    ListNode* newHead = s.swapPairs(head);
    printTestLinkedList(newHead);
    system("pause");
    return 0;
}