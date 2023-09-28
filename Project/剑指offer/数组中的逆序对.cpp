#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int> &data, vector<int> &copy, int start, int end)
{
    if(start > end)
    {
        return 0;
    }

    if(start == end)
    {
        copy[start] = data[start];
        return 0;
    }

    int nums = (end - start) / 2;
    int left = helper(data, copy, start, start + nums);
    int right = helper(data, copy, start+nums+1, end);

    int p1 = start + nums;
    int p2= end;
    int p3= end;
    int count = 0;
    while(p1 >= start && p2 >= start+nums+1)
    {
        if(copy[p1] > copy[p2])
        {
            count += p2 - (start+nums);
            copy[p3] = data[p1];
            p1--;
            p3--;
        }
        else
        {
            copy[p3] = data[p2];
            p2--;
            p3--;
        }
    }

    while(p1 >= start)
    {
        copy[p3] = data[p1];
        p1--;
        p3--;
    }

    while(p2 >= start + nums + 1)
    {
        copy[p3] = data[p2];
        p2--;
        p3--;
    }

    return left + right + count;
}

int inverse_pairs(vector<int> data)
{
    if(data.empty() || data.size() < 2)
    {
        return 0;
    }

    vector<int> copy(data);
    return helper(data, copy, 0, data.size()-1);
}

int main(void)
{
    vector<int> data{7, 5, 6, 4};
    cout << inverse_pairs(data);
    return 0;
}