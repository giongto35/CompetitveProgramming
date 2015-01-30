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

int n,t,m;
int tm,ID;
char prob;
string verdict;
vector<char> c;
pair<int,int> p[1000];
bool ACED[1000][1000];
int main()
{
    //freopen("LastBlood.inp","r",stdin);
    //freopen("LastBlood.out","w",stdout);
    cin>>n>>t>>m;
    FOR(i,1,m)
    {
        cin>>tm>>ID>>prob>>verdict;
        c.push_back(prob);
        if (verdict == "Yes")
        {
            if (!ACED[ID][prob] && p[prob].second <= tm)
            {
                p[prob].first = ID;
                p[prob].second =  tm;
            }
            ACED[ID][prob] = true;
        }
    }
    FOR(i,'A','A'+n-1)
    {
        if (p[i].first == 0)
            cout<<(char)i<<' '<<"-"<<' '<<"-"<<endl; else
        cout<<(char)i<<' '<<p[i].second<<' '<<p[i].first<<endl;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

