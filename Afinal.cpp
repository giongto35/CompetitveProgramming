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
const int maxm=40+10;
const int maxn=20;
struct point
{
    int x;
    int y;
} p[maxn];
int T,n,m;
char a[maxm][maxm];

int main()
{
    freopen("AFinal.in","r",stdin);
    freopen("AFinal.out","w",stdout);
    cin>>T;
    while(T>0)
    {
        scanf("%d%d",&n,&m);getline(cin,st);
        spt=0;
        FOR(i,1,n)
        {
            getline(cin,st);
            FOR(j,1,m)
            {
                a[i][j]=st[j-1];
                if (a[i][j]=='B')
                {
                    p[++spt].y=i;
                    p[spt].x=j;
                }
                if (a[i][j])
            }
        }
        FOR(i,1,n)
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

