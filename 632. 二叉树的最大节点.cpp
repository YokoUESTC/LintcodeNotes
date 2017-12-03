在二叉树中寻找值最大的节点并返回。
样例
给出如下一棵二叉树：

     1
   /   \
 -5     2
 / \   /  \
0   3 -4  -5 
返回值为 3 的节点。
分析：
  思路较为简单，分别递归遍历左右子树，将值大的节点保存在root中，继续递归。代码如下
Code：
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return the max node
     */
    TreeNode* maxNode(TreeNode* root) 
    {
        // Write your code here
        if(root==NULL) return NULL;
        TreeNode *left=root;
        TreeNode *right=root;
        if(root->left!=NULL)
          left=maxNode(root->left);
        if(root->right!=NULL)
          right=maxNode(root->right);
        if(root->val<left->val)
          root->val=left->val;
        if(root->val<right->val)
          root->val=right->val;
        return root;
    }
};
