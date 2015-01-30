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
#include <ctime>
#include <cstring>
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
const int maxn = 20;

int n,k,m;
int res;
int a[maxn];
int st[maxn];
int top,bot;
int cnt[maxn];
int T;

bool check()
{
    top=0;
    bot=1;
    memset(cnt,0,sizeof(cnt));
    FOR (i,1,n)
    {
        cnt[a[i]]++;
        if (i-k>=1) cnt[a[i-k]]--;
        if (top>=bot&&st[bot]<i-k+1) bot++;
        while (top>=bot&&a[st[top]]<=a[i]) top--;
        top++;st[top]=i;
        if (i>=k&&cnt[a[st[bot]]]>=m) return false;
    }
    return true;
}

void gen(int vt,int sum)
{
    if (vt==n+1)
    {
        if (check())
        res=min(res,sum);
        return;
    }
    gen(vt+1,sum);
    a[vt]+=1;
    gen(vt+1,sum+1);
    a[vt]-=1;
}

int main()
{
    //freopen("LEALCO.inp","r",stdin);
    //freopen("LEALCO.out","w",stdout);
    cin>>T;
    while (T>0)
    {
        cin>>n>>k>>m;
        FOR(i,1,n) cin>>a[i];
        res=1000000000;
        gen(1,0);
        if (res==1000000000) cout<<-1; else cout<<res;
        T--;
        if (T>0)
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

