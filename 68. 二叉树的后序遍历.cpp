给出一棵二叉树，返回其节点值的后序遍历。
样例
给出一棵二叉树 {1,#,2,3},

   1
    \
     2
    /
   3
返回 [3,2,1]
分析：
  后序遍历递归定义：先左子树，后右子树，再根节点。后序遍历的难点在于：需要判断上次访问的节点是位于左子树，还是右子树。
  若是位于左子树，则需跳过根节点，先进入右子树，再回头访问根节点；若是位于右子树，则直接访问根节点。
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
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root)
    { 
        vector<int> res;
        stack<TreeNode*> s;
        if(root==NULL) return res;
        TreeNode* pcur;
        TreeNode* pre=NULL;
        s.push(root);
        while(!s.empty())
        {
            pcur=s.top();
            //pcur栈顶元素为叶节点或者栈顶元素的左右节点已被访问过了，则直接访问栈顶元素
            if((pcur->left==NULL&&pcur->right==NULL)||((pre!=NULL)&&(pre==pcur->left||pre==pcur->right)))
            {
                res.push_back(pcur->val);
                pre=pcur;
                s.pop();
            }
            else
            { 
                if(pcur->right!=NULL)
                s.push(pcur->right);
                if(pcur->left!=NULL)
                s.push(pcur->left);
                
            }
        }
        return res;
    }
};    
    //version1:recursion
    //vector<int> temp;
    //vector<int> postorderTraversal(TreeNode * root) 
    //{
        // write your code here
        //if(root==NULL) return temp;
        //if(root->left!=NULL)
        //  postorderTraversal(root->left);
        //if(root->right!=NULL)
        //  postorderTraversal(root->right);
        //temp.push_back(root->val);
        //return temp;
    //}
//};
