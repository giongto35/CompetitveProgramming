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
const int maxd = 300000+10;
const int maxn = 10;
const int dy[8] = {-1,-1,-1,0,1,1,1,0};
const int dx[8] = {-1,0,1,1,1,0,-1,-1};
string a[maxn][maxn];
bool vis[maxn][maxn];
map<string, int> m;
map<string, int> ch;
map<string, int> g;
int sDict;
int T;
string st;
int cres;
int res;
int test_count;
int mres;
string mst;

void DFS(int y, int x, int cnt, string st)
{
	//cout<<y<<' '<<x<<' '<<st<<endl;
	vis[y][x] = true;
	if (m.count(st) > 0) cres += g[st];

	if (m.count(st) > 0 && ch[st] < test_count) 
	{
		res += m[st];
		ch[st] = test_count;
		if (mres < st.length())
		{
			mres = st.length();
			mst = st;
		}
		else
		if (mres == st.length())
		{
			if (mst > st)
				mst = st;
		}
	}
	if (cnt<8) 
	{
		FOR(i,0,7)
	{
		int y2 = y + dy[i];
		int x2 = x + dx[i];
		if (vis[y2][x2] == false)
			DFS(y2, x2, cnt + 1, st + a[y2][x2]);
	}
	}
	vis[y][x] = false;
}

int main()
{
    freopen("large_hand.in","r",stdin);
    freopen("Boggle.out","w",stdout);
    cin>>sDict;getline(cin,st);
    FOR(i,1,sDict)
    {
    	getline(cin,st);
    	g[st]++;
    	if (st.length() == 3 || st.length() == 4) m[st] = 1;
    	else 
    		if (st.length() == 5) m[st] = 2;
    	else 
    		if (st.length() == 6) m[st] = 3;
    	else
    		if (st.length() == 7) m[st] = 5;
    	else 
    		if (st.length() == 8) m[st] = 11;
    }
    cin>>T;
    for(test_count = 1; test_count <= T; test_count++)
    {
    	FOR(i,1,4)
    	{
    		cin>>st;
    		FOR(j,1,4)
    		{
    			a[i][j] = string(1,st[j-1]);
    		}
    	}
    	//FOR(i,1,4) { FOR(j,1,4) cout<<a[i][j]; cout<<endl;}
    	res = 0;
    	cres = 0;
    	mres = 0;
    	mst = "";	

    	FOR(i,1,4)
    	FOR(j,1,4)
    	{
    		memset(vis,true,sizeof(vis));
    		FOR(k,1,4) FOR(l,1,4) vis[k][l]=false;
    		DFS(i, j, 1, a[i][j]);
    	}
    	cout<<res<<' '<<mst<<' '<<cres<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
