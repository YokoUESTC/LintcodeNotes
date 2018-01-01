Given a linked list, determine if it has a cycle in it.
思路很简单，使用两个不同速度的指针，如果他们再次相遇，则一定存在环


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
            {
                return true;               
            }
        }
        return false;
    
    }
};
