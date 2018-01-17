描述
  我们有一个栅栏，它有n个柱子，现在要给柱子染色，有k种颜色可以染。
  必须保证不存在超过2个相邻的柱子颜色相同，求有多少种染色方案。
样例
  n = 3, k = 2, return 6

        post 1,   post 2, post 3
  way1    0         0       1 
  way2    0         1       0
  way3    0         1       1
  way4    1         0       0
  way5    1         0       1
  way6    1         1       0
思路
  最后两根柱子颜色相同
  最后两根柱子颜色不同
  对于第一种情况，最后两根柱子颜色相同，不能三根柱子颜色连续相同，所以最后两根柱子的颜色选择有k-1种，所以dp[i-2]k-1
  对于第二种情况，最后两根柱子颜色不同，那么最后一根柱子的颜色有k-1种选择方案，所以dp[i-1]k-1
  所以综上，我们就得出状态转移方程为：
  dp[i] = dp[i-1] * (k-1) + dp[i-2] * (k-1);
  初始条件：
  dp[0] = k; dp[1] = k*k;
代码
  class Solution {
public:
    /*
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // write your code here
        int *dp=new int[n];
        dp[0]=k;
        dp[1]=k*k;
        for(int i=2;i<n;i++)
        {
            dp[i]=(dp[i-2]+dp[i-1])*(k-1);
        }
        return dp[n-1];
    }
};
