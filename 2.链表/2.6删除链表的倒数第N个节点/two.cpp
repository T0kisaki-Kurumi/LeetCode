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

#include "../MyLinkedList.cpp"
#include <vector>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        n++;
        while(n--){
            fast = fast->next;
        }
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        ListNode* newHead = dummyHead->next;
        delete dummyHead;
        return newHead;
    }
};

int main(){
    vector<int> a{1,2,3,4,5};
    ListNode* head = testVector2LinkedList(a);
    printTestLinkedList(head);
    Solution s;
    ListNode* newHead = s.removeNthFromEnd(head,2);
    printTestLinkedList(newHead);

    system("pause");
    return 0;
}