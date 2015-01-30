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
string a,b;
const int maxn=10000+10;
const int maxm=1000+10;
int F[maxn][maxm];
int next[maxm];
int nex[maxm][30];
int n,m,j;
int res;

void prekmp()
{
    next[1]=0;
    FOR(i,2,m)
    {
        j=next[i-1];
        while (j>0&&b[j+1]!=b[i]) j=next[j];
        if (b[j+1]==b[i]) j++;
        next[i]=j;
    }
    FOR(i,0,m-1)
    FOR(c,'a','z')
    {
        int l=i;
        while (l!=0&&c!=b[l+1]) l=next[l];
        if (c==b[l+1])
        nex[i][c-'a']=l+1;
        else
        nex[i][c-'a']=l;
    }
}

int main()
{
    //freopen("necklace.in4","r",stdin);
    //freopen("necklace.out","w",stdout);
    cin>>a;
    cin>>b;
    a=" "+a;
    b=" "+b;
    n=a.length()-1;
    m=b.length()-1;
    FOR(i,0,n)
    FOR(j,0,m) F[i][j]=n;
    F[0][0]=0;
    prekmp();
    //cout<<a<<endl;
    //cout<<b<<endl;
    FOR(i,0,n-1)
    FOR(j,0,m-1)
    {
        if (F[i][j]==n) continue;
        F[i+1][j]=min(F[i+1][j],F[i][j]+1);
        F[i+1][nex[j][a[i+1]-'a']]=min(F[i+1][nex[j][a[i+1]-'a']],F[i][j]);
    }
    int res=n;
    FOR(j,0,m-1)
    res=min(res,F[n][j]);
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

