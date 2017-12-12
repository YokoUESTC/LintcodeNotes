描述
  给出一个字符串（假设长度最长为1000），求出它的最长回文子串，你可以假定只有一个满足条件的最长回文串。
样例
  给出字符串 "abcdzdcab"，它的最长回文子串为 "cdzdc"。
思路
  采用的方法是中心扩散法，外层循环遍历的是子字符串的中心点，内层循环则是从中心扩散，
  一旦不是回文就不再计算其他以此为中心的较大的字符串。由于中心对称有两种情况，
  一是奇数个字母以某个字母对称，而是偶数个字母以两个字母中间为对称，所以我们要分别计算这两种对称情况。
  时间复杂度为n*n
代码
class Solution {
public:
    /*
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        // write your code here
        if(s.size()==0) return NULL;
        if(s.size()==1) return s;
        int maxLength=0;
        int begin;
        for(int i=0;i<s.size();i++)//长度为偶数
        {
            int j=i;
            int k=i+1;
            while(j>=0&&k<s.size()&&s.at(j)==s.at(k))
            {
                if(k-j+1>maxLength)
                {  
                    maxLength=k-j+1;
                    begin=j;
                }
                j--;
                k++;
            }
            
        }
        for(int i=0;i<s.size();i++)//长度为奇数
        {
            int j=i-1;
            int k=i+1;
            while(j>=0&&k<s.size()&&s.at(j)==s.at(k))
            {
                if(k-j+1>maxLength)
                {  
                    maxLength=k-j+1;
                    begin=j;
                }
                j--;
                k++;
            }
            
        }
        if(maxLength>0)
          return s.substr(begin,maxLength);
        return NULL;
    }
};
