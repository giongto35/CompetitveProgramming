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
const int maxn=100000+10;
int VT[maxn],B[maxn],A[maxn],cnt[maxn];
int T,n,k,a,b,c,r,res;
int main()
{
    freopen("FindTheMin.inp","r",stdin);
    freopen("FindTheMin2.out","w",stdout);
    cin>>T;
    FOR (cs,1,T)
    {
        cin>>n>>k;
        memset(VT,0,sizeof(VT));
        memset(B,0,sizeof(B));
        cin>>a>>b>>c>>r;
        memset(cnt,0,sizeof(cnt));
        A[0]=a;
        cnt[A[0]]++;
        //cout<<A[0]<<' ';
        FOR(i,1,k-1)
        {
            A[i]=(b*A[i-1]+c)%r;
            cnt[A[i]]++;
            //cout<<A[i]<<' ';

        }
        FOR(i,k,n-1)
        {
            FOR (j,0,k)
            if (cnt[j]==0)
            {
                A[i]=j;
                break;
            }
            cnt[A[i]]++;
            cnt[A[i-k]]--;
        }
        FOR(i,0,n-1) cout<<A[i]<<' ';
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//2 3 1 4 2 3
