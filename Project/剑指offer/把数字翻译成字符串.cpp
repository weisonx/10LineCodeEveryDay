#include <string>
#include <iostream>

using namespace std;

int helper(string &s, int index)
{
    int ret = 0;

    if(index > s.size())
    {
        return 0;
    }

    if(index == s.size())
    {
        return 1;
    }

    ret = helper(s, index+1);

    if(index + 2 < s.size())
    {
        if(s[index+1] + s[index+2] - '0' - '0' <= 25)
        {
            ret += helper(s, index+2);
        }
    }

    return ret;
}

int digital_to_string(int n)
{
    string s;

    s = to_string(n);
    return helper(s, 0);
}

int main(void)
{
    cout << digital_to_string(12258);
    return 0;
}