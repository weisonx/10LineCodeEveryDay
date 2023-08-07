
#include <iostream>
#include <vector>

using namespace std;

//size:n, data[i]:0~n-1
int duplicate_digital(vector<int> &data)
{
    for(int i = 0; i < data.size(); i++)
    {
        while(data[i] != i)
        {
            if(data[data[i]] == data[i])
            {
                return data[i];
            }
            swap(data[i], data[data[i]]);
        }
    }

    return -1;
}