#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void  max_in_windows(vector<int> &data, int window)
{
    if(data.empty() || window <= 0)
    {
        return;
    }
    
    deque<int> index;   //存index而不是数值
    for(int i = 0; i < window && i < data.size(); i++)
    {
        while(!index.empty() && data[i] >= data[index.back()])
        {
            index.pop_back();
        }
        index.push_back(i);
    }

    for(int i = window; i < data.size(); i++)
    {
        cout << data[index.front()];

        //维持队头降序且丢弃不可能是本窗口最大值的值
        while(!index.empty() && data[i] >=  data[index.back()])
        {
            index.pop_back();
        }

        //队头已是上一个窗口，和当前i的关系判断
        if(!index.empty() && index.front() + window <= i)
        {
            index.pop_front();
        }
        index.push_back(i);
    }
    cout << data[index.front()];
}

int main(void)
{
    vector<int> data{2,3,4,2,6,2,5,1};
    max_in_windows(data, 3);
    return 0;
}