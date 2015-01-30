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

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
string s;
const int maxn = 100+10;
const int hashbase = 1000007;
char a[maxn][maxn],b[maxn][maxn];
int h[maxn][maxn],g[maxn][maxn],h2[maxn][maxn],g2[maxn][maxn];
int res;
int m27;
int mn27;
vector<int> hashs[hashbase+10];
int n,m,len,he,T;

void add(int n)
{
    hashs[abs(n%hashbase)].push_back(n);
}

bool found(int n)
{
    int gt=abs(n%hashbase);
    FOREACH(it,hashs[gt])
        if ((*it)==n) return true;
    return false;
}

void recover()
{
    FOR(i,he,n)
    FOR(j,len,m)
    {
        hashs[abs(g[i][j]%hashbase)].clear();
    }
}

bool check(int hi)
{
    he=hi;
    mn27=1;
    FOR (i,1,he) mn27*=m27;
    FOR (i,1,n)
        FOR (j,len,m)
        {
            g[i][j]=g[i-1][j]*m27+h[i][j];
            if (i>=he)
            {
                g[i][j]-=h[i-he][j]*mn27;
                add(g[i][j]);
            }
        }

     FOR (i,1,n)
        FOR (j,len,m)
        {
            g2[i][j]=g2[i-1][j]*m27+h2[i][j];
            if (i>=he)
            {
                g2[i][j]-=h2[i-he][j]*mn27;
                if (found(g2[i][j]))
                {
                    recover();
                    return true;
                }
            }
        }


    recover();
    return false;
}
void process()
{
    int ml=0;
    res=0;
    for(len=1;len<=m;len++)
    {
        m27=1;
        FOR (i,1,len) m27*=27;
        ml=0;

        FOR (i,1,n)
            FOR (j,1,m)
            {
                h[i][j]=h[i][j-1]*27+(a[i][j]-'a'+1);
                if (j>len) h[i][j]-=(a[i][j-len]-'a'+1)*m27;
            }

        FOR (i,1,n)
            FOR (j,1,m)
            {
                h2[i][j]=h2[i][j-1]*27+(b[i][j]-'a'+1);
                if (j>len) h2[i][j]-=(b[i][j-len]-'a'+1)*m27;
            }
/*
        FOR (i,1,n)
        {
            FOR (j,1,m) cout<<h[i][j]<<' ';
            cout<<endl;
        }

        FOR (i,1,n)
        {
            FOR (j,1,m) cout<<h2[i][j]<<' ';
            cout<<endl;
        }*/
        int l=1;
        int r=n;
        while (l<=r)
        {
            int mid=(l+r)/2;
            if (check(mid)) ml = mid,l=mid+1;
            else r=mid-1;
        }
        res=max(res,len*ml);
    }
}

int main()
{
    //freopen("message1.inp","r",stdin);
    //freopen("message1.out","w",stdout);
    cin>>T;
    while (T>0)
    {
        cin>>n>>m;
        getline(cin,s);
        FOR(i,1,n)
        {
            getline(cin,s);
            FOR(j,1,m)
            a[i][j]=s[j-1];
        }
        FOR(i,1,n)
        {
            getline(cin,s);
            FOR(j,1,m)
            b[i][j]=s[j-1];
        }
        process();
        cout<<res<<endl;
        T--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

