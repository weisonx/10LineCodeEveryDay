#include <iostream>
#include <vector>
#include <string>

using namespace std;

void set_next_array(vector<int> &next, string &s)
{
    int i, j;

    if(next.empty() || s.empty())
    {
        return;
    }

    i = 0;
    j = -1;
    next[0] = -1;

    while(i < next.size() - 1)
    {
        if(j < 0 || s[i] == s[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int  kmp_search(string &s, string &sub)
{
    int i = 0;
    int j = 0;

    if(s.empty() || sub.empty())
    {
        return -1;
    }

    vector<int> next(sub.size());
    set_next_array(next, sub);

    while(i < s.size() && j < (int)sub.size())
    {
        if(j < 0 || s[i] == sub[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    if(j == sub.size())
    {
        return i - j;
    }
    
    return -1;
}

int main()
{
    string s{"fskfjksldajflsdkajfklsajflsda"};
    string s1{"fs"};
    string s2{"sda"};

    cout << kmp_search(s, s1) << " " << s.find(s1) << endl;
    cout << kmp_search(s, s2) << " " << s.find(s2) <<endl;

}