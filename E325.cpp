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
#include <iomanip>

using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
const double eps = 0.00000001;
const int maxn = 100010;

int u,n;
int se;
int res[maxn];
bool used[maxn];
int main()
{
    //freopen("E325.inp","r",stdin);
    //freopen("E325.out","w",stdout);
    cin>>n;
        res[++se]=0;
        FOR(i,1,n)
        {
            if (used[(res[se]+n)/2]==false)
            {
                res[se+1]=(res[se]+n)/2;
                ++se;
                used[res[se]]=true;
            }
            else
            if (used[res[se]/2]==false)
            {
                res[se+1]=res[se]/2;
                ++se;
                used[res[se]]=true;
            }
            else
            {
                cout<<-1;
                return 0;
            }
        }
        DOW(i,se,1) cout<<res[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

