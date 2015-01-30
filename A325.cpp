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

long long x1,x2,y11,y2,xmin,ymin,xmax,ymax,sum,n;
int main()
{
    //freopen("A325.inp","r",stdin);
    //freopen("A325.out","w",stdout);
    cin>>n;
    xmin=1000000000;
    xmax=-1000000000;
    ymin=1000000000;
    ymax=-1000000000;
    FOR(i,1,n)
    {
        //scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
        cin>>x1>>y11>>x2>>y2;
        xmin=min(xmin,x1);
        ymin=min(ymin,y11);
        xmax=max(xmax,x2);
        ymax=max(ymax,y2);
        sum=sum+(x2-x1)*(y2-y11);
    }
    if (sum==(xmax-xmin)*(ymax-ymin)&&(xmax-xmin)==(ymax-ymin))
    cout<<"YES";else cout<<"NO";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

