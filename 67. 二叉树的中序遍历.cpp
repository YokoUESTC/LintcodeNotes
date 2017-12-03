题目：给出一棵二叉树,返回其中序遍历
样例
给出二叉树 {1,#,2,3},

   1
    \
     2
    /
   3
返回 [1,3,2].
分析：
  递归的思路简单，中序遍历特点：左根右，即先遍历左子树，然后遍历根节点，再遍历右子树
  我在这里也使用了非递归的方法来写，利用了栈，一直遍历到左子树最下边，边遍历边保存根节点到栈中
  保存一路走过的根节点的理由是：中序遍历的需要，遍历完左子树后，需要借助根节点进入右子树。
Code：
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
     * @return: Inorder in ArrayList which contains node values.
     */
    //version2:no recursion非递归
    vector<int> inorderTraversal(TreeNode *root) 
    { 
        stack<TreeNode*> s;
        vector<int> res;
        if(root==NULL) return res;
        TreeNode* p=root;
        while(p!=NULL||!s.empty())
        {
           while(p!=NULL)
           {
               s.push(p);
               p=p->left;
           }
           if(!s.empty())
           {
               
               p=s.top();
               res.push_back(p->val);
               s.pop();
               p=p->right;
           }
        }
        return res;
    }
};
     
     
     
    version1:recursion
    vector<int> vec;
    vector<int> inorderTraversal(TreeNode *root) {
         //write your code here
        if(root==NULL){
            return vec;
        }
         
        if(root->left!=NULL){
            inorderTraversal(root->left);
        }
        vec.push_back(root->val);
         
        if(root->right!=NULL){
            inorderTraversal(root->right);
        }         
        return vec;
    }
};
