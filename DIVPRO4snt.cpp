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
const int a[10][4]={{0,0,0,0},{0,0,0,0},{1,0,0,0},{0,1,0,0},{2,0,0,0},{0,0,1,0},{1,1,0,0},{0,0,0,1},{3,0,0,0},{0,2,0,0}};
int i;
long long j;
int s2,s3,s5,s7;
int ns2,ns3,ns5,ns7,T,L;
long long V;
vector<pair<long long,unsigned int> > hashs[hashbase];
vector<pair<long long,unsigned int> > F[20];

void sep(long long so,int &i,int &s2,int &s3,int &s5,int &s7)
{
    s7=so%200;
    so/=200;
    s5=so%200;
    so/=200;
    s3=so%200;
    so/=200;
    s2=so%200;
    so/=200;
    i=so;
}

long long ch(int i,int s2,int s3,int s5,int s7)
{
    return (long long)i*200*200*200*200+s2*200*200*200+s3*200*200+s5*200+s7;
}

long long geth(long long n)
{
    int gt=n%hashbase;
    FOREACH(it,hashs[gt])
        if (it->first==n) return it->second;
    return -1;
}

void inserth(long long n,int gt)
{
    hashs[n%hashbase].push_back(make_pair(n,gt));
}

void add(long long n,int val)
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
    long long so = ch(0,100,100,100,100);
    long long gt;
    Q[1]=so;
    inserth(so,1);
    int Fr=1;
    int Re=1;
    while (Fr<=Re)
    {
        //cout<<Fr<<' '<<Re<<endl;
        gt=geth(Q[Fr]);
        sep(Q[Fr],i,s2,s3,s5,s7);
//        cout<<i<<' '<<s2<<' '<<s3<<' '<<s5<<' '<<s7<<endl;
        if (i==36) break;
        FOR(k,1,9)
        {
            //cout<<a[k][1]<<' '<<a[k][2]<<' '<<a[k][3]<<' '<<a[k][4]<<endl;
            if (k!=0)
            {
                ns2=s2+a[k][0]*((i+1)%2*2-1);
                ns3=s3+a[k][1]*((i+1)%2*2-1);
                ns5=s5+a[k][2]*((i+1)%2*2-1);
                ns7=s7+a[k][3]*((i+1)%2*2-1);
            }
            else
            {
                ns2=0;
                ns3=0;
                ns5=0;
                ns7=0;
            }
//            cout<<i+1<<' '<<ns2<<' '<<ns3<<' '<<ns5<<' '<<ns7<<endl;
            long long so =ch(i+1,ns2,ns3,ns5,ns7);
            if (geth(so)==-1)
            {
                inserth(so,0);
                Q[++Re]=so;
            }
            add(so,gt);
        }
        Fr++;
    }
    /*FOR (i,1,Re)
        F[Q[i]/1600000000].push_back(Q[i],geth(Q[i]));*/

    cout<<Re<<endl;
}

void phantich(long long so,int &c2,int &c3,int &c5,int &c7)
{
    c2=0;c3=0;c5=0;c7=0;
    if (so==0) return ;
    while (so%2==0) c2++,so/=2;
    while (so%3==0) c3++,so/=3;
    while (so%5==0) c5++,so/=5;
    while (so%7==0) c7++,so/=7;
}

void process()
{
    int c2,c3,c5,c7;
    phantich(V,c2,c3,c5,c7);

    cout<<geth(ch(L,100+c2,100+c3,100+c5,100+c7))<<endl;
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
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

