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
const long long maxn=10000+10;
const long long cmod=1000000007;
long long a[maxn];
long long D[maxn];
long long GT[maxn];
long long res,T;
int n,k;

long long modpow(long long a,long long x)
{
    if (x==0) return 1;
    if (x%2==0)
    {
        long long p=modpow(a,x/2);
        return (p*p)%cmod;
    }
    else return ((long long)a*modpow(a,x-1))%cmod;
}

long long MI(long long u)
{
    return modpow(u,cmod-2);
}

int main()
{
    freopen("Card_game.txt","r",stdin);
    freopen("cardgame.out","w",stdout);
    cin>>T;
    D[0]=MI(1);
    FOR(i,1,10000+2) D[i]=(D[i-1]*MI(i))%cmod;
    GT[0]=1;
    FOR(i,1,10000+2) GT[i]=(GT[i-1]*i)%cmod;
    FOR(ct,1,T)
    {
        cin>>n>>k;
        FOR(i,1,n) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        res=0;
        FOR(i,k,n)
        {
            //cout<<i<<' '<<k<<endl;
            //cout<<k-1<<' '<<i-1<<' '<<D[k-1]<<' '<<D[(i-1)-(k-1)]<<endl;
            long long s1=(a[i]*GT[i-1])%cmod;
            long long s2=(D[k-1]*D[i-k])%cmod;
            res=(res+(s1*s2)%cmod)%cmod;
        }
        cout<<"Case #"<<ct<<": "<<res<<endl;
        T--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

