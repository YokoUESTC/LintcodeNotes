描述
  给定一个只含非负整数的m*n网格，找到一条从左上角到右下角的可以使数字和最小的路径。
思路
  属于矩阵类的动态规划，比较简单，注意边界，找到递推式，和数字三角形一个道理
代码
  class Solution {
public:
    /*
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        // write your code here
        int m=grid.size();
        int n=grid[0].size();
        int dp[m][n];
        dp[0][0]=grid[0][0];
        for(int j=1;j<m;j++)
           dp[j][0]=dp[j-1][0]+grid[j][0];
        for(int i=1;i<n;i++)
           dp[0][i]=dp[0][i-1]+grid[0][i];
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=min(dp[i][j-1],dp[i-1][j])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
    
};
