// 142. 环形链表 II
// 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

// 不允许修改 链表。

// 示例 1：
// 输入：head = [3,2,0,-4], pos = 1
// 输出：返回索引为 1 的链表节点
// 解释：链表中有一个环，其尾部连接到第二个节点。

// 示例 2：
// 输入：head = [1,2], pos = 0
// 输出：返回索引为 0 的链表节点
// 解释：链表中有一个环，其尾部连接到第一个节点。

// 示例 3:
// 输入：head = [1], pos = -1
// 输出：返回 null
// 解释：链表中没有环。

// 提示：

// 链表中节点的数目范围在范围 [0, 104] 内
// -105 <= Node.val <= 105
// pos 的值为 -1 或者链表中的一个有效索引

// 进阶：你是否可以使用 O(1) 空间解决此题？

#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(!fast || !fast->next) return nullptr;
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main(){
    vector<int> a = {3,2,0,-4};
    Solution s;
    ListNode* list = testVector2LinkedList(a);
    printTestLinkedList(list);
    list->next->next->next->next = list->next;
    ListNode* newList = s.detectCycle(list);
    // printTestLinkedList(newList);
    cout<<newList->val<<endl;
    system("pause");
    return 0;
}