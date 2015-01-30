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

const int maxn = 600+10;
char s[maxn][20];
int F[110][610];
int hash1[maxn];
int hash2[maxn];
vector<int> ke[maxn];
int sz,n,l,m;
int main()
{
    //freopen("B.inp","r",stdin);
    //freopen("B.out","w",stdout);
    while(true)
    {
        scanf("%d%d%d",&n,&l,&m);
        if(n==0&&l==0&&m==0) break;
        FOR(i,1,m)
        {
            scanf("%s",&s[i]);
            ke[i].clear();
        }
        sz=strlen(s[1]);
        FOR(i,1,m)
        {
            hash2[i]=0;hash1[i]=0;
            FOR(j,1,sz-1)
            hash2[i]=hash2[i]*30+(s[i][j]-'a'+1);
            FOR(j,0,sz-2)
            hash1[i]=hash1[i]*30+(s[i][j]-'a'+1);
        }
        FOR(i,1,m)
        FOR(j,1,m)
        {
            if (hash2[i]==hash1[j])
                ke[i].push_back(j);
        }
        memset(F,0,sizeof(F));
        FOR(i,1,m) F[sz][i]++;
        FOR(i,sz,l-1)
        FOR(j,1,m)
        {
            if (F[i][j]>0)
            {
                FOR(k,0,ke[j].size()-1)
                F[i+1][ke[j][k]]+=F[i][j];
            }
        }
        int res=0;
        FOR(j,1,m) res+=F[l][j];
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

