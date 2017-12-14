写一个算法来判断一个数是不是"快乐数"。
一个数是不是快乐是这么定义的：对于一个正整数，每一次将该数替换为他每个位置上的数字的平方和，
然后重复这个过程直到这个数变为1，或是无限循环但始终变不到1。如果可以变为1，那么这个数就是快乐数。

样例
19 就是一个快乐数。

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
思路
  建立一个集合（Python中的集合，是存储不重复元素的），存储循环中每次生成的值（就是样例中19， 82,68。。。）
  如果某次循环后，值为1，那么就是快乐数；而如果某次循环后的值已经存在于集合中了，那么，当然不是快乐数。
代码
class Solution:
    """
    @param: n: An integer
    @return: true if this is a happy number or false
    """
    def isHappy(self, n):
        # write your code here
        res=set()
        while True:
            res.add(n)
            n=self.Next(n)
            if n == 1:  
                return True  
            elif n in res:  
                return False
    def Next(self,n):
        sum=0
        while n!=0:
            sum+=(n%10)*(n%10)
            n/=10
        return sum
