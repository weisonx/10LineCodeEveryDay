#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int> &data)
{
    for(int i = 0; i < data.size(); i++)
    {
        for(int j = data.size()-1; j > i; j--)
        {
            if(data[j] < data[j-1])
            {
                swap(data[j], data[j-1]);
            }
        }
    }
}

int main()
{
    vector<int> data{1,32,51,5555,123,3,4};
    bubbleSort(data);
    for(auto n : data)
    {
        cout << n << "  ";
    }

    cout << endl;

    return 0;
}