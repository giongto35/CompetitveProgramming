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
    y=0;
    mx=0;
    x=1;
    while (x<=n)
    {
        int ny=y;
        FOR(i,0,l[x].size()-1)
            ny=max(ny,t[l[x][i]]);
        while(y<ny)
        {
            y++;
            FOR(i,0,r[y].size()-1)
                mx=max(mx,s[r[y][i]]);
        }
        if (x==mx)
        {
            cout<<x<<endl;
            res++;

            while (x<y)
            {
                x++;
                FOR(i,0,l[x].size()-1)
                    ny=max(ny,t[l[x][i]]);
                while(y<ny)
                {
                    y++;
                    FOR(i,0,r[y].size()-1)
                        mx=max(mx,s[r[y][i]]);
                }
            }
        }
        else
        if (r[x].size()>0)
        {
            cout<<-1<<endl;
            return 0;
        }
        x++;
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

