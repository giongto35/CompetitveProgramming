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
const int maxn = 1003;
const int oo=1000000000;
int C[maxn][maxn];
int F[maxn][maxn];
int tr[maxn];
int freex[maxn];
int tt;
int Q[maxn];
int ll,ct;
int n,s,t,m,i,u,v,a,b;


inline bool findpath() {
    int sz = 0;
    Q[sz++] = s;
    memset(tr, 0, sizeof tr);
    tr[s] = -1;
    for(int id = 0; id < sz; id++) {
        int u = Q[id];
        FOR(v,0,t)
        {
            if (C[u][v] > F[u][v] && !tr[v]) {
                tr[v] = u;
                if (v == t) return 1;
                Q[sz++] = v;
            }
                }
    }
    return 0;
}

int MaxFlow() {
    while (findpath()) {
        int delta = 1e9;
        for(int v = t, u; ; v = u) {
            u = tr[v];
            if (u < 0) break;
            delta = min(delta, C[u][v]-F[u][v]);
        }
        for(int v = t, u; ; v = u) {
            u = tr[v];
            if (u < 0) break;
            F[u][v] += delta;
            F[v][u] -= delta;
            //cout<<v<<' ';
        }
        //cout<<endl;
    }
    int ret = 0;
    for(int u = 1; u <= t; u++)
        ret += F[u][t];
    return ret;
}
int con(string c)
{
    if (c=="XXL") return 1;
    if (c=="XL") return 2;
    if (c=="L") return 3;
    if (c=="M") return 4;
    if (c=="S") return 5;
    if (c=="XS") return 6;
}
int main()
{
    freopen("Bmini6.inp","r",stdin);
    //freopen("Amini6.out","w",stdout);
    int st;
    cin>>st;
    FOR(ct,1,st)
    {
        cin>>n>>m;
        memset(C,0,sizeof(C));
        memset(F,0,sizeof(F));
        memset(freex,0,sizeof(freex));
        int sl=n/6;
        s=0;
        t=m+6+1;
        string s1,s2;
        FOR(i,1,m)
        {
            cin>>s1>>s2;
            //cout<<s1<<' '<<s2<<' '<<con(s1)<<' '<<con(s2)<<endl;
            C[i][m+con(s1)]=1;
            C[i][m+con(s2)]=1;
            C[s][i]=1;
        }
        FOR(i,m+1,m+6)
        {
            C[i][t]=sl;
        }
        //cout<<MaxFlow()<<endl;
/*
        bool kq=true;
        FOR(i,1,b)
        if (C[0][G[i]]!=0)
        {
            kq=false;
            break;
        }*/
        //cout<<MaxFlow()<<' '<<m<<endl;
        if (MaxFlow()==m) cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


