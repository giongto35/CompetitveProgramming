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
string a,b;
const int maxn=1000000+10;
//bool F[maxn][2];
int main()
{
    //freopen("C282.in","r",stdin);
    //freopen("C282.out","w",stdout);
    cin>>a;
    cin>>b;
    if (a==b)
    {
        cout<<"YES";
        return 0;
    }
    if (a.length()!=b.length()) {
        cout<<"NO";
        return 0;
    }
    else
    {
        if (a.length()==1)
        {
            if (a!=b)
            {
                cout<<"NO";
                return 0;
            }
            else
            {
                cout<<"YES";
                return 0;
            }
        }
        bool ok=false;
        bool ok2=false;
        FOR(i,0,a.length()-1)
        {
            if (a[i]=='1') ok=true;
            if (b[i]=='1') ok2=true;
        }
        if (ok&&ok2) cout<<"YES";
        else
            cout<<"NO";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
