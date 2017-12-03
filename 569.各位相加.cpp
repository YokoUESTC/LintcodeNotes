Lintcode第569题，给出一个非负整数 num，反复的将所有位上的数字相加，直到得到一个一位的整数。
  样例
  给出 num = 38。
  相加的过程如下：3 + 8 = 11，1 + 1 = 2。因为 2 只剩下一个数字，所以返回 2。
分析：
  此题很基础，当判断位数相加大于十之后，使用递归的方法，代码如下
code：

class Solution {
public:
    /*
     * @param num: a non-negative integer
     * @return: one digit
     */
    int addDigits(int num) {
        // write your code here
        int a=num/10;
        int b=num%10;
        int sum=a+b;
        if(sum>=10)
        {
            int a1=sum/10;
            int b1=sum%10;
            return addDigits(a1+b1);
        }
        else
        return sum;
    }
};
