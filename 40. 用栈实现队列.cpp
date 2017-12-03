队列应支持push(element)，pop() 和 top()，其中pop是弹出队列中的第一个(最前面的)元素。
pop和top方法都应该返回第一个元素的值。
样例
比如push(1), pop(), push(2), push(3), top(), pop()，你应该返回1，2和2

分析：思路其实较为简单，入队时，将元素压入s1。出队时，判断s2是否为空，如不为空，则直接弹出顶元素；
     如为空，则将s1的元素逐个“倒入”s2，把最后一个元素弹出并出队。
代码如下：

class MyQueue {
public:
    MyQueue() {
        // do intialization if necessary
    }
    stack<int> s1;
    stack<int> s2;
    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        // write your code here
        s1.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res=s2.top();
        s2.pop();
        return res;
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
};
