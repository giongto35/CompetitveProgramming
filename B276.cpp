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
string s;
int cnt[100];
int res;
int main()
{
    //freopen("B276.inp","r",stdin);
    //freopen("B276.out","w",stdout);
    cin>>s;
    FOR(i,0,s.length()-1)
        cnt[s[i]-'a']++;
    FOR(i,0,'z'-'a')
    {
        if (cnt[i]%2==1) res++;
    }
    if (res==0) cout<<"First";
    else
    if (res%2==1) cout<<"First";
    else
        cout<<"Second";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

