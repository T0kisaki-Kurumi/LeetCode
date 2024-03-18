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

#include "../MyLinkedList.cpp"
#include <vector>
using namespace std;

class Solution{
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr; // 如果没有这一句会导致原来的head的next没有指向nullptr，形成环。
        return newHead;
    }
};

int main(){
    vector<int> a{1,2,3,4,5};
    ListNode* head = testVector2LinkedList(a);
    printTestLinkedList(head);
    Solution s;
    ListNode* newHead = s.reverseList(head);
    printTestLinkedList(newHead);
    system("pause");
    return 0;
}