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
int x,y,d,res;
int main()
{
    //freopen("A279.inp","r",stdin);
    //freopen("A279.out","w",stdout);
    cin>>x>>y;
    d=0;
    d=max(d,-x);
    d=max(d,-y);
    d=max(d,x);
    d=max(d,y);
    if (d==0) res=0;else
    res=(d-1)*4;
    //cout<<d<<endl;
    int xmin=-d;
    int ymin=-d;
    int xmax=d;
    int ymax=d;
    if (x==xmax&&y>ymin+1) res+=1;
    if (y==ymax&&x<xmax) res+=2;
    if (x==xmin&&y<ymax) res+=3;
    if (y==ymin&&x>xmin) res+=4;
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

