#include <iostream>
#include <stack>

using namespace std;

class MyStack
{
public:
    MyStack() = default;
    ~MyStack() = default;

    int min()
    {
        return _min;
    }

    void push(int val)
    {
        _stack.push(val);
        if(val < _min)
        {
            _min = val;
        }
        //每次push都将最小值push辅助栈
        _min_stack.push(_min);
    }

    void pop()
    {
        if(_stack.empty() || _min_stack.empty())
        {
            return;
        }
        _stack.pop();
        //每次pop都将辅助栈pop一次
        _min_stack.pop();
        if(!_min_stack.empty())
        {
            _min = _min_stack.top();
        }
    }

private:
    int _min{~(1 << 31)};
    stack<int> _stack;
    stack<int> _min_stack;   //辅助栈
};


int main(void)
{
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(0);
    stack.push(3);
    cout << "min:" << stack.min() << endl;
    stack.pop();
    stack.pop();
    cout << "min:" << stack.min() << endl;
    return 0;
}