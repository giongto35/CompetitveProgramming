#include <map>
#include <iostream>
#include <cstdio>
#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

using namespace std;
map<int,int> m;
pair<int,int> a[100000+10000];
int n,u,v,sum,spt,rr[100000+10],b[100000+10];
bool ex[100000+10];
int main()
{
    while(scanf("%d%d",&u,&v))
    {
        if (u == 5) break;
        a[++n].first = u;a[n].second = v;
    }
    for(int i = 1; i<= n; i++) if (a[i].first == 1) m[a[i].second] = 0;
    spt = m.size();
    int cnt = 0;
    FOREACH(v,m)
    {
        cnt++;
        m[(*v).first] = spt - cnt + 1;
        rr[spt - cnt + 1] = (*v).first;
    }
    for(int i =1; i <= n; i++)
    {
        if (a[i].first == 1)
            {
                ex[m[a[i].second]] = true;
                for (int j = m[a[i].second]; j <= spt; j += (j & (-j))) b[j] += 1;
            }
        if (a[i].first == 2)
            {
                ex[m[a[i].second]] = false;
                for (int j = m[a[i].second]; j <= spt; j += (j & (-j))) b[j] -= 1;
            }
        if (a[i].first == 3)
        {
            int l=1;
            int r=spt;
            int res = -1;
            while (l<=r)
            {
                int mid = (l + r) / 2;
                sum = 0;
                for(int j = mid; j >=1 ; j -= (j & (-j))) sum += b[j];
                if (sum >= a[i].second) res = mid , r = mid - 1;
                else l = mid + 1;
            }
            printf("%d\n",res == -1 ? -1 : rr[res]);
        }
        if (a[i].first == 4)
        {
            sum = 0;
            if (ex[m[a[i].second]] == false)
            {
                printf("-2\n");
                continue;
            }
            for(int j = m[a[i].second]; j >=1 ; j -= (j & (-j))) sum += b[j];
            printf("%d\n",sum);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
