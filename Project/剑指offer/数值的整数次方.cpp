#include <numeric>

using namespace std;

double power(double base, int exponent)
{
    double ret;

    ret = base;
    if(base == 0)
    {
        return ret;
    }

    if(exponent >= 0)
    {
        while(--exponent > 0)
        {
            ret *= base;
        }
    }
    else
    {
        exponent = -exponent;
        while(--exponent > 0)
        {
            ret *= base;
        }
        ret = 1 / ret;
    }

    return 0;
}