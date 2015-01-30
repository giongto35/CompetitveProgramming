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
#define fi first
#define se second
typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int maxn=400+10;
struct point
{
    int x;
    int y;
} a[maxn];
int cnt[maxn],n,u,v;
bool used[maxn];
int link[maxn][5];
double cur;
const double eps = 0.000000001;
bool change;

bool mycmp(point a,point b)
{
    return a.y>b.y;
}

double dist(point u,point v)
{
    return sqrt((u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y));
}

int main()
{
    freopen("E277.inp","r",stdin);
    //freopen("E277.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i].x>>a[i].y;
    sort(a+1,a+1+n,mycmp);
    used[1]=true;
    FOR(i,1,n)
    {
        FOR(j,i+1,n)
        {
            if (cnt[i]<2&&a[i].y>a[j].y&&used[j]==false)
            {
                cnt[i]++;
                used[j]=true;
                link[i][cnt[i]]=j;
                cur=cur+dist(a[i],a[j]);
            }
        }
    }
    FOR(i,1,n)
    if (used[i]==false)
    {
        cout<<-1;
        return 0;
    }
    while(true)
    {
        change=false;
        FOR(i,1,n)
        FOR(j,1,n)
        {
            if (i==j) continue;
            FOR(k,1,cnt[i])
            FOR(l,1,cnt[j])
            {
                u=link[i][k];
                v=link[j][l];
                if (a[i].y>a[v].y&&a[j].y>a[u].y)
                    if (cur>cur-dist(a[i],a[u])-dist(a[j],a[v])+dist(a[i],a[v])+dist(a[j],a[u])+eps)
                        {
                            cur=cur-dist(a[i],a[u])-dist(a[j],a[v])+dist(a[i],a[v])+dist(a[j],a[u]);
                            link[i][k]=v;
                            link[j][l]=u;
                            change=true;
                        }
            }
            if (cnt[i]<2)
            {
                FOR(l,1,cnt[j])
                {
                    v=link[j][l];
                    if (a[i].y>a[v].y)
                        if (cur>cur-dist(a[j],a[v])+dist(a[i],a[v])+eps)
                        {
                            cur=cur-dist(a[j],a[v])+dist(a[i],a[v]);
                            if (j==2||j==3)
                            {
                                cout<<"   "<<i<<' '<<j<<' '<<v<<endl;
                            }
                            cnt[i]++;
                            cnt[j]--;
                            link[i][cnt[i]]=v;
                            change=true;
                        }
                }
            }
        }
        if (change==false) break;
    }
    printf("%0.6f",cur);
    cout<<endl;
    FOR(i,1,n)
    {
        FOR(j,1,cnt[i])
        cout<<a[i].x<<' '<<a[i].y<<' '<<a[link[i][j]].x<<' '<<a[link[i][j]].y<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
