#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &data, int key)
{
    int l, r, m;

    if(data.empty())
    {
        return -1;
    }
    l = 0;
    r = data.size()-1;

    while(l <= r)
    {
         m = l + (r-l) / 2;
         if(data[m] == key)
         {
            return m;
         }
         else if(data[m] < key)
         {
            l = m + 1;
         }
         else
         {
            r = m - 1;
         }
    }

    return -1;
}

int main()
{
    vector<int> data1{};
    vector<int> data2{1};
    vector<int> data3{1,2};
    vector<int> data4{8,10,88,999,11111,11111};

    int key = 1;
    cout << binary_search(data1, key) << endl;
    key = 1;
    cout << binary_search(data2, key) << endl;
    key = 2;
    cout << binary_search(data3, key) << endl;
    key = 11111;
    cout << binary_search(data4, key) << endl;
}