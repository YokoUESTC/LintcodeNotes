描述
  给定一个数字三角形，找到从顶部到底部的最小路径和。每一步可以移动到下面一行的相邻数字上。
样例
  比如，给出下列数字三角形：

  [
       [2],
      [3,4],
     [6,5,7],
    [4,1,8,3]
  ]
  从顶到底部的最小路径和为11 ( 2 + 3 + 5 + 1 = 11)。
思路
  采用动态规划，第一种使用自底向上，第二种使用自顶向下，注意边界问题
代码
class Solution {
public:
    /*
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
//自底向上
    int minimumTotal(vector<vector<int>> &triangle) {
        // write your code here
        //int n=triangle.size();
        //int f[n][n];
        //for(int i=0;i<n;i++)
           //f[n-1][i]=triangle[n-1][i];
        //for(int i=n-2;i>=0;i--)
        //{
            //for(int j=0;j<=triangle[i].size();j++)
            //{
                //f[i][j]=min(f[i+1][j],f[i+1][j+1])+triangle[i][j];
            //}
        //}
        //return f[0][0];
   //}
   //自顶向下
        int n=triangle.size();
        int f[n][n];
        int minn=INT_MAX;
        f[0][0]=triangle[0][0];
        if(n==1) return f[0][0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0)
                  f[i][j]=f[i-1][j]+triangle[i][j];
                else if(j==i)
                  f[i][j]=f[i-1][j-1]+triangle[i][j];
                else 
                  f[i][j]=min(f[i-1][j-1],f[i-1][j])+triangle[i][j];
                if(i==n-1)
                {
                  if(f[i][j]<minn)
                    minn=f[i][j];
                }
            }
        }
        return minn;
}
};


