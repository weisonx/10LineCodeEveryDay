#include <vector>
#include <algorithm>

using namespace std;

int stock_profit_max(vector<int> prices)
{
    vector<int> diff(prices.size());
    int ret = 0;

    if(prices.size() <= 1)
    {
        return 0;
    }

    diff[0] = 0;
    for(int i = 1; i < prices.size(); i++)
    {
        diff[i] = prices[i] - prices[i-1];
        if(diff[i-1] > 0)
        {
            diff[i] += diff[i-1];
        }
    }

    return *max_element(diff.begin(), diff.end());
}   