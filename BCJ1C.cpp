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

const int maxn = 500+10;
const int cmod = 1000000007;
string s;
int res;
int vt[maxn];

char next[maxn];
bool co[maxn];
bool co2[maxn];
int cnt[maxn];
int degin[maxn];
int degout[maxn];
bool vis[maxn];
pair<int,int> iso[maxn];
char bd;
int T,n;
string ss[maxn];
int main()
{
    freopen("B-small-practice.in","r",stdin);
    //freopen("BCJ1C.out","w",stdout);
    scanf("%d",&T);
    for (int st = 1; st <= T; st++)
    {
        scanf("%d\n",&n);
        res = 0;
        memset(vt,0,sizeof(vt));
        memset(next,0,sizeof(next));
        memset(degin,0,sizeof(degin));
        memset(degout,0,sizeof(degout));
        memset(cnt,0,sizeof(cnt));
        memset(co,false,sizeof(co));
        memset(co2,false,sizeof(co2));
        memset(vis,false,sizeof(vis));
        for (char c = 'a' ; c <= 'z' ; c++)
            cnt[c]++;
        for (int i = 1; i <= n; i++)
        {
            cin>>s;
            cout<<s<<endl;
            ss[i] = s;
            s.resize(distance(s.begin(),unique(s.begin(),s.end())));

            for (int j = 0; j < s.size(); j++)
                co2[s[j]] = true;
            for (int j = 1; j < s.size() - 1; j++)
                iso[s[j]]=make_pair(i,j);
            if (s.size() == 1)
            {
                cnt[s[0]]++;
            }
            else
            {
                next[s[0]] = s[s.size()-1];
                degout[s[0]]++;
                degin[s[s.size()-1]]++;
            }
        }
        for (int i = 1; i<=n; i++)
        {
            for (int j = 0; j < ss[i].length(); j++)
            {
                if (iso[ss[i][j]].first != 0)
                {
                    if (!(i == iso[ss[i][j]].first && j == iso[ss[i][j]].second))
                    {
                        res = -1;
                    }
                }
            }
        }
        cout<<"Case #"<<st<<": ";
        if (res == -1)
            cout<<0<<endl;
        else
        {
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (degin[c] > 1)
                {
                    res = -1;
                    break;
                }
                else
                if (degout[c] > 1)
                {
                    res = -1;
                    break;
                }
            }
            if (res == -1)
            {
                cout<<0<<endl;
            }
            else
            {
                long long sum = 0;
                long long res = 1;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (degin[c] == 0 && degout[c] == 1){
                        char u = c;
                        //cout<<"BD "<<u<<endl;
                        sum++;
                        while (u != 0)
                        {
                            //cout<<"visit "<<u<<endl;
                            vis[u] = true;
                            res = (res * cnt[u]) % cmod;
                            u = next[u];
                            //cout<<"next "<<u<<endl;
                        }
                    }
                }
                for (char c = 'a'; c <= 'z'; c++)
                    if (vis[c] == false && co2[c]) sum++;
                for (int i  = 1; i <= sum; i++)
                    res = (res * i) % cmod;
                cout<<res<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

