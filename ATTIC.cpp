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
string st;
int cnt,T,top;
int a[maxn];
int main()
{
    //freopen("ATTIC.inp","r",stdin);
    //freopen("ATTIC.out","w",stdout);
    cin>>T;
    getline(cin,st);
    while(T>0)
    {
        getline(cin,st);
        cnt=0;
        top=0;
        FOR(i,0,st.length())
        {
            if (st[i]=='.') cnt++;
            else
            {
                if (cnt>0) a[++top]=cnt;
                cnt=0;
            }
        }
        int res=0;
        int smax=0;
        FOR(i,1,top) if (smax<a[i]) res++,smax=a[i];
        cout<<res<<endl;
        T--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

