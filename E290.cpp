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

const long len = 1000001;

string a, b;
char t[len], p[len];
long next[len];
int F[len];
int main() {

//    freopen("substr.inp", "r", stdin);
//    freopen("substr.out", "w", stdout);

    cin >> b;
    for (int i = 0; i < b.length(); i++) p[i + 1] = b[i];

    int j;
    next[1] = 0;
    for (int i = 2; i <= b.length(); i++){
        j = next[i - 1];
        while (j > 0 && p[j + 1] != p[i]) j = next[j];
        if (p[j + 1] == p[i]) ++j;
        next[i] = j;
    }
    FOR(i,1,b.length())
    {
        if (next[i]==0) F[i]=i;else
        if (F[i-next[i]]==next[i]) F[i]=next[i];
    }
    int cnt=0;
    //FOR(i,1,b.length())cout<<F[i]<<' ';
    DOW(i,b.length(),1)
    {
        if (F[i]!=0)break;//&&next[i]!=i) break;
        if (b[i]=='H')
        cnt++;else cnt--;
    }
    if (cnt%2==0) cout<<"Yes";else cout<<"No";
}
