#include <iostream>
#include <vector>
#include <algorithm>

//这个堆的存储结构为vector

using namespace std;

unsigned parent(unsigned i)
{
    return (i-1) / 2;
}

unsigned left(unsigned i)
{
    return (i+1)*2-1;
}

unsigned right(unsigned i)
{
    return (i+1)*2;
}


void max_heapify(vector<int> &data, unsigned i)
{
    unsigned l, r, max;
    if(data.empty())
    {
        return;
    }

    if(i >= data.size())
    {
        return;
    }

    l=left(i);
    r=right(i);
    max = i;

    if(l < data.size() && data[l] > data[i])
    {
        max = l;
    }
    if(r < data.size() && data[r] > data[max])
    {
        max = r;
    }

    if(max != i)
    {
        swap(data[i], data[max]);
        max_heapify(data, max);
    }
}

void build_max_heap(vector<int> &data)
{
    for(int i = data.size()-1; i >= 0; i--)
    {
        max_heapify(data, i);
    }
}

void heapsort(vector<int> &data)
{
    if(data.empty())
    {
        return;
    }

    vector<int> tmp(data);

    build_max_heap(tmp);
    for(int i = data.size()-1; i >= 0; i--)
    {
        data[i] = tmp[0];
        cout << "max:" << tmp[0] << " ";
        swap(tmp[0], tmp[i]);
        tmp.pop_back();
        build_max_heap(tmp);
    }
    cout << endl;
}

int main()
{
    vector<int> data1 = {0};
    vector<int> data2 = {0, 1};
    vector<int> data3 = {0, 1, 2, 3, 4, 8, -1, -2, -3, 9, 100};
    heapsort(data1);
    heapsort(data2);
    heapsort(data3);

    for(int i : data1)
    {
        cout << i << " ";
    }
    cout << endl;

    for(int i : data2)
    {
        cout << i << " ";
    }
    cout << endl;

    for(int i : data3)
    {
        cout << i << " ";
    }
    cout << endl;
}