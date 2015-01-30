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
const int maxc=1000000+10;
int r[maxc],c[maxc];
string com1,com2;
int x1,x2,x3,yy1,y2,y3,x,n,m;
int main()
{
    //freopen("BUREK.inp","r",stdin);
    //freopen("BUREK.out","w",stdout);
    cin>>n;
    FOR(i,1,n)
    {
        cin>>x1>>yy1>>x2>>y2>>x3>>y3;
        c[min(min(x1,x2),x3)+1]++;
        c[max(max(x1,x2),x3)]--;
        r[min(min(yy1,y2),y3)+1]++;
        r[max(max(yy1,y2),y3)]--;
    }
    FOR(i,1,1000000) r[i]=r[i-1]+r[i],c[i]=c[i-1]+c[i];
    cin>>m;
    FOR(i,1,m)
    {
        cin>>com1>>com2>>x;
        if (com1=="x") cout<<c[x]<<endl;else cout<<r[x]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

