#include <iostream>
#include <vector>
#include <string>

using namespace std;

char find_first_appearing_char(string s)
{
    vector<int> tab(256, 0);

    for(auto c : s)
    {
        tab[c]++;
    }

    for(auto c : s)
    {
        if(tab[c] == 1)
        {
            return c;
        }
    }

    return '\0';
}