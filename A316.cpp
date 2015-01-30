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
bool C[100];
long long res;
int sl,s0;
bool bd;
int main()
{
    //freopen("A316.inp","r",stdin);
    //freopen("A316.out","w",stdout);
    getline(cin,st);
    res=1;
    sl=0;
    FOR(i,0,st.length()-1)
    {
        if (st[i]=='?')
        {
            if (i==0) res=res*9;
            else s0++;
        }
        if (st[i]>='A'&&st[i]<='Z')
        {
            if (i==0) bd=true;
            if (C[st[i]]==false)
            {
                sl++;
                C[st[i]]=true;
            }
        }
    }
    //cout<<res<<' '<<sl<<endl;
    if (bd==false)
        FOR(i,1,sl) res=res*(11-i);
    else
    {
        FOR(i,1,sl)
        if (i==1) res=res*(10-i);else res=res*(11-i);
    }
    if (res!=0)
    {
        cout<<res;
        FOR(i,1,s0) cout<<0;
    }
    else
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

