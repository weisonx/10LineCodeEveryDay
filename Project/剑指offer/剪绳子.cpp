#include <vector>

using namespace std;

//f(n) = max{f(i)*f(n-i)}
int max_product_after_cutting(int len)
{
    vector<int> product(len+1);

    if(len < 2)
    {
        return 0;
    }
    else if(len == 2)
    {
        return 1;
    }
    else if(len == 3)
    {
        return 2;
    }

    //从长度4开始构造切割最大乘积
    product[0] = 0;
    product[1] = 1;
    product[2] = 2;
    product[3] = 3;

    for(int i = 4; i <= len; i++)
    {
        int j = i - 1;
        product[i] = 0;
        while(j > i / 2)
        {
            if(product[j] * product[i-j] > product[i])
            {
                product[i] = product[j] * product[i-j];
            }
            j--;
        }
    }

    return product[len];
}