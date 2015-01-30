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
const int hx[4]={-1,0,1,0};
const int hy[4]={0,-1,0,1};
const int cmod=1000000;
const int maxn=500;
const int mid=250;
int a[maxn+10][maxn+10];
int t,fr,re,n,x,y;
struct point
{
    int x;
    int y;
} q[1000000+10];


int main()
{
    //freopen("B317.inp","r",stdin);
    //freopen("B3172.out","w",stdout);
    cin>>n>>t;
    fr=0;
    re=1;
    a[mid][mid]=n;
    q[re%cmod].x=mid;
    q[re%cmod].y=mid;

    while (fr<re)
    {
        fr++;
        int x=q[fr%cmod].x;
        int y=q[fr%cmod].y;
        //cout<<x<<' '<<y<<' '<<a[x][y]<<endl;
        if (a[x][y]>=4)
        {
            int k=a[x][y]/4;
            a[x][y]=a[x][y]%4;
            FOR(i,0,3)
            {
                a[x+hx[i]][y+hy[i]]+=k;
                if (a[x+hx[i]][y+hy[i]]>=4)
                {
                    re++;
                    q[re%cmod].x=x+hx[i];
                    q[re%cmod].y=y+hy[i];
                }
            }
        }
    }
    //FOR(i,mid,mid+50){FOR(j,mid,mid+50) cout<<a[i][j]<<' ';cout<<endl;}
    FOR(i,1,t)
    {
        cin>>x>>y;
        x=x+mid;
        y=y+mid;
        if (x>=0&&x<=maxn&&y>=0&&y<=maxn) cout<<a[x][y]<<endl;
        else
            cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

