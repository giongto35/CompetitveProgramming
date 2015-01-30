void update(int i,int gt)//change long long
{
    while (i<=maxso)
    {
        BIT[i]=BIT[i] + gt;
        i=i+(i & (-i));
    }
}


int get(int i)//change long long
{
    int gt=0;//change long long
    while (i>=1)
    {
        gt=BIT[i] + gt;
        i=i-(i & (-i));
    }
    return gt;
}

