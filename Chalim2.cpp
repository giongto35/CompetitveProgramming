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
int cnt[maxn*2+10],s[maxn],a[maxn];
int res,TC,n;
int main()
{
    //freopen("Chalim2.inp","r",stdin);
    //freopen("Chalim2.out","w",stdout);
    cin>>TC;
    while (TC>0)
    {
        cin>>n;
        s[0]=0;
        memset(cnt,0,sizeof(cnt));
        cnt[maxn+0]=1;
        res=0;/*
        if (n==0)
        {
            string s;
            getline(cin,s);
        }*/
        FOR(i,1,n)
        {
            scanf("%d",&a[i]);

            if (a[i]>0) a[i]=1;else
            a[i]=-1;
            s[i]=s[i-1]+a[i];
            if (cnt[maxn+s[i]]!=0)
            res=max(res,i-cnt[maxn+s[i]]+1);
            else
            cnt[maxn+s[i]]=i+1;
        }
        cout<<res<<endl;
        TC--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

