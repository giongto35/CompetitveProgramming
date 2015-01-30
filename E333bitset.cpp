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
#include <iomanip>
#include <ctime>
#include <queue>
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
#define mp(a,b) make_pair((a),(b))
#define X first;
#define Y second;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const int maxn = 3010;
ii a[maxn];
iii e[maxn*maxn];
int se;
int n;
bitset<maxn> b[maxn];

int main()
{
    //freopen("E333.inp","r",stdin);
    //freopen("E333.out","w",stdout);
    cin>>n;
    FOR(i,1,n)
    {
        cin>>a[i].first;
        cin>>a[i].second;
    }
    //cout<<e[1].second.first<<endl;
    FOR(i,1,n) FOR(j,i+1,n)
    {
        e[++se]=make_pair((a[i].first-a[j].first)*(a[i].first-a[j].first)+(a[i].second-a[j].second)*(a[i].second-a[j].second),make_pair(i,j));
    }
    sort(e+1,e+1+se);
    DOW(i,se,1)
    {
        if ((b[e[i].second.first]&b[e[i].second.second]).any())
        {
            cout<<fixed<<setprecision(6)<<sqrt(e[i].first)/2<<endl;
            return 0;
        }
        b[e[i].second.first][e[i].second.second]=1;
        b[e[i].second.second][e[i].second.first]=1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

