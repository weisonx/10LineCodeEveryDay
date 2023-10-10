#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

void helper(vector<int> &data, vector<int> &copy, int index, int &min)
{
    if(index >= data.size())
    {
        return;
    }

    for(auto n : data)
    {
        string s; 
        unordered_set<int> hash;   
        for(int i = 0; i < index; i++)
        {
            hash.insert(copy[i]);
            s += to_string(copy[i]);
        }

        if(hash.count(n) != 0)
        {
            continue;
        }

        s += to_string(n);
        copy[index] = n;
        helper(data, copy, index+1, min);

        if(index == data.size() - 1)
        {
           min = std::min(min, atoi(s.c_str()));
        }
    }
}

void print_min_number(vector<int> &data)
{
    if(data.empty())
    {
        return;
    }

    vector<int> copy(data.size());
    int min = ~(1 << 31);
    helper(data, copy, 0, min);
    cout << min << endl;
}

int main(void)
{
    vector<int> data{3, 32, 321};
    print_min_number(data);
    return 0;
}