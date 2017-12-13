Given a matrix, find a element that appear in all the rows in the matrix.
You can assume that there is only one such element.
样例
For example:
Given a matrix:

[
  [2,5,3],
  [3,2,1],
  [1,3,5]
]
return 3
 先试用set去除重复元素，将矩阵所有元素装在list中，使用python中的字典如果list有重复的元素则加一
代码如下：
class Solution:
    """
    @param Matrix: the input
    @return: the element which appears every row
    """
    def FindElements(self, Matrix):
        # write your code here
        import operator
        size = len(Matrix)
        newMatrix = []
        for row in Matrix:
            rowset = set(row)
            newMatrix += list(rowset)

        tempdir = {}
        for x in newMatrix:
            tempdir[x] = tempdir.get(x,0)+1
            if tempdir[x] == size:
                return x
        return -1
