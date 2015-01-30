#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int maxn = 1000+10;
int T,n;
int a[maxn];
int p[maxn];
bool ok;
int g[maxn];
int GCD(int a,int b)
{
    if (b==0) return a;
    return GCD(b,a % b);
}

int calc(int u)
{
    int res=1;
    FOR(i,1,u) res=res*a[i]/GCD(res,a[i]);
    return res;
}

int frac(int x)
{
    memset(p,0,sizeof(p));
    if (x>=1) p[1]=1;
    FOR(i,2,n) while (x%i==0&&x>1) x/=i,p[i]++;
}
int main()
{
    freopen("ExpensiveDinner.inp","r",stdin);
    freopen("ExpensiveDinner.out","w",stdout);
    cin>>T;
    FOR(ct,1,T)
    {
        cin>>n;
        FOR(i,1,n) a[i]=i;

        memset(g,0,sizeof(g));
        int sum1=n;
        FOR(i,1,n)
        {
            int x=a[i];
            ok=true;
            frac(x);
            FOR(j,1,n)
            {
                if (p[j]>g[j]) ok=false;
                g[j]=max(g[j],p[j]);
            }
            if (ok) sum1--;
        }

        FOR(i,1,n) a[i]=n-i+1;
        memset(g,0,sizeof(g));
        int sum2=n;
        FOR(i,1,n)
        {
            int x=a[i];
            ok=true;
            frac(x);
            FOR(j,1,n)
            {
                if (p[j]>g[j]) ok=false;
                g[j]=max(g[j],p[j]);
            }
            if (ok) sum2--;
        }
        cout<<"Case #"<<ct<<": "<<sum1-sum2<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

