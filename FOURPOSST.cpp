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
const int maxn = 100000+10;
int a[maxn],b[maxn],c[maxn],d[maxn],n;

int random(int so)
{
    so=((long long)rand()*rand())%so;
}

void swap (int &a,int &b)
{
    int tg;
    tg=a;a=b;b=tg;
}

int main()
{
    //freopen("FOURPOSST.inp","r",stdin);
    freopen("FOURPOS.inp","w",stdout);
    n=10000;
    cout<<n<<endl;
    FOR(i,1,n) a[i]=i,b[i]=i,c[i]=i,d[i]=i;
    FOR(i,1,n) swap(a[i],a[random(i)+1]);
    FOR(i,1,n) swap(b[i],b[random(i)+1]);
    FOR(i,1,n) swap(c[i],c[random(i)+1]);
    FOR(i,1,n) swap(d[i],d[random(i)+1]);
    FOR(i,1,n) cout<<a[i]<<' ';cout<<endl;
    FOR(i,1,n) cout<<b[i]<<' ';cout<<endl;
    FOR(i,1,n) cout<<c[i]<<' ';cout<<endl;
    FOR(i,1,n) cout<<d[i]<<' ';cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

