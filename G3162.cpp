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
const int maxn=12;
string st;
int m;
string s[maxn];
int l[maxn];
int r[maxn];
int h;
int res;
map<int,int> d[maxn];
map<int,bool> daco;
int main()
{
    //freopen("G316.inp","r",stdin);
    //freopen("G1316.out","w",stdout);
    cin>>st;
    cin>>m;
    FOR(i,1,m)
    {
        cin>>s[i]>>l[i]>>r[i];
        d[i].clear();
        FOR(j,0,st.length()-1)
        {
            h=0;
            FOR(k,j,st.length()-1)
            {
                h=h*1000003+s[i][k];
                d[i][h]+=1;
            }
        }
    }
    res=0;
    daco.clear();
    FOR(i,0,st.length()-1)
    {
        h=0;
        FOR(j,i,st.length()-1)
        {
            h=h*1000003+st[j];
            if (daco[h]==true) continue;
            daco[h]=true;
            bool ok=true;
            FOR(k,1,m)
            {
                int u=d[k][h];
                //if (i==2&&j==3) cout<<h<<endl;
                if (u>=l[k]&&u<=r[k]); else
                {
                    ok=false;
                    break;
                }
            }
            if (ok) res++;//,cout<<i<<' '<<j<<endl;
        }

    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

