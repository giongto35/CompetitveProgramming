
void roirachoa()
{
    vector<int> b(a+1,a+sn+1);
    sort(b.begin(),b.end());
    b.resize(distance(b.begin(),unique(b.begin(),b.end())));
    maxso = b.size();
    for (int i = 1; i <= sn; i++)
        a[i] = lower_bound(b.begin(),b.end(),a[i]) - b.begin() + 1;
}
