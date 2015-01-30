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
const int cmod = 1000000007;
const int maxn = 20;
int l,r,T;
string st;
long long m10[maxn];
long long F[maxn];
long long sum;
int calc(int s)
{
    if (s<=0) return 0;
    stringstream ss;
    ss<<s;
    st=ss.str();
    //cout<<st<<endl;
    long long res=0;

    FOR(i,1,st.length()-1) res=(res+F[i]*i)%cmod;

    sum=0;
    FOR(i,0,st.length()-1)
    {
        FOR(j,(i==0),st[i]-'0'-1)
        {
            //cout<<i<<' '<<j<<' '<<sum<<' '<<endl;
            //cout<<sum*10+j<<' '<<st.length()-i-1<<' '<<m10[st.length()-i-1]<<' '<<F[st.length()-i-1]<<endl;
            res=(res+(((((long long)(sum*10+j)*m10[st.length()-i-1])%cmod)*m10[st.length()-i-1])%cmod+F[st.length()-i-1])*st.length())%cmod;
        }
        sum=sum*10+(st[i]-'0');
    }
    //cout<<sum<<endl;
    res=(res+sum*st.length())%cmod;
    //res%=cmod;
    //cout<<s<<' '<<res<<endl;
    return res;

}

int main()
{
    //freopen("PPNUM.inp","r",stdin);
    //freopen("PPNUM.out","w",stdout);
    scanf("%d",&T);
    memset(F,0,sizeof(F));
    memset(m10,0,sizeof(m10));
    m10[0]=1;
    m10[1]=10;
    F[0]=0;
    F[1]=1+2+3+4+5+6+7+8+9;
    FOR(i,2,18)
    {
        m10[i]=(m10[i-1]*10)%cmod;
        FOR(j,1,9)
        {
            //cout<<j*m10[i-1]<<' '<<m10[i-1];
            F[i]=(F[i]+(F[i-1]+(((long long)j*m10[i-1])%cmod)*m10[i-1])%cmod)%cmod;
        }
        F[i]=(F[i-1]+F[i])%cmod;
        //cout<<i<<' '<<m10[i]<<' '<<F[i]<<endl;
    }
    FOR(i,1,T)
    {
        cin>>l>>r;
        //cout<<calc(10)<<endl;
        cout<<(calc(r)-calc(l-1)+cmod)%cmod<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

