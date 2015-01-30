#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000+10;
int a[maxn];
int b[maxn];
int T;
int n,m;
    void process()
    {
        scanf("%d",&T);
        for (int st = 1; st <= T; st ++)
        {
            scanf("%d%d",&n,&m);
            for (int i = 1; i <= n; i++)
            {
                scanf("%d",&a[i]);
            }
            for (int i = 1; i <= m; i++)
            {
                scanf("%d",&b[i]);
            }
            sort(a+1,a+1+n);
            sort(b+1,b+1+m);
            a[0] = -123;
            a[n+1] = -353;
            int j = 1;
            int res = 0;
            int s = 0;
            for (int i = 1; i <= n; i++)
            {
                if (a[i]!=a[i-1]) s = 1; else s++;
                if (a[i]!=a[i+1]){
                    while (j <= m && b[j] < a[i] ){
                            j++;
                        res += 1;
                    }
                    int jt = j;
                    while (j <= m && b[j] == a[i]) j++;
                    res = res + abs((j - jt) - s);
                }
            }
            printf("%d\n",res + (m - j + 1));
        }
    }
int main()
{
    freopen("JustPruneTheList.inp","r",stdin);
    //freopen("JustPruneTheList.inp","w",stdout);

    process();
}
