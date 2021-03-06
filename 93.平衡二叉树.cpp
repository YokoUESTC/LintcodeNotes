lintcode第93题，给定一个二叉树,确定它是高度平衡的。对于这个问题,一棵高度平衡的二叉树的定义是：一棵二叉树中每个节点的两个子树的深度相差不会超过1。 
样例
  给出二叉树 A={3,9,20,#,#,15,7}, B={3,#,20,15,7}
  A)  3            B)    3 
     / \                  \
    9  20                 20
      /  \                / \
     15   7              15  7
  二叉树A是高度平衡的二叉树，但是B不是
分析:
  解决这个问题首先是要理解平衡二叉树的概念，左右子树深度差不超过一，那么就可以先求出左子树最大深度（maxDepth）再求出右子树的最大深度
  从而进行一个if比较，即可。
code:
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
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) 
    {
        // write your code here
        if(root==NULL) return true;
        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;
        int hleft=maxDepth(root->left);
        int hright=maxDepth(root->right);
        if(abs(hleft-hright)>1) return false;
        return true;
        
    }
    int maxDepth(TreeNode *root) {
        if(root==NULL) return 0;
        int hl=maxDepth(root->left);
        int hr=maxDepth(root->right);
        if(hl>hr)
            return hl+1;
        else
            return hr+1;
    }
};
