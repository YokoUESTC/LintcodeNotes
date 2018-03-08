描述
实现一个带有取最小值min方法的栈，min方法将返回当前栈中的最小值。
你实现的栈将支持push，pop 和 min 操作，所有操作要求都在O(1)时间内完成。
样例
如下操作：push(1)，pop()，push(2)，push(3)，min()， push(1)，min() 返回 1，2，1
思路：
  使用两个栈，一个栈用来保存当前栈中的元素，其功能和正常的栈没有任何区别，另一个栈用来保存每一步的最小值
代码：
class MinStack {
public:
    MinStack() {
        // do intialization if necessary
        
    }
    stack<int> stackData;
    stack<int> stackMin;

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        // write your code here
        if(stackMin.empty())
          stackMin.push(number);
        else if(number<=stackMin.top())
          stackMin.push(number);
        stackData.push(number);
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        if(stackData.empty())
          return 0;
        int value= stackData.top();
        stackData.pop();
        if(value==stackMin.top())
          stackMin.pop();
        return value;
          
    }

    /*
     * @return: An integer
     */
    int min() {
        // write your code here
        if(stackMin.empty())
          return 0;
        return stackMin.top();
    }
};
