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
const int maxn=5000+10;
int a[maxn];
int mex[maxn];
int g[maxn];
int n,spt;
int tolxor;
pair<int,int> p[maxn];
string st;
int main()
{
    //freopen("E305.inp","r",stdin);
    //freopen("E305.out","w",stdout);
    cin>>st;
    FOR(i,1,st.length()-2) if (st[i-1]==st[i+1]) a[i]=1;
    n=st.length()-2;
    FOR(i,1,n)
    {
        FOR(j,1,i) mex[g[j-2]^g[i-j-1]]=i;
        int k=0;
        while (mex[k]==i) k++;
        g[i]=k;
    }
    int i=0;
    int tolxor=0;
    spt=0;
    while (i<=n)
    {
        if (a[i]==0)
        {
            i++;
            continue;
        }
        int j=i;
        while (a[j+1]==1) j++;
        tolxor=tolxor^g[j-i+1];
        p[++spt]=make_pair(i,j);
        i=j+1;
    }
    if (tolxor==0)
    {
        cout<<"Second"<<endl;
        return 0;
    }
    cout<<"First"<<endl;
    FOR(i,1,spt)
    {
        int l=p[i].first;
        int r=p[i].second;

        FOR(j,l,r)
        {
            int resxor=tolxor ^ g[r-l+1];
            resxor=resxor ^ g[j-l-1] ^ g[r-j-1];
            if (resxor==0)
            {
                cout<<j+1<<endl;
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

