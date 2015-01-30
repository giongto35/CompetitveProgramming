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
int n,m,top,bot,top2,bot2,TC,a[maxn],k,pr;
int st[maxn],st2[maxn];
vector<int> res;
int gtmax;
int main()
{
    //freopen("Bhalim2.inp","r",stdin);
    //freopen("Bhalim2.out","w",stdout);
    cin>>TC;
    while (TC>0)
    {
        scanf("%d %d",&n,&k);
        top=0;
        bot=1;
        top2=0;
        bot2=1;
        gtmax=0;
        pr=0;
        res.clear();
        FOR(i,1,n)
        {
            if (i==1) a[i]=0; else
            scanf("%d",&a[i]);
            pr=a[i]+pr;
            a[i]=pr;
            while (top>=bot&&st[bot]<i-k) bot++;
            while (top2>=bot2&&st2[bot2]<i-k) bot2++;
            //cout<<a[st[top]]<<' '<<a[i]<<endl;
            while (top>=bot&&a[st[top]]<=a[i]) top--;
            while (top2>=bot2&&a[st2[top2]]>=a[i]) top2--;
            //cout<<i<<' '<<a[i]<<' '<<top<<' '<<bot<<' '<<top2<<' '<<bot2<<' '<<a[st[bot]]<<' '<<a[st2[bot2]]<<endl;
            st[++top]=i;
            st2[++top2]=i;
            //cout<<bot<<' '<<top<<endl;
            //FOR(i,bot,top) cout<<a[st[i]]<<' ';
            //cout<<endl;
            if (i>k)
            {
                //cout<<a[st[bot]]<<' '<<a[st2[bot2]]<<endl;
                if (a[st[bot]]-a[st2[bot2]]>gtmax)
                {
                    gtmax=a[st[bot]]-a[st2[bot2]];
                    res.clear();
                    res.push_back(i-k);
                }
                else
                if (a[st[bot]]-a[st2[bot2]]==gtmax)
                {
                    res.push_back(i-k);
                }
             }
        }
        //printf("%d ",gtmax);
        cout<<gtmax<<' ';
        FOR(i,0,res.size()-1)
        {
            cout<<res[i]<<' '<<res[i]+k;
            if (i!=res.size()-1) cout<<' ';
        }
        TC--;
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

