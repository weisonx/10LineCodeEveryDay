#include <string>
#include <iostream>

using namespace std;

void print_one_to_max(int n)
{
    string number;

    number.resize(n);
    
    helper(number, 0);
}

void helper(string &number, int index)
{
    if(index > number.size())
    {
        return;
    }

    //最后一位赋值才打印；全0和前导0需要格式化。
    if(index == number.size())
    {
        cout << number <<endl;
        return;
    }

    for(int i = 0; i != 10; i++)
    {
        number[index] = i + '0';
        helper(number, index+1);
    } 
}