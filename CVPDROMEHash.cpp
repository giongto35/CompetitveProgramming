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
const int maxn = 3*
100000+10;
char s[maxn];
map<long long,int> sl,sl2;
map<long long,int>::iterator it;
map<long long,int>::iterator xx;
long long bit;
int vt;
int n;
long long res;
int main()
{
    freopen("CVPDROME.inp","r",stdin);
    //freopen("CVPDROME.out","w",stdout);
    cin>>n;
    /*/string temp;
    getline(cin,temp);*/
    scanf("%s",s+1);

    bit=0;
    sl[0]++;
    FOR (i,1,n)
    {
        if (s[i]<='Z') vt=s[i]-'A';else vt=s[i]-'a'+26;
        bit^=(long long)1<<vt;
        sl[bit]=1;
    }

    bit=0;
    FOR(j,0,51) sl2[bit^((long long)1<<j)]++;
    sl[0]++;
    FOR (i,1,n)
    {
        if (s[i]<='Z') vt=s[i]-'A';else vt=s[i]-'a'+26;
        bit^=(long long)1<<vt;
        res+=sl[bit]-1+sl2[bit];
        FOR(j,0,51)
        {
            long long nb = bit^((long long)1<<j);
            if (sl[nb]>0)sl2[nb]++;
        }
        sl[bit]++;
    }
    /*
    for(it=sl.begin();it!=sl.end();it++)
    {
        cout<<it->first<<' '<<it->second<<' '<<sl2[it->first]<<endl;
        res+=(long long)it->second*(it->second-1)/2+(long long)it->second*(sl2[it->first]-1);
    }*/

    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

