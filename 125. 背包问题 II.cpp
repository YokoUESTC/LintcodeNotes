描述
给出n个物品的体积A[i]和其价值V[i]，将他们装入一个大小为m的背包，最多能装入的总价值有多大？
样例
对于物品体积[2, 3, 5, 7]和对应的价值[1, 5, 2, 4], 假设背包大小为10的话，最大能够装入的价值为9。
代码

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        if(m==0||A.size()==0||V.size()==0) return 0;
        //int dp[m+1];
        vector<int> dp(m+1,0);
        for(int i=0;i<A.size();i++)
        {
            for(int j=m;j>0;j--)
            {
                if(j>=A[i])
                  dp[j]=max(dp[j],dp[j-A[i]]+V[i]);
            }
        }
        return dp[m];
    }
};
