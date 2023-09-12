#include <vector>
#include <iostream>

using namespace std;

int get_max_value(vector<vector<int>> &value)
{
    if(value.empty())
    {
        return 0;
    }

    if(value[0].empty())
    {
        return 0;
    }

    vector<vector<int>> max_value(value.size(), vector<int>(value[0].size()));

    for(int i = 0; i < value.size(); i++)
    {
        for(int j = 0; j < value[0].size(); j++)
        {
            int up = 0;
            int left = 0;

            if(i > 0)
            {
                up = max_value[i-1][j];
            }

            if(j > 0)
            {
                left = max_value[i][j-1];
            }

            max_value[i][j] = max(up, left) + value[i][j];
        }
    }

    return max_value[value.size()-1][value[0].size()-1];
}

int main(void)
{
    vector<vector<int>> value{{0,1,2}, {1,2,3}};
    cout << get_max_value(value);


    return 0;
}