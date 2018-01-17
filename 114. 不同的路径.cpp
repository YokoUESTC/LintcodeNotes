描述
  有一个机器人的位于一个 m × n 个网格左上角。
  机器人每一时刻只能向下或者向右移动一步。机器人试图达到网格的右下角。
  问有多少条不同的路径？
样例
  给出 m = 3 和 n = 3, 返回 6.
  给出 m = 4 和 n = 5, 返回 35.
思路：
  使用一个二维数组dp[i][j]保存每一步走的方法，到最右下角的时候前一步只能来自上面和左边
  于是有了状态转移式 dp[i][j]=dp[i-1][j]+dp[i][j-1]
  需要注意的一点是，边界问题，就是i和j==0的时候
代码
  class Solution {
public:
    /*
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
        // write your code here
        int dp[m][n];
        for(int i=0;i<m;i++)
          dp[i][0]=1;
        for(int i=0;i<n;i++)
          dp[0][i]=1;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
              dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
