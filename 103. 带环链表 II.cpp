给定一个链表，如果链表中存在环，则返回到链表中环的起始节点，如果没有环，返回null。
样例
给出 -21->10->4->5, tail connects to node index 1，返回10
代码：
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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head)
    {
        // write your code here
        ListNode *fast=head;
        ListNode *slow=head;
        if(head==NULL) return NULL;
        if(head->next==NULL||head->next->next==NULL) return NULL;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                while(head!=slow)
                {
                    head=head->next;
                    slow=slow->next;
                }
                return head;
            }
               
        }
        return NULL;
        
    }
};


