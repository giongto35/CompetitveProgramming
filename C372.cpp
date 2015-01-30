#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std ;

#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const long long oo = 1000000000000000000ll;
const int maxn = 150000+10;
int a[maxn],b[maxn],t[maxn];
int st[maxn];
long long F[maxn];
long long G[maxn];
int top,bot;
int n,m,d;

int main()
{
    //freopen("C372.inp","r",stdin);
    //freopen("C372.out","w",stdout);
    scanf("%d%d%d",&n,&m,&d);
    FOR(i,1,m)
    {
        scanf("%d%d%d",&a[i],&b[i],&t[i]);

        long long r = (long long)(t[i] - t[i-1]) * d;
        int x = 1;
        bot = 1; top = 0;
        FOR(j,1,n)
        {
            while (x <= min((long long)n,j + r))
            {
                while ((top>=bot) && (F[st[top]] <= F[x])) top--;
                st[++top] = x;
                x++;
            }
            while ((top>=bot) && (st[bot] < j - r)) bot++;
            if (bot <= top) G[j] = F[st[bot]] + (long long)b[i] - abs(a[i] - j);
        }
        FOR(j,1,n)
        {
            F[j] = G[j];
        }
    }
    long long res = -oo;
    FOR(i,1,n) res = max(res,F[i]);
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

