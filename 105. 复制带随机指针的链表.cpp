描述
给出一个链表，每个节点包含一个额外增加的随机指针可以指向链表中的任何节点或空的节点。
返回一个深拷贝的链表。

代码：使用了两种不同的方法来实现

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        //1.使用map
    //     if(!head) return NULL;
    //     map<RandomListNode*,RandomListNode*> m;
    //     RandomListNode *res=new RandomListNode(head->label);
    //     RandomListNode *cur=head->next;
    //     RandomListNode *node=res;
    //     m[head]=res;
    //     while(cur!=NULL)
    //     {
    //         RandomListNode *tmp=new RandomListNode(cur->label);
    //         node->next=tmp;
    //         m[cur]=tmp;
    //         node=node->next;
    //         cur=cur->next;
    //     }
    //     node=res;
    //     cur=head;
    //     while(node!=NULL)
    //     {
    //         node->random=m[cur->random];
    //         node=node->next;
    //         cur=cur->next;
    //     }
    //     return res;
       //2.在原链表上操作
       if(!head) return NULL;
       RandomListNode *cur=head;
       while(cur)
       {
           RandomListNode *node=new RandomListNode(cur->label);
           node->next=cur->next;
           cur->next=node;
           cur=node->next;
       }
       cur=head;
       while(cur)
       {
           if(cur->random)
             cur->next->random=cur->random->next;
           cur=cur->next->next;
       }
       cur=head->next;
       RandomListNode *res=head->next;
       RandomListNode *pre=res;
       while(cur)
       {
           pre->next=cur->next;
           if(cur->next) cur->next=cur->next->next;
           pre=pre->next;
           cur=cur->next;
       }
       return res;
       
    }
};
