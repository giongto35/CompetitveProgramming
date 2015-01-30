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
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
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
const int maxn = 500+10;
const int dy[4]={-1,0,1,0};
const int dx[4]={0,1,0,-1};
char a[maxn][maxn];
const int oo=10000000;
string st;
int cnt,res,dir,n,m,y,x;
bool used[maxn][maxn][4];

char ch(int i)
{
    if (i==0) return 'U';
    if (i==1) return 'R';
    if (i==2) return 'D';
    if (i==3) return 'L';
}

void DFS(int y,int x,int d)
{
    used[y][x][d]=true;
    if (y==0||x==0||y==n+1||x==m+1) return ;
    cnt++;
    if (a[y][x]=='\\')
    {
        if (d==0) d=3;else
        if (d==1) d=2;else
        if (d==2) d=1;else
        if (d==3) d=0;
    }
    else
    if (a[y][x]=='/')
    {
        if (d==0) d=1;else
        if (d==1) d=0;else
        if (d==2) d=3;else
        if (d==3) d=2;
    }
    else
    if (a[y][x]=='C') {cnt--;return ;}
    if (used[y+dy[d]][x+dx[d]][d]==true)
    {
        cnt=oo;
        return ;
    }
    else
        DFS(y+dy[d],x+dx[d],d);
}

int main()
{
    //freopen("voyager.inp","r",stdin);
    //freopen("voyager.out","w",stdout);
    cin>>n>>m;
    getline(cin,st);
    FOR(i,1,n)
    {
        getline(cin,st);
        FOR(j,1,m)
            a[i][j]=st[j-1];
    }
        cin>>y>>x;
    res=0;
    FOR(i,0,3)
    {
        memset(used,false,sizeof(used));
        cnt=0;
        DFS(y,x,i);
        if (res<cnt) dir=i,res=cnt;
        if (cnt==oo) break;
    }
    cout<<ch(dir)<<endl;
    if (res==oo) cout<<"Voyager";
    else
        cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

