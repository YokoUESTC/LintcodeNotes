描述
  "不同的路径" 的跟进问题：
  现在考虑网格中有障碍物，那样将会有多少条不同的路径？
  网格中的障碍和空位置分别用 1 和 0 来表示。
样例
  如下所示在3x3的网格中有一个障碍物：

  [
    [0,0,0],
    [0,1,0],
    [0,0,0]
  ]
  一共有2条不同的路径从左上角到右下角。
思路
  和前一个问题类似，主要是网格中一些点不能走，写几个if语句判断就完事了。注意边界的初始化写法。（一开始问题出在这里）
代码
  class Solution {
public:
    /*
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // write your code here
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int dp[m][n];
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        dp[0][0]=1;
        for(int i=1;i<m;i++)
        {
            if(obstacleGrid[i][0]==1)
            dp[i][0]=0;
            else 
            dp[i][0]=dp[i-1][0];
        }
        for(int j=1;j<n;j++)
        {
            if(obstacleGrid[0][j]==1)
            dp[0][j]=0;
            else 
            dp[0][j]=dp[0][j-1];
        }
          
        for(int i=1;i<m;i++)
        {
          for(int j=1;j<n;j++)
          {
             if(obstacleGrid[i][j]==1)
             {
                 dp[i][j]=0;
             }
             else
             dp[i][j]=dp[i-1][j]+dp[i][j-1];
          }
        }
        return dp[m-1][n-1];
    }
};
