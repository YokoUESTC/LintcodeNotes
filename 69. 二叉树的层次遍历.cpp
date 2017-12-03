给出一棵二叉树，返回其节点值的层次遍历（逐层从左往右访问）
样例
给一棵二叉树 {3,9,20,#,#,15,7} ：

  3
 / \
9  20
  /  \
 15   7
返回他的分层遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

分析：使用队列实现：遍历从根节点开始，首先将根节点入队，然后开始执行循环：结点出队、访问该节点、其左右儿子入队
  层序遍历的基本过程是：
  先根节点入队，然后：
  1.从队列中取出一个元素
  2.访问该元素所指的结点
  3.若该元素所指结点的左、右孩子结点非空，则将其左、右孩子的指针顺序入队
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
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> temp;
    vector<vector<int>> levelOrder(TreeNode * root) 
    {
        // write your code here
        if(root==NULL) return temp;
        queue<TreeNode*> que;
        int count;
        que.push(root);
        while(!que.empty())
        {
            vector<int> inner;
            count=que.size();
            while(count--)
            {
                TreeNode* tmp=que.front();
                inner.push_back(tmp->val);
                que.pop();
                if(tmp->left!=NULL)
                  que.push(tmp->left);
                if(tmp->right!=NULL)
                  que.push(tmp->right);
                
            }
        temp.push_back(inner);
            
        }
        return temp;
    }
};
