描述
在n个物品中挑选若干物品装入背包，最多能装多满？假设背包的大小为m，每个物品的大小为A[i]

样例
如果有4个物品[2, 3, 5, 7]

如果背包的大小为11，可以选择[2, 3, 5]装入背包，最多可以装满10的空间。

如果背包的大小为12，可以选择[2, 3, 7]装入背包，最多可以装满12的空间。

函数需要返回最多能装满的空间大小


代码：
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        //DPsolution1:
        // int n=A.size();
        // if(m==0||n==0) return 0;
        // //int dp[n][m+1];
        // vector< vector<int> > dp(n, vector<int>(m+1, 0) );
        // for(int i=0;i<n;i++)
        // {  
        //      dp[i][0]=0;
        // }
        // for(int j=0;j<m+1;j++)
        // {
        //     if(j>=A[0])
        //       dp[0][j]=A[0];
        // }
        // for(int i=1;i<n;i++)
        // {
        //     for(int j=1;j<m+1;j++)
        //     {
        //         if(j>=A[i])  //取大值作为背包空间为j且放第i个物品时可以有的最大可装满空间
        //           dp[i][j]=max(dp[i-1][j],dp[i-1][j-A[i]]+A[i]);
        //         else
        //           dp[i][j]=dp[i-1][j];
        //     }
        // }
        // return dp[n-1][m];
        
        
        //DPsolution2:
        int n=A.size();
        if(m==0||n==0) return 0;
        vector<int> dp(m+1,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(j>=A[i])  //取大值作为背包空间为j且放第i个物品时可以有的最大可装满空间
                  dp[j]=max(dp[j],dp[j-A[i]]+A[i]);
               
            }
        }
        return dp[m];
    }
};
