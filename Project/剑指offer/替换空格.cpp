#include <iostream>
#include <string>

using namespace std;

// 将字符串中的空格替换为%20
void replace_space(string &s)
{
    int space_num = 0;

    for(auto c : s)
    {
        if(c == ' ')
        {
            space_num++;
        }
    }

    /* 预留插入大小 */
    s.reserve(space_num * 2);

    for(int i = s.size()-1, j = i + space_num*2; i >= 0; i--, j--)
    {
        if(s[i] == ' ')
        {
            j -= 3;
            s[j] = '%';
            s[j+1] = '2';
            s[j+2] = '0';
        }
        else
        {
            s[j] = s[i];
        }
    }
}