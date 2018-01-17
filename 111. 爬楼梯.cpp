描述：
  假设你正在爬楼梯，需要n步你才能到达顶部。但每次你只能爬一步或者两步，你能有多少种不同的方法爬到楼顶部？
样例
  比如n=3，1+1+1=1+2=2+1=3，共有3种不同的方法
  返回 3
思路：
  设走第i层楼梯需要dp[i]中方法，走第i-1层楼梯需要dp[i-1]种方法。则走第
  i层楼梯的方法种数为dp[i-1]+dp[i-2]种。动态规划解题的主要思想就是找出递推式，然后利用子问题的解来求最后的最优解。
代码：


class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if(n<=2) return n;
        int* dp = new int[n];
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};

