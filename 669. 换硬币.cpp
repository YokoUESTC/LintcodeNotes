描述
给出不同面额的硬币以及一个总金额. 写一个方法来计算给出的总金额可以换取的最少的硬币数量.
如果已有硬币的任意组合均无法与总金额面额相等, 那么返回 -1.
样例
给出 coins = [1, 2, 5], amount = 11
返回 3 (11 = 5 + 5 + 1)
给出 coins = [2], amount = 3
返回 -1

代码：
class Solution {
public:
    /**
     * @param coins: a list of integer
     * @param amount: a total amount of money amount
     * @return: the fewest number of coins that you need to make up
     */
    int coinChange(vector<int> &coins, int amount) {
        // write your code here
        //dp[i]表示钱数为i最少需要多少coins
        if(coins.size()==0) return -1;
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i)
                  dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
            
        }
        if(dp[amount]>amount) return -1;
        return dp[amount];
    }
};
