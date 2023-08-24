#include <cmath>

using namespace std;

double power(double base, int exponent)
{
    double ret;

    ret = base;

    //无意义1/0、0^0
    if(abs(base - 0.0) < 1e-9 && exponent <= 0)
    {
        return 0.0;
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