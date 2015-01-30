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
const int d[3]={0,4,7};
const int maxcs = 20;
struct tracer
{
    int i,j;
    int s1,s2,s3,s4,s5,s6;
} tr[maxcs][10];
struct p6
{
    int i1,i2,i3,i4,i5,i6;
} t6[100];
string s;
int t;
int G[100];
bool F[maxcs][10];
long long so[6];

p6 m6(int i1,int i2,int i3,int i4,int i5,int i6)
{
    p6 u;
    u.i1=i1;
    u.i2=i2;
    u.i3=i3;
    u.i4=i4;
    u.i5=i5;
    u.i6=i6;
    return u;
}

tracer maketrace(int i,int j,int k)
{
    tracer res;
    res.i=i;
    res.j=j;
    res.s1=d[t6[k].i1];
    res.s2=d[t6[k].i2];
    res.s3=d[t6[k].i3];
    res.s4=d[t6[k].i4];
    res.s5=d[t6[k].i5];
    res.s6=d[t6[k].i6];
    return res;
}

void trace(int i,int j)
{
    if (i==0&&j==0) return;
    so[0]=so[0]*10+tr[i][j].s1;
    so[1]=so[1]*10+tr[i][j].s2;
    so[2]=so[2]*10+tr[i][j].s3;
    so[3]=so[3]*10+tr[i][j].s4;
    so[4]=so[4]*10+tr[i][j].s5;
    so[5]=so[5]*10+tr[i][j].s6;
    trace(tr[i][j].i,tr[i][j].j);
}

int main()
{
    //freopen("E354.inp","r",stdin);
    //freopen("E354.out","w",stdout);
    cin>>t;
    FOR(i1,0,2)
    FOR(i2,0,2)
    FOR(i3,0,2)
    FOR(i4,0,2)
    FOR(i5,0,2)
    FOR(i6,0,2)
    {
        G[d[i1]+d[i2]+d[i3]+d[i4]+d[i5]+d[i6]]=true;
        t6[d[i1]+d[i2]+d[i3]+d[i4]+d[i5]+d[i6]]=m6(i1,i2,i3,i4,i5,i6);
    }

    FOR(i,1,t)
    {
        cin>>s;
        int l=0;int r=s.length()-1;
        while (l<=r)
        {
            char tg=s[l];s[l]=s[r];s[r]=tg;
            l++;r--;
        }
        s=" "+s;
        memset(F,false,sizeof(F));
        F[0][0]=true;
        FOR(i,0,s.length()-2)
        {
            FOR(j,0,4)
            {
                if (F[i][j]==false) continue;
                FOR(k,0,42)
                {
                    if (G[k]&&(k+j)%10==s[i+1]-'0')
                    {
                        F[i+1][(k+j)/10]=true;
                        tr[i+1][(k+j)/10]=maketrace(i,j,k);
                    }
                }
            }
        }
        if (F[s.length()-1][0]==false) cout<<-1<<endl; else
        {
            memset(so,0,sizeof(so));
            trace(s.length()-1,0);
            FOR(i,0,5) cout<<so[i]<<' ';cout<<endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

