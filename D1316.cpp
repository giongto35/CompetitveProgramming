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
int a[maxn];
int b[maxn];
map<long long,bool> c;
int res,n;

void rec()
{
    long long code=0;
    FOR(k,1,n) code=code*20+b[k];//,cout<<b[k]<<' ';cout<<endl;
    if (c[code]==false)
    {
        res++;
        //cout<<res<<endl;
        c[code]=true;
    }
    else
    {
        //FOR(i,1,n) cout<<b[i]<<' ';
        //cout<<endl;
        //cout<<"CO"<<endl;
    }
    FOR(i,1,n)
    FOR(j,i+1,n)
    if (a[i]>=1&&a[j]>=1)
    {
        a[i]--;
        a[j]--;
        int tg=b[i];b[i]=b[j];b[j]=tg;
        rec();
        tg=b[i];b[i]=b[j];b[j]=tg;
        a[i]++;
        a[j]++;
    }
}

int main()
{
    freopen("D1316.inp","r",stdin);
    //freopen("D13162.out","w",stdout);
    FOR(s1,1,10)
    {
        FOR(s2,0,0)
    {
        n=s1+s2;
        //cin>>n;
        //FOR(i,1,n) cin>>a[i],b[i]=i;
        c.clear();
        FOR(i,1,n) b[i]=i;
        FOR(i,1,s1) a[i]=1;
        FOR(i,s1+1,s1+s2) a[i]=2;
        res=0;
        rec();
        cout<<res<<' ';

    }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

