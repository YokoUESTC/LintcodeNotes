描述
给出一个非负整数数组，你最初定位在数组的第一个位置。　　　
数组中的每个元素代表你在那个位置可以跳跃的最大长度。　　　　
判断你是否能到达数组的最后一个位置。
注意事项
这个问题有两个方法，一个是贪心和 动态规划。
贪心方法时间复杂度为O（N）。
动态规划方法的时间复杂度为为O（n^2）。
我们手动设置小型数据集，使大家可以通过测试的两种方式。这仅仅是为了让大家学会如何使用动态规划的方式解决此问题。
如果您用动态规划的方式完成它，你可以尝试贪心法，以使其再次通过一次。

样例
A = [2,3,1,1,4]，返回 true.

A = [3,2,1,0,4]，返回 false.

代码：使用了三种方法来实现


class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here
        //DP1:
        
        //f[i]代表能否从起点跳到第i个位置
        // int n=A.size();
        // if(n==0) return false;
        // bool f[n];
        // f[0]=true;
        // for(int i=1;i<n;i++)
        // {
        //     f[i]=false;
        //     for(int j=0;j<i;j++)
        //     {
        //         if(f[j]&&A[j]+j>=i)
        //         {  
        //           f[i]=true;
        //           break;
        //         }
        //     }
        // }
        // return f[n-1];
        
        
        //DP2:优化，不使用数组保存
        // int n=A.size();
        // if(n==0) return false;
        // bool flag;
        // for(int i=1;i<n;i++)
        // {
        //      flag=false;
        //      for(int j=0;j<i;j++)
        //      {
        //          if(A[j]+j>=i)
        //          {  
        //           flag=true;
        //           break;
        //          }
        //      }
        //      if(!flag)
        //       return false;
        // }
        // return true;
        
        
        //3.贪心法
        int n=A.size();
        if(n==0) return false;
        int maxJump=A[0];
        for(int i=0;i<=maxJump;i++)
        {
            maxJump=max(maxJump,A[i]+i);
            if(maxJump>=n-1)
              return true;
            
        }
        return false;
    }
};
