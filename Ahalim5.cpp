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
const long long oo = 1000000000000000000LL;
const int maxn =100+10;
pair<int,int> a[maxn];
long long F[maxn][maxn];
int T,n;
int main()
{
    //freopen("Ahalim5.inp","r",stdin);
    //freopen("Ahalim5.out","w",stdout);
    int ct=0;
    while(true)
    {
        ct++;
        cin>>n;
        if (n==0) return 0;
        FOR(i,1,n)
        cin>>a[i].first>>a[i].second;
        FOR(i,1,n)FOR(j,1,n) F[i][j]=oo;
        FOR(i,1,n) F[i][i]=0;
        DOW(i,n,1)
        FOR(j,i+1,n)
        {
            FOR(k,i,j-1)
            F[i][j]=min(F[i][j],F[i][k]+F[k+1][j]+(long long)a[i].first*(long long)a[k+1].first*(long long)a[j].second);
        }
        cout<<"Case "<<ct<<": "<<F[1][n]<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

