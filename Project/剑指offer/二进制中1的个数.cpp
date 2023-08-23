

int count_one_of_int(int n)
{
    int count = 0;
    int i = 0;

    while(i < 32)
    {
        if(n & (1 << i))
        {
            count++;
        }
    }

    return count;
}