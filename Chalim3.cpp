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
int n,k,c,u,v;
char ch;
int temp;
int IT[maxn*4];

void update(int node,int l,int r,int &vt,int gt)
{
    if (vt<l||vt>r) return;
    if (l==vt&&vt==r)
    {
        IT[node]=gt;
        return;
    }
    int mid = (l+r)>>1;
    update(node<<1,l,mid,vt,gt);
    update((node<<1)+1,mid+1,r,vt,gt);
    IT[node]=IT[node<<1]*IT[(node<<1)+1];
}

int get(int node,int l,int r,int &u,int &v)
{
    if (v<l||r<u) return 1;
    if (u<=l&&r<=v)
    {
        return IT[node];
    }
    int mid = (l+r)>>1;
    return get(node<<1,l,mid,u,v)*get((node<<1)+1,mid+1,r,u,v);
}

int main()
{
    //freopen("Chalim3.inp","r",stdin);
    //freopen("Chalim3.out","w",stdout);
    while (scanf("%d%d", &n,&k) ==2)
    {
        memset(IT,0,sizeof(IT));
        FOR(i,1,n)
        {
            cin >>c;
            temp=i;
            if (c==0) update(1,1,n,temp,0);
            else
            if (c>0) update(1,1,n,temp,1);
            else
            update(1,1,n,temp,-1);
        }
        FOR(i,1,k)
        {
            cin>>ch;
            cin>>u>>v;
            if (ch=='C')
            {
                if (v==0) update(1,1,n,u,0);
                else
                if (v>0) update(1,1,n,u,1);
                else update(1,1,n,u,-1);
            }
            else
            {
                int res=get(1,1,n,u,v);
                if (res==0) cout<<0;
                else
                if (res>0) cout<<'+';
                else
                cout<<'-';
            }
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

