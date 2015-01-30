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
int kq[maxn*2];
string st;
int main()
{
    //freopen("A264.inp","r",stdin);
    //freopen("A264.out","w",stdout);
    getline(cin,st);
    int vtl=maxn;
    int vtr=maxn;
    DOW(i,st.length()-1,0)
    {
        if (st[i]=='r') kq[--vtl]=i+1;
        else kq[++vtr]=i+1;
    }
    FOR(i,vtl,vtr)
    if (kq[i]!=0) cout<<kq[i]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

