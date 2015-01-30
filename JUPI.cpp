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
#include <ctime>
#include <queue>
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
string st;
const int maxn  = 200+10;
char a[maxn][maxn];
int mdist[maxn][maxn][4];
long long cdist[maxn][maxn][4];
int fr,re,ny,nx,n,m,kty,ktx;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};
int mindist;
struct kdl
{
    int y;
    int x;
    int d;
}q[maxn*maxn*4];

void push(int &y,int &x,int d,int &ty,int &tx,int &td)
{
    if (mdist[y][x][d]==0)
    {
        q[++re].y=y;
        q[re].x=x;
        q[re].d=d;
        mdist[y][x][d]=mdist[ty][tx][td]+1;
        cdist[y][x][d]=cdist[ty][tx][td];
    }
    else
    {
        if (mdist[y][x][d]==mdist[ty][tx][td]+1)
            cdist[y][x][d]+=cdist[ty][tx][td];
    }
}
void push(int &y,int &x,int d)
{
    q[++re].y=y;
    q[re].x=x;
    q[re].d=d;
}

void BFS()
{
    int y,x,d;
    mdist[q[1].y][q[1].x][q[1].d]=1;
    cdist[q[1].y][q[1].x][q[1].d]=1;
//    cout<<q[1].y<<' '<<q[1].x<<' '<<q[1].d<<' '<<mdist[q[1].y][q[1].x][q[1].d]<<' '<<cdist[q[1].y][q[1].x][q[1].d]<<endl;
    mindist=-1;
    fr=1;
    while (fr<=re)
    {
        y=q[fr].y;x=q[fr].x;d=q[fr].d;
        //cout<<y<<' '<<x<<' '<<d<<endl;
        if (a[y][x]=='X'&&mindist==-1) mindist=mdist[y][x][d];
        if (mindist!=-1&&mdist[y][x][d]>mindist) break;
        push(y,x,(d-1+4)%4,y,x,d);
        push(y,x,(d+1  )%4,y,x,d);
        ny=y+dy[d];nx=x+dx[d];
        while (ny>=1&&ny<=n&&nx>=1&&nx<=m&&a[ny][nx]!='*')
        {
            //cout<<"      "<<ny<<' '<<nx<<' '<<d<<endl;
            push(ny,nx,d,y,x,d);
            ny=ny+dy[d];nx=nx+dx[d];
        }
        ny=y-dy[d];nx=x-dx[d];
        while (ny>=1&&ny<=n&&nx>=1&&nx<=m&&a[ny][nx]!='*')
        {
            //cout<<"      "<<ny<<' '<<nx<<' '<<d<<endl;
            push(ny,nx,d,y,x,d);
            ny=ny-dy[d];nx=nx-dx[d];
        }
        fr++;
    }
    if (mindist==-1)
    {
        cout<<0<<' '<<0;
        return ;
    }
    long long res=0;
    FOR (i,0,3)
    if (mdist[kty][ktx][i]==mindist)
    res+=cdist[kty][ktx][i];
    cout<<mindist-1<<' '<<res;
}

int main()
{
    //freopen("JUPI.inp","r",stdin);
    //freopen("JUPI.out","w",stdout);
    scanf("%d%d",&n,&m);
    getline(cin,st);
    FOR(i,1,n)
    {
        getline(cin,st);
        FOR(j,1,m)
        {
            a[i][j]=st[j-1];
            if (a[i][j]=='N') push(i,j,0);
            if (a[i][j]=='E') push(i,j,1);
            if (a[i][j]=='S') push(i,j,2);
            if (a[i][j]=='W') push(i,j,3);
            if (a[i][j]=='X') kty=i,ktx=j;
        }
    }
    BFS();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

