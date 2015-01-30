
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

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define fi first
#define se second
using namespace std;
const int oo = 1000000000;
const int maxn = 5000+10;
const int maxm = 1000000;

struct edge{ int x; int y; int c; int f;} e[maxm];
vector<int> ke[maxn];
int q[maxm];
int d[maxn][maxn];
int cs[maxn][maxn];
int tra[maxn];
int las,fir,res,s,t,m,u,v,TC,N,M;
int W[maxn],L[maxn],R[maxn];
int sT;
string st[maxn];

void addedge(const int x,const int y, const int c)
{
    e[++m].x = x;
    e[m].y = y;
    e[m].c = c;
    e[m].f = 0;
}

void swap(int &u,int &v)
{
    int tg=u;u=v;v=tg;
}

int cf(int i) {return e[i].c-e[i].f;}
bool findF() {
    memset(tra,0,sizeof(tra));
    fir=0, las=0;
    q[0]=s; tra[s]=-1;
    while (fir<=las) {
        int u=q[fir]; fir++;
        FOREACH(i, ke[u])
            if (tra[e[*i].y]==0 && cf(*i)>0) {
                tra[e[*i].y]=*i;
                las++, q[las]=e[*i].y;
                if (q[las]==t) return true;
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
	return res;
}


int n,A,B;

bool trys(int u)
{
	m = 0;
	int MaxWin = W[u] + R[u];
	for (int i = 1; i <= N; i++)
        if (MaxWin < W[i]) return true;
	for (int i = 1; i <= N; i++)
		{
			//cout<<" i = "<<MaxWin-W[i]<<endl;
			//if (MaxWin < W[i]) return true;
			addedge(i,t , MaxWin - W[i]);
		}
	for (int i = 1; i <= N; i++)
	for (int j = i+1; j <= N; j++)
		{
		    if (d[i][j]>0){
		    addedge(s,cs[i][j],d[i][j]);
		    addedge(cs[i][j],i,d[i][j]);
		    addedge(cs[i][j],j,d[i][j]);
		    }
		}
    //cout<<RunFlow()<<' '<<sT<<endl;
	if (RunFlow() == sT) return false; else return true;
}

int main()
{
  freopen("C6.inp","r",stdin);
//    freopen("A.out","w",stdout);
	int cnt = 0;
    while (true)
    {
          cin>>N;
		  if (N == -1) break;
          s = 0;
          M = 0;
		  sT = 0;
		  memset(d,0,sizeof(d));
		  for (int i = 1; i <= N; i++)
		  {
				cin >> st[i];
				cin >> W[i] >> L[i] >> R[i];
				sT += R[i];
				for (int j = 1; j <= N; j++)
					{
					    cin >> d[i][j];
					    if (d[i][j] > 0 && i < j)
					    {
					        ++M;
					        cs[i][j] = N + M;
					    }
					}
		  }
		  sT /= 2;
		  t = N + sT + 1;
		  cnt ++;

		  cout<<"Case "<<cnt<<":"<<endl;
		  for (int i = 1; i <= N; i++)
			if (trys(i))
				cout<<"Team "<<st[i]<<" is eliminated."<<endl;

		  cout<<endl;
          TC--;
    }
	fclose(stdin);
	fclose(stdout);
}


