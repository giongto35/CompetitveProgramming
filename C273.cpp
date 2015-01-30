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
const int maxn = 3*100000+10;
pair<int,int> Edge[maxn];
int c[maxn];
int a[maxn][5];
int n,m,u,v,cnt;
bool ok;
int main()
{
    //freopen("C273.inp","r",stdin);
    //freopen("C273.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,m)
    {
        cin>>u>>v;
        a[v][++a[v][0]]=u;
        a[u][++a[u][0]]=v;
    }
    FOR (sl,1,30)
    {
        FOR(j,1,n)
        {
            c[j]=rand()%2;/*
                cnt=0;
                FOR(k,1,a[j][0])
                {
                    if (a[j][k]<j&&c[a[j][k]]==c[j]) cnt++;
                    if (cnt>1)
                    {
                        c[j]=1-c[j];
                        break;
                    }
                }*/
        }
        FOR(t,1,20)
        {
            ok=true;
            FOR(j,1,n)
            {
                cnt=0;
                FOR(k,1,a[j][0])
                {
                    if (c[a[j][k]]==c[j]) cnt++;
                    if (cnt>1)
                    {
                        //c[a[j][k]]=1-c[a[j][k]];
                        //cnt--;
                        ok=false;
                        c[j]=1-c[j];
                        break;
                    }
                }
            }
            if (ok)
            {
                FOR(i,1,n) cout<<c[i];
                return 0;
            }
        }

    }
    cout<<-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

