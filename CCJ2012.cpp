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
const int maxn = 10+2;
int a[maxn];
bool co;
int h[maxn],n,T;

bool check (int u,int v)
{
    FOR(i,u+1,v-1)
    if ((h[v]-h[u])*(i-u)<=(h[i]-h[u])*(v-u)) return false;
    FOR(i,v+1,n)
    if ((h[v]-h[u])*(i-u)< (h[i]-h[u])*(v-u)) return false;
    return true;
}

int main()
{
    freopen("C-small-practice.in","r",stdin);
    freopen("CCJ2012.out","w",stdout);
    cin>>T;
    FOR(ct,1,T)
    {
        cin>>n;
        FOR(i,1,n-1) cin>>a[i];
        FOR(i,1,n) h[i]=0;
        FOR (tick,1,1000000)
        {
            co=false;
            FOR(i,1,n-1)
            if (check(i,a[i])==false)
            {
                //while (check(i,a[i])==false)
                h[a[i]]++;
                co=true;
            }
//FOR(i,1,n) cout<<h[i]<<' ';cout<<endl;
            if (co==false) break;
        }
        cout<<"Case #"<<ct<<": ";
        if (co==true)
        cout<<"Impossible";
        else
        FOR(i,1,n) cout<<h[i]<<' ';cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

