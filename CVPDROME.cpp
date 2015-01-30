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
const int maxn = 3*100000+10;
const int hashbase = 1000007;
char s[maxn];
map<long long,int> sl,sl2;
map<long long,int>::iterator it;
long long bit;
int vt;
int n;
long long res;
//long long hashs[hashbase+10];
vector<pair<long long,int> > hashs[hashbase+10];
long long geth(long long n)
{
//    return hashs[n % hashbase];
    int gt=n%hashbase;
    FOREACH(it,hashs[gt])
        if (it->first==n) return it->second;
    return 0;
}

void add(long long n)
{
    //cout<<n<<' '<<n%hashbase<<endl;
//    hashs[n % hashbase]++;
    int gt=n%hashbase;
    FOREACH(it,hashs[gt])
        if (it->first==n)
        {
            it->second++;
            return ;
        }
    hashs[gt].push_back(make_pair(n,1));
}

int main()
{
    //freopen("CVPDROME.inp","r",stdin);
    //freopen("CVPDROME.out","w",stdout);
    cin>>n;
    scanf("%s",s+1);
    bit=0;
    FOR(j,0,51) sl2[bit^((long long)1<<j)]++;
    //FOR(i,0,hashbase) hashs[i].clear();
    add(0);

    FOR (i,1,n)
    {
        if (s[i]<='Z') vt=s[i]-'A';else vt=s[i]-'a'+26;
        bit^=(long long)1<<vt;
        res+=geth(bit);
        FOR(j,0,51) //sl2[bit^((long long)1<<j)]++;
            res+=geth(bit^((long long)1<<j));

        add(bit);
    }
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

