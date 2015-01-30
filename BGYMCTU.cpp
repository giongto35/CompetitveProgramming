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

long long A,B;
map<long long, int> c;
int cnt;
int SA,SB;

void process()
{
        c.clear();
        cnt = 0;
        while (A != 1)
        {
            c[A] = cnt++;
            if (A % 2 == 0)
            {
                A = A / 2;
            }
            else
            {
                A = A * 3 + 1;
            }
        }
        c[A] = cnt;

        cnt = 0;
        while (B != 1)
        {
            if (c.count(B) > 0)
            {
                cout<<SA<<" needs "<<c[B]<<" steps, "<<SB<<" needs "<<cnt<<" steps, they meet at "<< B<<endl;
                return;
            }
            if (B % 2 == 0)
            {
                B = B / 2;
            }
            else
            {
                B = B * 3 + 1;
            }
            cnt++;
        }
        if (c.count(B) > 0)
        {
                cout<<SA<<" needs "<<c[B]<<" steps, "<<SB<<" needs "<<cnt<<" steps, they meet at "<< B<<endl;
                return;
        }
}

int main()
{
    //freopen("BGYMCTU.inp","r",stdin);
    //freopen("BGYMCTU.out","w",stdout);
    while(cin>>A>>B)
    {
        if (A == 0 && B == 0) break;
        SA = A;
        SB = B;
        process();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

