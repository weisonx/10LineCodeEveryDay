#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int get_ugly_number(int index)
{
    unordered_set<int> ugly_numbers_hash;
    vector<int> ugly_numbers;
    ugly_numbers_hash.insert(2);
    ugly_numbers.push_back(2);
    ugly_numbers_hash.insert(3);
    ugly_numbers.push_back(3);
    ugly_numbers_hash.insert(4);
    ugly_numbers.push_back(4);
    ugly_numbers_hash.insert(5);
    ugly_numbers.push_back(5);

    if(ugly_numbers.size() >= index)
    {
        return ugly_numbers[index-1];
    }

    int n = 6;
    while(ugly_numbers.size() < index)
    {
        if(n % 2 == 0)
        {
            if(ugly_numbers_hash.count(n/2) != 0)
            {
                ugly_numbers_hash.insert(n);
                ugly_numbers.push_back(n);
            }
        }
        else if(n % 3 == 0)
        {
            if(ugly_numbers_hash.count(n/3) != 0)
            {
                ugly_numbers_hash.insert(n);
                ugly_numbers.push_back(n);
            }
        }
        else if(n % 5 == 0)
        {
            if(ugly_numbers_hash.count(n/5) != 0)
            {
                ugly_numbers_hash.insert(n);
                ugly_numbers.push_back(n);
            }
        }
        n++;
    }

    return ugly_numbers[index-1];
}

void generate_ugly_numbers(vector<int> &ugly_numbers, int count)
{
    int t2, t3, t5;
    int max;

    ugly_numbers.clear();
    ugly_numbers.reserve(count);

    ugly_numbers.push_back(2);
    ugly_numbers.push_back(3);
    ugly_numbers.push_back(4);
    ugly_numbers.push_back(5);

    /* 找到比当前最大丑数大的第一个丑数 */
    max = 5;
    while(ugly_numbers.size() < count)
    {
        for(auto n : ugly_numbers)
        {
            if(n * 2 > max)
            {
                t2 = n * 2;
                break;
            }
        }

        for(auto n : ugly_numbers)
        {
            if(n * 3 > max)
            {
                t3 = n * 3;
                break;
            }
        }

        for(auto n : ugly_numbers)
        {
            if(n * 5 > max)
            {
                t5 = n * 5;
                break;
            }
        }

        int new_ugly = min(t2, min(t3, t5));
        max = new_ugly;
        ugly_numbers.push_back(new_ugly);
    }
}

int main(void)
{
    cout << get_ugly_number(150) << endl;;
    vector<int> ugly_numbers;
    generate_ugly_numbers(ugly_numbers, 1500);
    cout << ugly_numbers[1500-1] << endl;
    return 0;
}