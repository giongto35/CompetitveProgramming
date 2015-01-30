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
char key[1000];
char s[1000];
char res[1000][1000];
pair<char,int> g[1000];
int n,m;

int main()
{
    //freopen("A.inp","r",stdin);
    //freopen("A.out","w",stdout);
    while (true)
    {
        scanf("%s",&key);
        if (strcmp(key,"THEEND")==0) break;
        scanf("%s",&s);
        n=strlen(s)/strlen(key);
        //cout<<n<<endl;
        int spt=0;
        FOR(i,0,strlen(key)-1)
            g[i]=make_pair(key[i],i);
        sort(g,g+strlen(key));
        int cs=0;
        FOR(j,0,strlen(key)-1)
        {
            //cout<<g[j].first<<' '<<g[j].second<<endl;
            int x=g[j].second;
            FOR(i,1,n)
                res[i][x+1]=s[cs++];
            //FOR(i,1,n)
            //{FOR(j,0,strlen(key)-1) cout<<res[i][j];cout<<endl;}
        }
        FOR(i,1,n)
        FOR(j,1,strlen(key))
            cout<<res[i][j];
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

