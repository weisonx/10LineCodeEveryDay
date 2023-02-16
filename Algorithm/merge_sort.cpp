#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &data, int l, int m, int r)
{
    vector<int> tmp(data);
    int i, j;

    i = l;
    j = m+1;
    for(int k = l; k <= r; k++)
    {
        if(i > m)
        {
            data[k] = tmp[j];
            j++;
        }
        else if(j > r)
        {
            data[k] = tmp[i];
            i++;
        }
        else if(tmp[j] < tmp[i])
        {
            data[k] = tmp[j];
            j++;
        }
        else
        {
            data[k] = tmp[i];
            i++;
        }
    }

    for(auto n : data)
    {
        cout << n <<" ";
    }
    cout <<endl;
}

void merge_sort(vector<int> &data, int l, int r)
{
    int m;
    if(l >= r)
    {
        return;
    }

    m = l + (r-l)/2;
    merge_sort(data, l, m);
    merge_sort(data, m+1, r);
    merge(data, l, m, r);
}

void merge_sort(vector<int> &data)
{
    if(data.empty())
    {
        return;
    }

    merge_sort(data, 0, data.size()-1);
}

int main()
{
    vector<int> data1{0};
    vector<int> data2{1,0};
    vector<int> data3{0,2,1,88,-1,99,1000,666};

    merge_sort(data1);
    merge_sort(data2);
    merge_sort(data3);

    for(auto n : data1)
    {
        cout << n <<" ";
    }
    cout <<endl;

    for(auto n : data2)
    {
        cout << n <<" ";
    }
    cout <<endl;

    for(auto n : data3)
    {
        cout << n <<" ";
    }
    cout <<endl;

}