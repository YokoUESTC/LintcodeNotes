描述
  给出一个包含大小写字母的字符串。求出由这些字母构成的最长的回文串的长度是多少。
  数据是大小写敏感的，也就是说，"Aa" 并不会被认为是一个回文串。
样例
  给出 s = "abccccdd" 返回 7
  一种可以构建出来的最长回文串方案是 "dccaccd"。
思路
  第一种方法是使用set集合，如果遍历到的字符不在set中，那么就将其加入set，
  如果已经在set里了，就将其从set中删去，这样遍历完成后set中就是所有出现个数是奇数个的字符了，
  那么我们最后只要用s的长度减去0和set长度减一之间的较大值即可。
  
  第二种是使用STL中的count函数，就是找字符串中某个字符出现的个数，那么我们和1相与，
  就可以知道该个数是奇数还是偶数了，返回的写法和上面那种方法相同
代码如下：
//使用set
class Solution {
public:
    int longestPalindrome(string s) {
        set<char> t;
        for (char c : s) {
            if (!t.count(c)) t.insert(c);
            else t.erase(c);
        }
        return s.size() - max(0, (int)t.size() - 1);
    }
};
//使用count
class Solution {
public:
    int longestPalindrome(string s) {
        int odds = 0;
        for (char c = 'A'; c <= 'z'; ++c) {
            odds += count(s.begin(), s.end(), c) & 1;
        }
        return s.size() - max(0, odds - 1);
    }
};
