#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//这里考虑k不会很大，使用选择排序处理结果更快
void select_sort(vector<int> &data, int l, int r, int k)
{
    int max;
    int max_idx;

    max = data[l];
    max_idx = l;

    for(int i = l; i <= r; i++)
    {
        max = data[i];
        for(int j = i; j <= r; j++)
        {
            if(data[j] > max)
            {
                max = data[j];
                max_idx = j;
            }
        }
        cout << "topk:" << max << " ";
        swap(data[i], data[max_idx]);
        k--;
        if(k == 0)
        {
            cout << endl;
            return;
        }
    }

    cout << "error." << endl;
    return;
}

// 按快速排序原理将数据按中枢分开两半，左小右大
int split_half(vector<int> &data, int l, int r)
{
    int pivot, m;
    int i, j;

    pivot = data[r];
    for(i = l, j = l; j < r; j++)
    {
        if(data[j] <= pivot)
        {
            swap(data[i], data[j]);
            i++;
        }
    }   
    swap(data[i], data[r]);

    return i;
}

void topk(vector<int> &data, int l, int r, int k)
{
    int m;

    if(l > r || k <= 0)
    {
        return;
    }

    //如果子集数量少于k，停止,topK就在该子集
    if((r-l+1) <= k)
    {
        //利用选择排序子集
        select_sort(data, l, r, k);
        return;
    }

    m = split_half(data, l, r);
    if((r-m) > k)
    {
        //只选择右半部部分子集
        topk(data, m+1, r, k);
    }
    else
    {
        //剩余右半子集不足k个，
        //那么就是右半子集、中枢
        topk(data, m, r, r-m+1);
        //和左半子集的一部分
        topk(data, l, m-1, k-(r-m+1));
    }
    
}

void print_topk(vector<int> &data, int k)
{
    if(data.empty() || data.size() < k)
    {
        cout << "incorrected parameters." <<endl;
        return;
    }

    topk(data, 0, data.size()-1, k);
}

int main()
{
    int k;
    vector<int> data1{0};
    vector<int> data2{0, 2, 1};
    vector<int> data3{0,32,999,32,88,11,-9,100,99,32};

    k=1;
    print_topk(data1, k);
    cout << "=====================" << endl;
    print_topk(data2, k);
    cout << "=====================" << endl;
    print_topk(data3, k);
    cout << "=====================" << endl;

    k=2;
    print_topk(data1, k);
    cout << "=====================" << endl;
    print_topk(data2, k);
    cout << "=====================" << endl;
    print_topk(data3, k);
    cout << "=====================" << endl;

    k=3;
    print_topk(data2, k);
    cout << "=====================" << endl;
    print_topk(data3, k);
    cout << "=====================" << endl;

    k=5;
    print_topk(data3, k);
}