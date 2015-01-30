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

const int maxn = 100+10;
int n;
string fn[maxn];
vector<string> a[maxn];
vector<string> sres;
string temp;
int res;
int F[1000][1000];

int calc(vector<string> a, vector<string> b)
{
    memset(F,0,sizeof(F));
    int ketqua = 0;
    for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < b.size(); j++)
    {
        if (a[i] == b[j])
            F[i+1][j+1] = F[i][j] + 1;
        else
            F[i+1][j+1] = 0;
        ketqua = max(ketqua, F[i+1][j + 1]);
    }
    return ketqua;
}

int main()
{
    //freopen("CGYM3.inp","r",stdin);
    //freopen("CGYM3.out","w",stdout);
    cin>>n;
    for (int i = 1; i <= n + 1; i++)
    {
        if (i <= n)
        {
            cin>>fn[i];
            getline(cin,temp);
        }
        for (int j = 0; ; j ++)
        {
            getline(cin, temp);
            if (temp == "***END***") break;
            std::remove(temp.begin(), temp.end(), ' ');
            //cout<<i<<' '<<temp<<endl;
            if (temp.length() > 0)
                a[i].push_back(temp);
        }
    }
    res = 0;
    sres.clear();
    for (int i = 1; i <= n; i++)
    {
        if (res < calc(a[i],a[n+1]))
        {
            res = calc(a[i],a[n+1]);
            sres.clear();
            sres.push_back(fn[i]);
        }
        else
        if (res == calc(a[i], a[n+1]))
        {
            sres.push_back(fn[i]);
        }
    }
    if (sres.size()  == 0) cout<<0;else
    {
        cout<<res;
        for (int i = 0; i < sres.size(); i++) cout<<' '<<sres[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

