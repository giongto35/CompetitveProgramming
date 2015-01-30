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
string st;
int s[maxn];
int n,l,r,m;
int main()
{
    //freopen("B313.inp","r",stdin);
    //freopen("B313.out","w",stdout);
    getline(cin,st);
    n=st.length();
    FOR(i,0,n-2)
    {
        s[i+1]=s[i]+(st[i]==st[i+1]);
    }
    cin>>m;
    FOR(i,1,m)
    {
        cin>>l>>r;
        cout<<s[r-1]-s[l-1]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

