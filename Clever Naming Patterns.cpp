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
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int maxn = 1000+10;
const int oo = 1000000000;
const int maxm = 100000;
struct edge{ int x; int y; int c; int f; string s;} e[maxm];
int n,m,s,t;
vector<int> ke[maxn];
int las, fir, res;
int q[maxm], tra[maxn];
int u,v,c;
int N,M,TC;
map<string,int> CH;
int cf(int i) {return e[i].c-e[i].f;}
vector<string> kq;


bool mycmp(string a,string b)
{
    return a[0]<b[0];
}
edge make_edge(const int x,const int y, const int c, const string s)
{
    edge res;
    res.x = x;
    res.y = y;
    res.c = c;
    res.s = s;
    res.f = 0;
    return res;
}

void swap(int &u,int &v)
{
    int tg=u;u=v;v=tg;
}
bool findF() {
    //RESET(tra, 0);
    memset(tra,0,sizeof(tra));
    fir=0, las=0;
    q[0]=s; tra[s]=-1;
    while (fir<=las) {
        int u=q[fir]; fir++;
        FOREACH(i, ke[u])
        {
            if (tra[e[*i].y]==0 && cf(*i)>0) {
                    //cout<<u<<' '<<*i<<endl;
                tra[e[*i].y]=*i;
                las++, q[las]=e[*i].y;
                if (q[las]==t) return true;
            }
        }
    }
    return false;
}
void IncFlow() {
    int u=t, delta=oo, i;
    while (u!=s) {
        i=tra[u];
        delta=min(delta, cf(i));
        u=e[i].x;
    }
    res+=delta;
    u=t;
    while (u!=s) {
        i=tra[u];
        e[i].f+=delta;
        if (i<=m) e[i+m].f-=delta; else e[i-m].f-=delta;
        u=e[i].x;
    }
}

int RunFlow()
{
	FOR(i,1,m) {e[i+m]=e[i];swap(e[i+m].x,e[i+m].y);e[i+m].c=0;}
	FOR(i,0,t) ke[i].clear();
	FOR(i,1,m*2) ke[e[i].x].push_back(i);
	res=0;
	while (findF()) IncFlow();
	kq.clear();
    for (int i = 1; i <= m; i++)
    {
        if (e[i].f > 0 && e[i].x != s && e[i].y != t)
        {
            string st = e[i].s;
            kq.push_back((char)toupper(st[0]) + st.substr(1,(int)st.length()-1));
        }
    }
    sort(kq.begin(),kq.end(),mycmp);
    FOREACH(it,kq)
    {
        cout<<*it<<endl;
    }
}

int main()
{
    //freopen("CleverNamingPatterns.inp","r",stdin);
    //freopen("NKFLOW.out","w",stdout);
    scanf("%d",&TC);
    int cnt=0;
    while (TC>0){
            cnt++;
        cout<<"Case #"<<cnt<<":"<<endl;
        //scanf("%d%d%d%d",&n,&m,&s,&t);
        scanf("%d",&N);
        int M = 'Z' - 'A' + 1;
        m = 0;
        FOR(i,1,N)
        {
            cin>>u;
            string st;
            FOR(j,1,u)
            {
                cin>>st;
                for (int j = 0; j < (int) st.length(); j++)
                    st[j] = tolower(st[j]);
                int d = st[0]-'a'+1;
                e[++m] = make_edge(i,N + d,1,st);
            }
        }
        s = 0;
        t = N + M + 1;
        FOR(i,1,N)
            e[++m] = make_edge(s,i,1,"");
        FOR(i,1,M)
            e[++m] = make_edge(N+i,t,1,"");
        //cout<<m<<' '<<N/6<<endl;
        RunFlow();
        TC--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

