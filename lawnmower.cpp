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
int st,T;
const int maxn=100;
int a[maxn][maxn];
int n,m;
bool r[maxn],c[maxn];

void process()
{
    bool ok;
    memset(r,true,sizeof(r));
    memset(c,true,sizeof(c));
    FOR(k,1,100)
    {
        FOR(i,1,n)
        {
            if (r[i]==false) continue;
            ok=true;
            FOR(j,1,m)
            {
                if (a[i][j]!=0&&k!=a[i][j])
                    {
                        ok=false;
                        break;
                    }
            }
            if (ok)
            {
                r[i]=false;
                FOR(j,1,m) a[i][j]=0;
            }
        }

        FOR(j,1,m)
        {
            if (c[j]==false) continue;
            ok=true;
            FOR(i,1,n)
            {
                if (a[i][j]!=0&&k!=a[i][j])
                    {
                        ok=false;
                        break;
                    }
            }
            if (ok)
            {
                c[j]=false;
                FOR(i,1,n) a[i][j]=0;
            }
        }
    }
    bool co =true;
    FOR(i,1,n)
    FOR(j,1,m)
    if (a[i][j]!=0) co=false;
    if (co) cout<<"YES"<<endl;else cout<<"NO"<<endl;
}

int main()
{
    freopen("lawnmower.inp","r",stdin);
    //freopen("lawnmower.out","w",stdout);
    cin>>T;
    FOR(st,1,T)
    {
        cin>>n>>m;
        FOR(i,1,n)
        FOR(j,1,m) cin>>a[i][j];
        if (st==7)
        {
            cout<<n<<' '<<m<<endl;
            FOR(i,1,n)
            {
            FOR(j,1,m)
            cout<<a[i][j]<<' ';
            cout<<endl;
        }
        }
        printf("Case #%d: ",st);
        process();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

