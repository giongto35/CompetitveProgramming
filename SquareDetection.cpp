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
#define RESET(c,x) memset (c, x, sizeof (c))
#define oo 1000111000
#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int maxn = 30;
int T,n;
string a[maxn];
int lx,ly,rx,ry;
int main()
{
    freopen("square_detector.txt","r",stdin);
    freopen("sqdetection.out","w",stdout);
    cin>>T;
    FOR(tc,1,T)
    {
        cin>>n;
            lx = 1000000000;
            ly = 1000000000;
            rx = 0;
            ry = 0;
        getline(cin,a[0]);

        FOR(i,1,n)
        {
            getline(cin,a[i]);
            FOR(j,0,n-1)
            if (a[i][j]=='#')
            {
                lx=min(lx,j);
                ly=min(ly,i);
                rx=max(rx,j);
                ry=max(ry,i);
            }
        }
        bool ok=true;
        FOR(i,ly,ry)
        FOR(j,lx,rx)
        {
            if (a[i][j] == '.') {ok=false;break;}
        }
        cout<<"Case #"<<tc<<": ";
        if (ok&&(rx-lx)==(ry-ly)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

