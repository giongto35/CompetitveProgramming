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

string st;
int k;
int main()
{
    //freopen("B435.inp","r",stdin);
    //freopen("B435.out","w",stdout);
    cin>>st>>k;
    for (int i = 0; i < st.length(); i++)
    {
        int vt =0 ;
        for (int j = i+1; j < min((int)st.length(),i+k+1); j++)
        {
            //cout<<i<<' '<<j<<' '<<st[i]<<' '<<st[j]<<endl;
            if (st[j] > st[i])
                if (vt == 0 || st[vt] < st[j])
                    vt = j;
        }
        //cout<<i<<' '<<vt<<endl;
        if (vt != 0){
            k-=(vt - i);
            for (int j = vt; j > i; j--)
                swap(st[j],st[j-1]);
        }
    }
    cout<<st<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

