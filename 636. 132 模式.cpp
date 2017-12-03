描述：
  给你一个 n 个整数的序列 a1,a2,...,an，一个 132 模式是对于一个子串 ai,aj,ak，满足 i < j < k 和 ai < ak < aj。
  设计一个算法来检查输入的这 n 个整数的序列中是否存在132模式。n 会小于 20,000。
样例
  给你序列 nums = [1,2,3,4] 
  返回 False//没有132模式在这个序列中。
  给你序列 nums = [3,1,4,2] 
  返回 True//存在132模式：[1,4,2]。
分析：
  本题很容易想到的方式就是暴力循环枚举，但是这样时间复杂度太高，并不是我们所追求的。在看了别人的一些想法之后，
  决定用栈来实现，思路是我们维护一个栈和一个变量third，其中third就是第三个数字，也是pattern 132中的2，栈里面
  按顺序放所有大于third的数字，也是pattern 132中的3，那么我们在遍历的时候，如果当前数字小于third，
  即pattern 132中的1找到了，我们直接返回true即可，因为已经找到了，注意我们应该从后往前遍历数组。
  如果当前数字大于栈顶元素，那么我们按顺序将栈顶数字取出，赋值给third，然后将该数字压入栈，
  这样保证了栈里的元素仍然都是大于third的，我们想要的顺序依旧存在。
代码：
class Solution {
public:
    /*
     * @param nums: a list of n integers
     * @return: true if there is a 132 pattern or false
     */
    bool find132pattern(vector<int> &nums) {
        // write your code here
        // if(nums.size()==0||nums.size()<3) return false;
        // for(int i=0;i<nums.size()-2;i++)
        // {
        //     for(int j=i+1;j<nums.size()-1;j++)
        //     {
        //         for(int k=j+1;k<nums.size();k++)
        //         {
        //             if(nums[k]>nums[i]&&nums[k]<nums[j])
        //             return true;
        //         }
        //     }
        // }
        // return false;
        int third = INT_MIN;
        stack<int> s;
        for (int i = nums.size() - 1; i >= 0; --i) 
        {
            if (nums[i] < third) return true;
            else 
            {
                while (!s.empty() && nums[i] > s.top()) 
                {
                   third = s.top(); s.pop();
                }
            }
            s.push(nums[i]);
        }
        return false;
        }
};
