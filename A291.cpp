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
const int maxn=1000+10;
int a[maxn];
map<int,int> c;
int n;
int spt;
int main()
{
    //freopen("A291.inp","r",stdin);
    //freopen("A291.out","w",stdout);
    cin>>n;
    c.clear();
    FOR(i,1,n)
    {
        cin>>a[i];
        if (a[i]!=0)
        c[a[i]]++;
    }
    for(map<int,int>::iterator it=c.begin();it!=c.end();it++)
    {
        if (it->second>2)
            {
                cout<<-1<<endl;
                return 0;
            }
        else
        if (it->second==2) spt++;
    }
    cout<<spt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

