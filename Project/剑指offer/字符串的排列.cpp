#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

void helper(string &s, string &temp, unordered_set<char> &hash, int index)
{
    if(index >= s.size())
    {
        return;
    }

    for(auto c : s)
    {
        //前面已确定的字符不能再使用
        hash.clear();
        for(int i = 0; i < index; i++)
        {  
            hash.insert(temp[i]);
        }
        
        if(hash.count(c) != 0)
        {
            continue;
        }

        temp[index] = c;
        hash.insert(c);
        
        if(index == s.size() - 1)
        {
            cout << temp << endl;
        }
        helper(s, temp, hash, index+1);
    }
}

void permutation_string(string &s)
{
    string temp(s);
    unordered_set<char> hash;

    //全排列的方式递归，然后过滤重复组合
    helper(s, temp, hash, 0);
}


int main()
{
    string s("abc");
    permutation_string(s);
}