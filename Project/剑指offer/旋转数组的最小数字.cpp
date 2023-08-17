#include <vector>

using namespace std;

int get_min_of_rotated_array(vector<int> &data)
{
    int p1, p2;
    int mid;

    if(data.empty())
    {
        return 0;
    }

    if(data.size() == 1)
    {
        return data[0];
    }

    p1 = 0;
    p2 = data.size()-1;

    while(data[p1] >= data[p2])
    {
        if(p1 + 1 == p2)
        {
            break;
        }

        mid = p1 + (p2-p1)/2;
        if(data[p1] > data[mid])
        {
            p1 = mid;
        }
        else
        {
            p2 = mid;
        }
    }

    return data[p2];
}