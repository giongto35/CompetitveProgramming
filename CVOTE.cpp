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
const int maxn=10000+10;
map<string,string> ct;
map<string,int> cntct;
map<string,int> cntname;
map<string,int>::iterator it;
string maxct;
string maxname;
int n,m;
string name,country,s;

int main()
{
    //freopen("CVOTE.inp","r",stdin);
    //freopen("CVOTE.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n) cin>>name>>country,ct[name]=country;
    FOR(i,1,m)
    {
        cin>>s;
        cntname[s]++;
        cntct[ct[s]]++;
    }
    cntname["null"]=0;maxname="null";
    cntct["null"]=0;maxct="null";
    for(it=cntct.begin();it!=cntct.end();it++)
        if ((*it).second>cntct[maxct]||((*it).second==cntct[maxct]&&maxct>(*it).first)) maxct = (*it).first;
    for(it=cntname.begin();it!=cntname.end();it++)
        if ((*it).second>cntname[maxname]||((*it).second==cntname[maxname]&&maxname>(*it).first)) maxname = (*it).first;
    cout<<maxct<<endl<<maxname;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

