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
map<int,bool> used;
int cnt,n,g;
map<int,int> F;

int rec(int b)
{
    if (F[b]!=0) return F[b]-1;
    vector<int> mex;
    mex.clear();
    FOR(i,0,30)
    {
        if ((b>>i)&1)
        {
            int nb=b;
            for(int j=i+1;j<=31;j=j+(i+1))
                nb=nb&(~(1<<(j-1)));
            //if (b==7) cout<<nb<<' '<<rec(nb)<<endl;
            mex.push_back(rec(nb));
        }
    }
    sort(mex.begin(),mex.end());
    int tr=-1;
    int cnt=0;
    FOR(j,0,mex.size()-1)
    {
        if (mex[j]!=tr)
        {
            tr=mex[j];
            if (cnt!=tr) {F[b]=cnt+1;return cnt;}
            cnt++;
        }
    }
    F[b]=cnt+1;
    return cnt;
}

int main()
{
    //freopen("D317.inp","r",stdin);
    //freopen("D317.out","w",stdout);
    cin>>n;
    //FOR(i,0,29) cout<<rec((1<<i)-1)<<' ';cout<<endl;
    g=0;
    int rem=n;
    FOR(i,1,sqrt(n))
    {
        long long j=i;
        if (used[j]==true) continue;
        if (i==1) cnt=1;
        else
        {
            cnt=0;
            while (j<=n)
            {
                cnt++;
                used[j]=true;
                j=j*i;
            }
        }
        //cout<<i<<' '<<cnt<<' '<<rec((1<<cnt)-1)<<endl;
        rem-=cnt;
        g=g ^ (rec((1<<cnt)-1));
    }
    //cout<<g<<endl;
    //cout<<sqrt(n)<<endl;
    //int rem=n-(int)sqrt(n);
    //cout<<rem<<endl;
    if (rem%2==1) g = g ^ 1;
    if (g==0) cout<<"Petya"; else
    cout<<"Vasya";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

