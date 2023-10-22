//用两个栈实现队列

#include <stack>
using namespace std;

class Mydeque
{
public:
    //入队
    void push(int n)
    {
        stack1.push(n); 
    }

    //出队
    void pop(int n)
    {
        if(stack2.empty())
        {
            while(stack1.size() != 0)
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        stack2.pop();
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
