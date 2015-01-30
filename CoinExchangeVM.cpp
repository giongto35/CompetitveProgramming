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
const int maxn=1000+10;
const int maxc=10000;
const int oo=1000000000;
int n;
int a[maxn];
int F[maxc];
int T;

void process()
{
        F[0]=0;
        FOR(i,1,a[n]*2)
        {
            F[i]=oo;
            int c=-1;
            FOR(j,1,n)
            {
                if (a[j]>i) break;
                c=max(c,a[j]);
                F[i]=min(F[i],F[i-a[j]]+1);
            }
            if (F[i]==oo||F[i]!=F[i-c]+1)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
}

int main()
{
    freopen("CoinExchange.inp","r",stdin);
    //freopen("CoinExchange.out","w",stdout);
    cin>>T;
    while (T>0)
    {
        cin>>n;
        FOR(i,1,n) cin>>a[i];
        sort(a+1,a+1+n);
        process();
        T--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

