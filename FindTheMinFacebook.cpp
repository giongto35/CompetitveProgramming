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
int VT[maxn],B[maxn],A[maxn];
int T,n,k,res;
long long a,b,c,r;
int main()
{
    freopen("find_the_mintxt.txt","r",stdin);
    freopen("FindTheMin.out","w",stdout);
    cin>>T;
    FOR (cs,1,T)
    {
        cin>>n>>k;
        memset(VT,0,sizeof(VT));
        memset(B,0,sizeof(B));
        cin>>a>>b>>c>>r;
        A[0]=a;
        if (A[0]<=k) VT[A[0]]=0;
        //cout<<A[0]<<' ';
        FOR(i,1,k-1)
        {
            A[i]=((long long)b*A[i-1]+c)%r;
            if (A[i]<=k) VT[A[i]]=i+1;
            //cout<<A[i]<<' ';
        }

        printf("Case #%d: ",cs);
        if (n<=k-1) res=A[n];
        else
        {
            n=(n-k-1)%(k+1)+1;
            int nvt=1;
            FOR (i,0,k)
            {
                if (VT[i]==0)
                {
                    while (B[nvt]!=0) nvt++;
                    B[nvt]=i;
                    //if (i==10) cout<<"CO"<<nvt<<endl;
                    nvt++;
                }
                else
                {
                    if (VT[i]+1<=nvt)
                    {
                        while (B[nvt]!=0) nvt++;
                        B[nvt]=i;
                        nvt++;
                    }
                    else
                    B[VT[i]+1]=i;
                }
            }
            //FOR(i,1,k+1) cout<<B[i]<<' ';
            //cout<<n<<"abc"<<endl;
            cout<<B[n];
        }
        cout<<endl;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//2 3 1 4 2 3
