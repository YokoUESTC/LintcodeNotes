给出一棵二叉树，返回其节点值的前序遍历。
样例
给出一棵二叉树 {1,#,2,3},

   1
    \
     2
    /
   3
 返回 [1,2,3].
 
 分析：
   和中序遍历一样，分为递归和非递归写法。根据前序遍历规则：根左右。先根节点，后左子树，再右子树。
   首先，我们遍历左子树，边遍历并把根节点存入栈中，以后需借助这些节点进入右子树开启新一轮的循环。（所有的节点都可看做是根节点。）
   接下来就是：出栈，根据栈顶节点进入右子树。代码如下：
   Code：
```cpp
   /**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) 
    {
       stack<TreeNode *> s;
       vector<int> result;
       if(root==NULL) return result;
       TreeNode* p=root;
       
       while(p!=NULL||!s.empty())
       {
         while(p!=NULL)
         {
            result.push_back(p->val);
            s.push(p);
            p=p->left;
         }
         if(!s.empty())
         {
             p=s.top();
             s.pop();
             p=p->right;
         }
             
       }
       return result;
        
        
    }
};
 //version1:recursion
        // write your code here
        //if(root==NULL) return temp;
        //temp.push_back(root->val);
        //if(root->left!=NULL)
        //  preorderTraversal(root->left);
        //if(root->right!=NULL)
        //  preorderTraversal(root->right);
        //return temp;
```
