描述：
在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。给你一个数组，求出这个数组中逆序对的总数。
概括：如果a[i] > a[j] 且 i < j， a[i] 和 a[j] 构成一个逆序对。
样例
序列 [2, 4, 1, 3, 5] 中，有 3 个逆序对 (2, 1), (4, 1), (4, 3)，则返回 3 。

思路： 
  最简单的暴力查找法，时间复杂度n平方。这里采用归并排序的思想来统计逆序对，一个值得注意的问题是
  在归并时逆序对的个数为mid-i+1。
  
代码如下：
class Solution {
public:
    /*
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
        // write your code here
        long long res=0;
        sort(A,0,A.size()-1,res);
        return res;
    }
    void sort(vector<int>& v,int left,int right,long long &Res)
    {
        if(left<right)
        {
           int mid=(left+right)/2;
           sort(v,left,mid,Res);
           sort(v,mid+1,right,Res);
           merge(v,left,mid,right,Res);
        }
    }
    void merge(vector<int>& v,int left,int mid,int right,long long &Res)
    {
        int i=left;
        int j=mid+1;
        vector<int> temp;
        while(i<=mid&&j<=right)
        {
            if(v[i]<=v[j])
            {
                temp.push_back(v[i]);
                i++;
            }
            else
            {
                temp.push_back(v[j]);
                Res=Res+mid-i+1;
                j++;
            }
        }
        while(i<=mid)
          {temp.push_back(v[i]);i++;}
        while(j<=right)
          {temp.push_back(v[j]);j++;}
        for(int i=left;i<=right;i++)//此处出错，没有考虑完全，覆盖原数组
        {
            v[i]=temp[i-left];
        }
    }
};
