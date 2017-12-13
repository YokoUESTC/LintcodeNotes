给出两个字符串, 你需要修改第一个字符串，将所有与第二个字符串中相同的字符删除, 
并且第二个字符串中不同的字符与第一个字符串的不同字符连接
样例
给出 s1 = aacdb, s2 = gafd
返回 cbgf
给出 s1 = abcs, s2 = cxzca;
返回 bsxz

class Solution:
    """
    @param: : the 1st string
    @param: : the 2nd string
    @return: uncommon characters of given strings
    """

    def concatenetedString(self, s1, s2):
        # write your code here
        s3=''
        for i in range(len(s1)):
            if s1[i] not in s2:
                s3=s3+s1[i]
        for i in range(len(s2)):
            if s2[i] not in s1:
                s3=s3+s2[i]
        return s3
