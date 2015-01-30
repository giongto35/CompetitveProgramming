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
const int maxn=2000+10;
const int maxm=10000+10;
bool D[maxn];
int res,temp,n,m,u,v,a[maxn],cur,x,y;
int lab[maxm];//,lab2[maxm];

int getroot(int i)
{
    if (lab[i]==-1) return i;
    lab[i]=getroot(lab[i]);
    return lab[i];
}
int calc()
{
    FOR(i,1,m) lab[i]=-1;
    int cnt=m;
    FOR(i,0,n/4-1)
    {
        if (D[i]==0)
            {
                x=getroot(a[i*4+1]);
                y=getroot(a[i*4+2]);
            }
        else
            {
                x=getroot(a[i*4+3]);
                y=getroot(a[i*4+4]);
            }
        if (x!=y)
            {
                cnt--;
                lab[x]=y;
            }
    }
    return cnt;
}

void process()
{
    FOR(i,0,n/4-1) D[i]=rand()%2;
    cur=calc();
    //lab2=lab;
    while(true)
    {
        bool cobien=false;
        FOR(i,0,n/4-1)
        {
            D[i]=1-D[i];
            int v=calc();
            if (cur>v)
            {
                cur=v;
                //lab2=lab;
                cobien=true;
                break;
            }
            else
                D[i]=1-D[i];
        }
        if (cobien==false) break;
    }
    res=min(res,cur);
}

int main()
{
    //freopen("C11XU.inp","r",stdin);
    //freopen("C11XU.out","w",stdout);
    cin>>n>>m;;
    FOR(i,1,n) cin>>a[i];
    res=100000000;
    FOR(i,1,2)
    {
        temp=0;
        process();
    }
    cout<<2*(m-res)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

