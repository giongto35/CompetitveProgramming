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
const int maxn = 110;
int F[maxn][maxn][maxn];
struct tracer
{
    int i,j,k,c;
}tr[maxn][maxn][maxn];
int next[maxn][maxn];
int pi[maxn];
int res;
string s1,s2,s3;
void compute_prefix() {
    int j=0;
    FOR(i, 1, s3.length()-1) {
        while (j>=1 && s3[i]!=s3[j+1]) j=pi[j];
        if (s3[i]==s3[j+1] && i!=j+1) j++, pi[i]=j;
            else pi[i]=0;
    }

    //FOR(i,1,s3.length()-1) cout<<pi[i]<<' ';
    FOR(i,0,s3.length()-2)
    {
        FOR(c,'A','Z')
        {
            int q=i;
            while (q!=0&&s3[q+1]!=c) q=pi[q];
            if (s3[q+1]==c)
                next[i][c-'A']=q+1;
            else next[i][c-'A']=0;
            //cout<<i<<' '<<(char)c<<' '<<next[i][c-'A']<<endl;
        }
    }

}

tracer mt(int i,int j,int k,int c)
{
    tracer res;
    res.i=i;
    res.j=j;
    res.k=k;
    res.c=c;
    return res;
}

void trace(int i,int j,int k)
{
    //cout<<i<<' '<<j<<' '<<k<<endl;
    if (i==0||j==0) return;
    trace(tr[i][j][k].i,tr[i][j][k].j,tr[i][j][k].k);
    if (i==tr[i][j][k].i+1&&j==tr[i][j][k].j+1)
    {
        if (tr[i][j][k].c!=0)
        cout<<(char)tr[i][j][k].c;
    }
}

int main()
{
    //freopen("B346.inp","r",stdin);
    //freopen("B346.out","w",stdout);
    cin>>s1>>s2>>s3;
    s1=" "+s1;
    s2=" "+s2;
    s3=" "+s3;
    compute_prefix();
    FOR(i,0,s1.length()-1)
    FOR(j,0,s2.length()-1)
    {
        FOR(k,0,s3.length()-2)
        {
            if (i+1<=s1.length()-1&&j+1<=s2.length()-1&&s1[i+1]==s2[j+1])
            {
                if (F[i+1][j+1][next[k][s1[i+1]-'A']]<F[i][j][k]+1)
                {
                    F[i+1][j+1][next[k][s1[i+1]-'A']]=F[i][j][k]+1;
                    tr[i+1][j+1][next[k][s1[i+1]-'A']]=mt(i,j,k,s1[i+1]);
                }
            }
            if (i+1<=s1.length()-1)
                if (F[i+1][j][k]<F[i][j][k])
                {
                    F[i+1][j][k]=F[i][j][k];
                    tr[i+1][j][k]=mt(i,j,k,0);
                }
            if (j+1<=s2.length()-1)
                if (F[i][j+1][k]<F[i][j][k])
                {
                    F[i][j+1][k]=F[i][j][k];
                    tr[i][j+1][k]=mt(i,j,k,0);
                }
                //cout<<i<<' '<<j<<' '<<k<<' '<<F[i][j][k]<<' '<<F[4][4][0]<<endl;
        }
    }

    int res=0;
    int vt=0;
    FOR(k,0,s3.length()-2)
    {
        if (res<F[s1.length()-1][s2.length()-1][k])
        {
            res=F[s1.length()-1][s2.length()-1][k];
            vt=k;

        }
    }
    if (res==0) cout<<0;else
    trace(s1.length()-1,s2.length()-1,vt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

