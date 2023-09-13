#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int longestSubstringWithoutDuplication(string &s)
{
    if(s.empty())
    {
        return 0;
    }

    int ret = 0;
    int count = 0;
    for(int i = 0; i < s.size(); i++)
    {
        unordered_set<char> hash;
        count = 0;
        for(int j = i; j < s.size(); j++)
        {
            if(hash.count(s[j]) == 0)
            {
                hash.insert(s[j]);
            }
            else
            {
                if(ret < count)
                {
                    ret = count;
                }
                break;
            }
            count++;
        }
    }

    return ret;
}
int main(void)
{
    string s{"arabcacfr"};
    cout << longestSubstringWithoutDuplication(s);
    
    return 0;
}