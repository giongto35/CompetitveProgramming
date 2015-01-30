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
const int maxn=100+10;
string st[maxn],a[maxn],res[maxn];
int spt;
int cnt,n;
map<string,int> c;
int main()
{
    //freopen("A305.inp","r",stdin);
    //freopen("A305.out","w",stdout);
    cin>>n;
    FOR(i,1,n)
    {
        cin>>st[i];
        a[i]=st[i];
        while (st[i].length()<3) st[i]="0"+st[i];
        bool ok=false;
        FOR(j,0,st[i].length()-1)
        if (st[i][j]!='0') st[i][j]='1';
        c[st[i]]++;
    }
    c["100"]=min(c["100"],1);
    c["010"]=min(c["010"],1);
    c["001"]=min(c["001"],1);
    c["011"]=min(c["011"],1);
    if (c["010"]==1||c["001"]==1) c["011"]=0;
    FOR(i,1,n)
    {
        if (c[st[i]]>0)
        {
            c[st[i]]--;
            res[++spt]=a[i];
        }
    }
    cout<<spt<<endl;
    FOR(i,1,spt) cout<<res[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

