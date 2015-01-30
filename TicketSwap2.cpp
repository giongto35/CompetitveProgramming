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

const int maxm = 1000+10;
struct event
{
    int vt;
    int p;
    int t;
    event ():vt(0),p(0),t(0){};
    event (int a, int b, int c):vt(a),p(b),t(c){}

    bool operator == (event n)
    {
        return make_pair(vt,t) == make_pair(n.vt,n.t);
    }

};
int l[maxm],r[maxm],p[maxm];
int n,m,T,top,bot;
vector<event> e;
pair<int,int> st[maxm*2];
const int cmod = 1000002013;
long long res;
long long oldres;
bool mycmp(event a,event b)
{
    return make_pair(a.vt,a.t) < make_pair(b.vt,b.t);
}

long long calc(int l)
{
    l--;
    return ((long long)(l+1) * l / 2)% cmod;
}

int main()
{
    freopen("A-large-practice.in","r",stdin);
    freopen("ticketswap.out","w",stdout);
    scanf("%d",&T);
    for (int sT = 1; sT <= T; sT++)
    {
        e.clear();
        res = 0;
        oldres = 0;
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d",&l[i],&r[i],&p[i]);
            e.push_back(event(l[i],p[i],1));
            e.push_back(event(r[i],p[i],2));
            oldres = (oldres+((long long)(p[i])*calc(r[i]-l[i])) % cmod) % cmod;
        }
        sort(e.begin(),e.end(),mycmp);
        //vector<event>::iterator it = unique(e.begin(),e.end());
        //e.resize(distance(e.begin(),it));
        for (int i = 0; i < e.size(); i++)
        {
            if (e[i].t == 1)
                st[++top] = make_pair(e[i].p,e[i].vt);
            else
            {
                while (top > 0)
                {
                    int gtmin = min(st[top].first,e[i].p);
                    st[top].first -= gtmin;
                    e[i].p -= gtmin;
                    res = ((res + (long long)gtmin*calc(e[i].vt - st[top].second))% cmod)% cmod;
                    //cout<<gtmin<<' '<<e[i].vt<<' '<<st[top].second<<' '<<res<<  endl;
                    if (st[top].first == 0) top--;else break;
                    if (e[i].p == 0) break;
                }

            }
        }
        cout<<"Case #"<<sT<<": "<<(res - oldres + cmod) % cmod<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

