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
        if(data[mid] >= data[p1])
        {
            p1 = mid;
        }
        else if(data[mid] <= data[p2])
        {
            p2 = mid;
        }
    }

    return data[p2];
}