给定一个整数数组，找到和为零的子数组。你的代码应该返回满足要求的子数组的起始位置和结束位置
样例
给出 [-3, 1, 2, -3, 4]，返回[0, 2] 或者 [1, 3].
思路
首先最容易想到的就是利用两个for循环，每次取出一个元素依次与后面的元素相加，时间复杂度是O(n^2)
代码如下：
class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        // write your code here
        vector<int> res;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum = nums[i];
            if(sum==0)
            {
                res.push_back(i);
                res.push_back(i);
                return res;
            }
            for(int j=i+1;j<nums.size();j++)
            {
                sum+=nums[j];
                    if(sum==0)
                    {
                        res.push_back(i);
                        res.push_back(j);
                        return res;
                    }
                
            }
        }
    }
};
方法二（O(n)）

利用一个 map 记录从第一个元素开始到当前元素之和 与 当前元素的下标 的对应关系，
若有一段子数组和为0，那么势必出现同一和对应2个下标，此时就找到了和为零的连续序列，
时间复杂度是O(n)
代码如下：
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        int size = nums.size(), sum = 0;
        if(size <= 0) {
            return vector<int>();
        }

        vector<int> result;
        map<int, int> subSum;
        subSum[0] = -1;

        for(int i=0; i<size; i++) {
            sum += nums[i];
            if(subSum.count(sum)) {
                result.push_back(subSum[sum] + 1);
                result.push_back(i);
                return result;
            }
            subSum[sum] = i;
        }

        return result;
    }
};
