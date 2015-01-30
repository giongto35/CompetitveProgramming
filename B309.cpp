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
const int maxn=1000000+10;
int a[maxn],s[maxn];
int n,r,c;
int l;
string st[maxn];
int nt[maxn];
int res;
int bk[maxn][22];
int bd,kt;
int main()
{
    //freopen("B309.inp","r",stdin);
    //freopen("B309.out","w",stdout);
    cin>>n>>r>>c;
    FOR(i,1,n)
    {
        cin>>st[i];
        a[i]=st[i].length();
        s[i]=s[i-1]+a[i];
    }
    l=1;
    FOR(i,1,n)
    {
        while (l<=i&&s[i]-s[l-1]+i-l>c) l++;
        bk[i][0]=l-1;
        if (bk[i][0]==i) bk[i][0]=-1;
    }

    FOR(j,1,20)
    FOR(i,1,n)
    {
        if (bk[i][j-1]!=-1)
        bk[i][j]=bk[bk[i][j-1]][j-1];
        else
        bk[i][j]=-1;
    }
    FOR(i,1,n)
    {
        int sr=r;
        int p=i;
        DOW(j,20,0)
        {
            if ((sr>=(1<<j))&&(bk[p][j]!=-1))
                {
                    sr-=1<<j;
                    p=bk[p][j];
                }
        }
        if (res<i-p)
        {
            res=i-p;
            bd=p+1;
            kt=i;
        }
    }
    //cout<<bk[n][2]<<endl;
    int sum=1000000000;
    FOR(i,bd,kt)
    {
        sum=sum+1+a[i];
        if (sum>c)
        {
            if (sum<1000000000)
            cout<<endl;
            cout<<st[i];
            sum=a[i];
        }
        else
        cout<<' '<<st[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

