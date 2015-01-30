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
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int hy[4]={0,1,0,-1};
const int hx[4]={1,0,-1,0};
const int maxn = 1000+10;
struct point
{
    int y,x;
} q[maxn*maxn],v;
int dd[maxn*maxn];
int n,m,res;
string st;
char a[maxn][maxn];
bool used[maxn][maxn];
int fr,re;
int bd;
vector<pair<int,int> > e;

point make_point(int y,int x)
{
    point p;
    p.y=y;
    p.x=x;
    return p;
}

void process()
{
    fr=0;
    used[q[fr].y][q[fr].x]=true;
    while (fr<re)
    {
        fr++;
        //cout<<fr<<' '<<q[fr].y<<' '<<q[fr].x<<endl;
        FOR(i,0,3)
        {
            v=make_point(q[fr].y+hy[i],q[fr].x+hx[i]);
            //cout<<v.y<<' '<<v.x<<endl;
            if (v.y>=1&&v.y<=n&&v.x>=1&&v.x<=m&&used[v.y][v.x]==false&&a[v.y][v.x]!='T')
            {
                used[v.y][v.x]=true;
                q[++re]=v;
                dd[re]=dd[fr]+1;
                if (a[v.y][v.x]>='1'&&a[v.y][v.x]<='9') e.push_back(make_pair(dd[re],a[v.y][v.x]-'0'));
                else
                if (a[v.y][v.x]=='S') bd=dd[re];
            }
        }
    }
    sort(e.begin(),e.end());
    FOR(i,0,e.size()-1)
    {
        //cout<<e[i].first<<' '<<e[i].second<<endl;
        if (e[i].first<=bd) res+=e[i].second;
    }
    //cout<<bd<<endl;
    cout<<res;
}

int main()
{
    //freopen("B329.inp","r",stdin);
    //freopen("B329.out","w",stdout);
    cin>>n>>m;getline(cin,st);
    FOR(i,1,n)
    {
        getline(cin,st);
        FOR(j,1,m)
        {
            a[i][j]=st[j-1];
            if (a[i][j]=='E') q[++re]=make_point(i,j);
        }
    }
    process();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

