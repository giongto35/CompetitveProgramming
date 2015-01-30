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

string st1;
string st2;
int T;
int main()
{
    freopen("aIPSC.inp","r",stdin);
    freopen("aIPSC.out","w",stdout);
    scanf("%d",&T);
    for (; T>0; T--)
    {
        cin>>st1;
        cin>>st2;
        //cout<<st1<<' '<<st2<<endl;
        int diff = -1;
        for (int j = 0; j < st2.length(); j++)
            if (st1[j] != st2[j])
            {
                diff = j;
                break;
            }
        if (diff == -1)
        {
            for (int j = st2.length(); j < st1.length(); j++)
                cout<<st1[j];
        }
        else
        {
            int numback = st2.length() - diff;
            int numenter = diff + 1;
            if (numback < numenter)
                for (int i = 1; i <= numback; i++) cout<<'<';
            else
            {
                cout<<'*';
                for (int i = 0; i < diff; i++) cout<<st1[i];
            }
            for (int j = diff; j < st1.length(); j++)
                cout<<st1[j];

        }
            cout<<'*'<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

