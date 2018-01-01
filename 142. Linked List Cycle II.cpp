Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.




代码：
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
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
