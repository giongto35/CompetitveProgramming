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
#include <cstring>
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
const int maxn=2000+10;
int a[maxn][maxn];
string s;
int st[maxn];
int F[maxn];
int gt[maxn][maxn];
int H[maxn][maxn];
long long res,sres;
int n,m,top,bot;
long long S[maxn];
long long R[maxn];
int ST[maxn],VT[maxn];

int calc(int col)
{
    FOR(i,1,n)
    {
        top=1;st[top]=0;VT[top]=0;
        H[i][0]=-1;
        memset(F,0,sizeof(F));
        FOR(j,1,m+1)
        {
            if (a[i][j]==col) H[i][j]=H[i-1][j]+1; else H[i][j]=0;
            int temp=j;
            while (H[i][j]<ST[top])
            {
              temp=VT[top];
              //if kq < (i-VT[top])*ST[top] then kq:=(i-VT[top])*ST[top];
              //cout<<i<<' '<<j<<' '<<VT[top]<<' '<<ST[top]<<' '<<ST[top-1]<<endl;
              /*if (i==n)
              cout<<i<<' '<<j<<' '<<R[j-VT[top]]<<' '<<(S[ST[top]]-S[ST[top-1]])<<endl;*/
              res+=R[j-VT[top]]*(S[ST[top]]-S[max(H[i][j],ST[top-1])]);

              top--;
            }
            if (H[i][j]>ST[top])
            {
                ST[++top]=H[i][j];
                VT[top]=temp;
            }

        }
    }
}

int main()
{
    //freopen("LSEA.inp","r",stdin);
    //freopen("LSEA.out","w",stdout);
    cin>>n>>m;
    getline(cin,s);
    FOR(i,1,n)
    {
        getline(cin,s);
        FOR(j,1,m)
        a[i][j]=(s[j-1]=='1');
    }
    memset(H,0,sizeof(H));
    R[1]=1;
    FOR(i,1,m)
    {
        R[i]=R[i-1];
        FOR(j,1,i)
        R[i]=R[i]+j;
    }
    FOR(i,1,n)S[i]=S[i-1]+i;

    //calc(1);
    calc(1);
    FOR(i,1,n)FOR(j,1,m) a[i][j]=1-a[i][j];
    calc(1);
    //cout<<res<<endl;
    sres=0;
    FOR(i,1,n)
    FOR(j,1,m)
    sres=sres+(long long)(i*j)*(n-i+1)*(m-j+1);
    //rot();
    //calc(0);
    //calc(1);
    cout<<sres-res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

