描述
给定一个链表，判断它是否有环。
样例
给出 -21->10->4->5, tail connects to node index 1，返回 true

代码
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) 
    {
        // write your code here
        ListNode *fast=head;
        ListNode *slow=head;
        if(head==NULL) return false;
        if(head->next==NULL||head->next->next==NULL) return false;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
               return true;
        }
        return false;
    }
};


