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
string st;
const int maxn = 100+10;
bool F[maxn][maxn];
int T;
int main()
{
    freopen("balanced_smileystxt.txt","r",stdin);
    freopen("BalanceSmile.out","w",stdout);
    cin>>T;
    getline(cin,st);
    FOR(cs,1,T)
    {
        getline(cin,st);
        memset(F,false,sizeof(F));
        int n=st.length()-1;
        //cout<<st<<' '<<n<<endl;
        FOR(i,0,n) F[i+1][i]=true;
        DOW(i,n,0)
        FOR(j,i,n)
        {
            if (i==j&&st[i]!='('&&st[i]!=')') F[i][j]=true;
            if (i+1==j&&st[i]==':'&&(st[j]=='('||st[j]==')')) F[i][j]=true;
            if (st[i]=='('&&st[j]==')')
            {
                F[i][j]=F[i][j]|F[i+1][j-1];
            }
            FOR(k,i,j-1)
            {
                F[i][j]=F[i][j]|(F[i][k]&F[k+1][j]);
            }
        }
        printf("Case #%d: ",cs);
        if (F[0][n]) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

