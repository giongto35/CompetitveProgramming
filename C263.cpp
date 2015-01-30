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
const int maxn = 100000+10;
vector<int> a[maxn];
int c[maxn],n,u,v;
bool freex[maxn];bool found;

bool thu(int x,int y,int z)
{
    c[1]=x;
    c[2]=y;
    c[3]=z;
    memset(freex,true,sizeof(freex));
    freex[x]=false;
    freex[y]=false;
    freex[z]=false;
    FOR(i,4,n)
    {
        c[i]=0;
        FOR(j,0,a[c[i-2]].size()-1)
            {FOR(k,0,a[c[i-1]].size()-1)
            {
                if (a[c[i-2]][j]==a[c[i-1]][k]&&freex[a[c[i-1]][k]])
                {
                    c[i]=a[c[i-2]][j];
                    freex[c[i]]=false;
                    break;
                }
            }
            if (c[i]!=0) break;
        }
        if (c[i]==0) return false;
    }
    bool co=false;
    FOR(j,0,a[c[n-1]].size()-1)
    FOR(k,0,a[c[n]].size()-1)
    if ((a[c[n-1]][j]==a[c[n]][k])&&(a[c[n-1]][j]==c[1])) co=true;
    bool co2=false;
    FOR(k,0,a[c[n]].size()-1)
    if (a[c[n]][k]==c[2]) co2=true;
    return co&&co2;
}

int main()
{
    //freopen("C263.inp","r",stdin);
    //freopen("C263.out","w",stdout);
    cin>>n;
    FOR(i,1,2*n)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    found=false;
    int s1=(rand()-1)%n+1;
    FOR(i,1,n) if (a[i].size()!=4)
    {
        cout<<-1;
        return 0;
    }
    FOR(i,0,a[s1].size()-1)
    {
        int y=a[s1][i];
        FOR(j,0,a[s1].size()-1)
        if (j!=i)
        FOR(k,0,a[y].size()-1)
        if (a[s1][j]==a[y][k])
        if (thu(s1,y,a[s1][j]))
        {
            //cout<<1<<' '<<y<<' '<<a[1][j]<<endl;
            FOR(j,1,n) cout<<c[j]<<' ';
            found=true;
            return 0;
        }
    }
    if (found==false) cout<<-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

