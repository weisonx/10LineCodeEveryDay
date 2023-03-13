/*
给定一个 N 行 M 列的二维矩阵，矩阵中每个位置的数字取值为 0 或 1，矩阵示例如：
4 4
1 1 0 0
0 0 0 1
0 0 1 1
1 1 1 1
现需要将矩阵中所有的 1 进行反转为 0，规则如下：
1. 当点击一个 1 时，该 1 被反转为 0，同时相邻的上、下、左、右，以及左上、左下、右上、右下 8 个方向的 1 （如果存在 1）均会自动反转为 0；
2. 进一步地，一个位置上的 1 被反转为 0 时，与其相邻的 8 个方向的 1 （如果存在 1）均会自动反转为 0；
按照上述规则示例中的矩阵只最少需要点击 2 次后，所有均值 0 。请问，给定一个矩阵，最少需要点击几次后，所有数字均为 0？

*/

#include <iostream>
#include <vector>

using namespace std;

void clear_one(vector<vector<int>> &data, int i, int j)
{
    int rs, cs;
    
    if(data.empty())
    {
        cout << "error 2." << endl;
        return;
    }

    rs = data.size();
    cs = data[0].size();

    if(data[i][j] != 1)
    {
        return;
    }

    data[i][j] = 0;
    if(i-1 >= 0)
    {
        clear_one(data, i-1, j);
    }
    if(i+1 < rs)
    {
        clear_one(data, i+1, j);
    }
    if(j-1 >= 0)
    {
        clear_one(data, i, j-1);
    }
    if(j+1 < cs)
    {
        clear_one(data, i, j+1);
    }
    if(i-1 >= 0 && j-1 >= 0)
    {
        clear_one(data, i-1, j-1);
    }
    if(i-1 >= 0 && j+1 < cs)
    {
        clear_one(data, i-1, j+1);
    }
    if(i+1 < rs && j-1 >= 0)
    {
        clear_one(data, i+1, j-1);
    }
    if(i+1 < rs && j+1 < cs)
    {
        clear_one(data, i+1, j+1);
    }
}

int pop(vector<vector<int>> &data)
{
    int cnt = 0;
    int min = data.size();
    int rs, cs;
    bool flag = false;

    if(data.empty())
    {
        cout << "error." << endl;
        return -1;
    }

    rs = data.size();
    cs = data[0].size();

    for(int i = 0; i != rs; i++)
    {
        for(int j = 0; j != cs; j++)
        {
            if(data[i][j] == 1)
            {
                vector<vector<int>> new_data(data);
                clear_one(new_data, i, j);
                cnt = 1 + pop(new_data);
                flag = true;

                if(cnt < min)
                {
                    min = cnt;
                }
            }
        }
    }

    if(flag)
    {
        return min;
    }

    return 0;
}

int main()
{
    int row_size;
    int column_size;
    vector<vector<int>> data;

    cin >> row_size >> column_size;
    for(int i = 0; i != row_size; i++)
    {
        vector<int> tmp;
        for(int j = 0; j != column_size; j++)
        {
            int n;
            cin >> n;
            tmp.push_back(n);
        }
        data.push_back(tmp);
    }

    cout << "load data finished!." << endl;
    cout << pop(data) << endl;
}