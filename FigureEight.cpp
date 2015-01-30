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
const int maxn=200000+10;
int s[maxn],t[maxn];
vector<int> l[maxn];
vector<int> r[maxn];
int x,y;
int res;
int n,m,mx;
bool mark[maxn];
int IT[maxn*4];

void update(int node,int l,int r,int u,int gt)
{
    if (u<l||u>r) return;
    if (l==u&&u==r)
    {
        IT[node]=max(IT[node],gt);
    }
    int mid=(l+r)/2;
    update(node*2,l,mid,u,gt);
    update(node*2+1,mid+1,r,u,gt);
    IT[node]=max(It[node*2],IT[node*2+1]);
}

int main()
{
    freopen("photo.inp","r",stdin);
    //freopen("photo.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,m)
    {
        cin>>s[i]>>t[i];
        l[s[i]].push_back(i);
        r[t[i]].push_back(i);
    }
    memset(mark,sizeof(mark),true);
    FOR(i,1,n)
    {
        FOR(j,0,r[i].size()-1)
        {
            v=r[i][j];
            if (get(1,1,n,s[v],t[v])>s[v]) mark[v]=false;
        }

        FOR(j,0,r[i].size()-1)
        {
            v=r[i][j];
            if (mark[v])
            update(1,1,n,s[v]);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

