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
const int maxn = 50;
char c[maxn][maxn];
int d[maxn];
vector<int> vt[maxn];
int a[maxn][maxn];
int n,s[maxn];
int cnt;

void swap (int &u,int &v)
{
    int tg=u;u=v;v=tg;
}
 void DOC()
 {
        FOR(i,1,2*n+1) s[i]=i;
        while (true)
        {
            bool c2=false;
            FOR(j,1,2*n+1)
            FOR(k,j+1,2*n+1)
            {
                int r1=(1-a[s[j]][j])+(1-a[s[k]][k]);
                int r2=(1-a[s[j]][k])+(1-a[s[k]][j]);
                if (r1>r2)
                {
                    //if (r1==r2&&rand()%2==1) continue;
                    c2=true;
                    int tg=s[j];s[j]=s[k];s[k]=tg;
                }
            }
            if (c2==false) break;
        }
        FOR(j,1,2*n+1) a[s[j]][j]=1-a[s[j]][j],cnt=cnt+a[s[j]][j]-(1-a[s[j]][j]);
        int ss[maxn];
        FOR(j,1,2*n+1) ss[s[j]]=j;
        FOR(j,1,2*n+1) cout<<ss[j]<<' ';cout<<endl;
 }

int main()
{
    //freopen("TRANVERSAL.INP","r",stdin);
    srand (time(NULL));
    //freopen("tranversal.out","w",stdout);
    cin>>n;
    FOR(i,1,2*n+1) {scanf("%s",c[i]);
    FOR(j,1,2*n+1) a[i][j]=(c[i][j-1]=='+'),cnt=cnt+a[i][j];}
    //FOR(i,1,2*n+1){ FOR(j,1,2*n+1) cout<<a[i][j];cout<<endl;}
    cout<<"There is solution:"<<endl;
    FOR(i,1,n)
    {
        FOR(j,1,2*n+1) s[j]=j;
        FOR(j,1,2*n+1) swap(s[j],s[rand()%j+1]) ;
        FOR(j,1,2*n+1) a[j][s[j]]=1-a[j][s[j]],cnt=cnt+a[j][s[j]]-(1-a[j][s[j]]),cout<<s[j]<<' ';
        cout<<endl;
    }
    //normalize();
    while (true)
    {
        FOR(i,1,2*n+1) s[i]=i;
        while (true)
        {
            bool c2=false;
            FOR(j,1,2*n+1)
            FOR(k,j+1,2*n+1)
            {
                int r1=(1-a[j][s[j]])+(1-a[k][s[k]]);
                int r2=(1-a[k][s[j]])+(1-a[j][s[k]]);
                if (r1>r2)
                {
                    //if (r1==r2&&rand()%2==1) continue;
                    c2=true;
                    int tg=s[j];s[j]=s[k];s[k]=tg;
                }
            }
            if (c2==false) break;
        }
        FOR(j,1,2*n+1) a[j][s[j]]=1-a[j][s[j]],cnt=cnt+a[j][s[j]]-(1-a[j][s[j]]),cout<<s[j]<<' ';cout<<endl;
        DOC();
        //FOR(i,1,2*n+1){ FOR(j,1,2*n+1) cout<<a[i][j];cout<<endl;}
        if (cnt<=2*n) break;

    }
    //FOR(i,1,2*n+1){ FOR(j,1,2*n+1) cout<<a[i][j];cout<<endl;}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

