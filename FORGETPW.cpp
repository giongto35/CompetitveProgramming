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

const int maxn = 100;
char c[maxn];
char p[maxn];
string st;
int T,n;
int main()
{
    //freopen("FORGETPW.inp","r",stdin);
    //freopen("FORGETPW.out","w",stdout);
    scanf("%d",&T);
    for (;T>0;T--){
        scanf("%d\n",&n);
        for (int i = 1; i  <= n; i++)
            scanf("%c %c\n",&c[i],&p[i]);
        getline(cin,st);
        for (int i = 0; i < st.length(); i++)
        {
            for (int j = 1; j <=n; j++)
            {
                if (st[i] == c[j])
                {
                    st[i] = p[j];
                    break;
                }
            }
        }
        int l = 0;
        while (l <= st.size() && st[l] == '0') l++;
        int r = st.size()-1;
        while (r >= 0 && st[r] == '0') r--;
        if (st[r] == '.') r--;
        string temp;
        if (r < l) temp = "0";else
        temp = st.substr(l,r-l+1);
        printf("%s\n",temp.c_str());

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

