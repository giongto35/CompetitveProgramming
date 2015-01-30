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
int st[maxn],a[maxn],b[maxn];
int top,n,t;
int main()
{
    //freopen("C286.in","r",stdin);
    //freopen("C286.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    cin>>t;
    FOR(i,1,t)
    {
        int x;
        cin>>x;
        b[x]=2;
    }
    top=0;
    DOW(i,n,1)
    {
        if (b[i]==2)
        {
            st[++top]=i;
            continue;
        }
            if (top>0&&a[st[top]]==a[i])
            {
                b[i]=1;
                b[st[top]]=2;
                top--;
            }
            else
                st[++top]=i;
    }
    if (top>0) cout<<"NO";
        else
    {
        cout<<"YES"<<endl;
        FOR(i,1,n)
        {
            if (b[i]==2) cout<<'-';
            cout<<a[i]<<' ';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

