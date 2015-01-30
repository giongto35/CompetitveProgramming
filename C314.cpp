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
const int maxn=100000+10;
const int cmod=1000000007;
const int maxso=1000000+1;
int n;
int a[maxn];
long long F[maxn],G[maxn];
long long res;
long long BIT[1000000+10];
int nearest[1000000+10];

void update(int i,int gt)
{
    while (i<=maxso)
    {
        BIT[i]=(BIT[i]+gt) % cmod;
        i=i+(i & (-i));
    }
}


int get(int i)
{
    int gt=0;
    while (i>=1)
    {
        gt=(gt+BIT[i])%cmod;
        i=i-(i & (-i));
    }
    return gt;
}

int main()
{
    //freopen("C314.inp","r",stdin);
    //freopen("C314.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n)
    {
        G[i]=get(a[i]-1);
        if (nearest[a[i]]!=0)
        {
            F[i]=(F[i]+(long long)F[nearest[a[i]]]*a[i])%cmod;
            F[i]=(F[i]+((long long)get(a[i]-1)-G[nearest[a[i]]])*a[i])%cmod;
        }
        else
            F[i]=(F[i]+(long long)get(a[i]-1)*a[i]+a[i])%cmod;
        update(a[i],F[i]);
        //cout<<F[i]<<' ';
        res=(res+F[i])%cmod;
        nearest[a[i]]=i;
    }
    cout<<(res+cmod)%cmod<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

//1 4 8
