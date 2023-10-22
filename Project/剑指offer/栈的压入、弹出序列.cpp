#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool is_same_stack_sequence(vector<int> &push, vector<int> &pop)
{
    if(push.size() != pop.size())
    {
        return false;
    }

    if(push.empty() || pop.empty())
    {
        return true;
    }

    stack<int> stack;
    int index = 0;
    for(auto n : pop)
    {
        while(stack.empty() || stack.top() != n)
        {
            if(index >= push.size())
            {
                return false;
            }    
            stack.push(push[index]);
            index++;
        }
        if(!stack.empty())
        {
            stack.pop();
        }
    }

    return true;
}


int main(void)
{
    vector<int>push{1,2,3,4,5};
    vector<int>pop{4,5,3,2,1};
    cout << is_same_stack_sequence(push, pop) << endl;
    pop = vector<int>{4,3,5,1,2};
    cout << is_same_stack_sequence(push, pop) << endl;
    return 0;
}