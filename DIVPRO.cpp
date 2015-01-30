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
#define fi first
#define se second
#define mp make_pair

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int maxn=100000000;
const int base=200;
const int hashbase = 1000007;
long long Q[maxn];
int i;
long long j;
vector<pair<long long,unsigned int> > hashs[hashbase];
vector<pair<long long,unsigned int> > F[37];
int L,T;
long long V;

unsigned int geth(long long n)
{
    int gt=n%hashbase;
    FOREACH(it,hashs[gt])
        if (it->first==n) return it->second;
    return -1;
}

void inserth(long long n,unsigned int gt)
{
    hashs[n%hashbase].push_back(make_pair(n,gt));
}

void add(long long n,unsigned int val)
{
    int gt=n%hashbase;
    FOREACH(it,hashs[gt])
        if (it->first==n)
        {
            it->second+=val;
            return ;
        }
}

void BFS()
{
    unsigned int gt;
    Q[1]=1*100;
    inserth(1*100,1);
    int Fr=1;
    int Re=1;
    while (Fr<=Re)
    {
        gt=geth(Q[Fr]);
        int i=Q[Fr]%100;
        long long j=Q[Fr]/100;
        if (i==36) break;
        cout<<i<<' '<<j<<endl;
        FOR(k,(i==0),9)
        {
            long long so =j*k*100+i+1;
            //cout<<"    "<<j<<' '<<k<<' '<<i<<' '<<so<<endl;
            if (geth(so)==-1)
            {
                inserth(so,0);
                Q[++Re]=so;
            }
            add(so,gt);
        }
        Fr++;
    }
    FOR (i,1,Re)
        F[Q[i]%100].push_back(make_pair(Q[i],geth(Q[i])));
    //FOR (i,1,18) cout<<F[i].size()<<endl;
    cout<<Re<<endl;
    //cout<<Re<<endl;
}

void process()
{
    int sp = (L+1)/2;
    int sd = L-sp;
    unsigned int res=0;
    if (V==0)
    {
        res=1;
        FOR(i,1,sd) res=res*9;
        if (geth(sp)==-1) cout<<0; else
        cout<<geth(sp)*res;
        return;
    }
    FOREACH(it,F[sp])
    {
        if ((it->first/100)%V==0&&it->first/100>0)
        {
            //cout<<it->first<<' '<<it->second<<' '<<geth((it->first/100/V)*100+sd)<<endl;
            res+=it->second*geth((it->first/100/V)*100+sd);
            //cout<<res<<endl;
        }
    }
    cout<<res;
}

int main()
{
    freopen("DIVPRO.inp","r",stdin);
    //freopen("DIVPRO.out","w",stdout);
    BFS();
    cin>>T;
    while(T>0)
    {
        scanf("%d %lld",&L,&V);
        process();
        T--;
        if (T>0) cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

