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
const int maxn = 150+10;
#define maxd 30
#define digit 9
#define base 1000000000

int n,k;
typedef long long ll;

struct bignum {
 ll a[maxd];
 inline void reset() { memset(a, 0, sizeof a); }
 inline ll &operator []( int i) { return a[i]; }
 inline friend bignum operator * (bignum a, bignum b) {
  bignum c;
  c.reset();
  for(int i = maxd-1; i >= 1; i--) {
   ll cr = 0;
   for(int j = maxd-1; j >= 1; j--) {
    if (i+j > maxd-1) {
     int k = i+j-(maxd-1);
     c[k] = c[k] + a[i]*b[j] + cr;
     cr = c[k] / base;
     c[k] = c[k] % base;
    }
   }
  }
  return c;
 }

 inline friend bignum operator * (bignum a,  ll b) {
  bignum c;
  ll cr = 0;
  for(int i = maxd-1; i >= 1; i--) {
   c[i] = (a[i]*b + cr) % base;
   cr = (a[i]*b + cr) / base;
  }
  return c;
 }

 inline friend bignum operator + (bignum a,  ll b) {
  bignum c;
  for(int i = maxd-1; i >= 1; i--) {
   c[i] = (a[i]+b) % base;
   b = (a[i]+b) / base;
  }
  return c;
 }

 inline friend bignum operator + (bignum a,  bignum b) {
  bignum c;
  ll cr = 0;
  for(int i = maxd-1; i >= 1; i--) {
   c[i] = (a[i] + b[i] + cr) % base;
   cr = (a[i] + b[i] + cr) / base;
  }
  return c;
 }

 inline friend bignum operator - (bignum a,  bignum b) {
  bignum c;
  ll cr = 0;
  for(int i = maxd-1; i >= 1; i--) {
   c[i] = a[i]-b[i]-cr;
   if (c[i] < 0) {
    c[i] += base;
    cr = 1;
   }
   else cr = 0;
  }
  return c;
 }

 inline friend bignum operator - (bignum a,  ll b) {
  bignum b1;
  b1.reset();
  b1 = b1+b;
  return a-b1;
 }

 inline friend bignum operator / (bignum a, ll b) {
  bignum c;
  c.reset();
  ll t = 0;
  for(int i = 1; i < maxd; i++) {
   t = t*base + a[i];
   c[i] = t/b;
   t %= b;
  }
  return c;
 }

 inline void print() {
  for(int i = 1; i < maxd; i++)
   if (a[i] > 0) {
    printf("%lld", a[i]);
    for(int j = i+1; j < maxd; j++)
     printf("%09lld", a[j]);
    printf("\n");
    return;
   }
   printf("0\n");
 }

 inline friend bool operator < (bignum a, bignum b) {
  for(int i = 1; i < maxd; i++)
   if (a[i] < b[i]) return 1;
   else if (a[i] > b[i]) return 0;
   return 0;
 }
} F[maxn][maxn],G[maxn][maxn],T[maxn][maxn],GT[maxn],res;
int U[maxn];
bool ok[maxn][maxn];

inline bignum tobignum(string a) {
 bignum c;
 c.reset();
 for(int i = 0; i < a.length(); i++)
  c = c*10 + (a[i]-'0');
 return c;
}
inline bignum tobignum(ll n) {
 bignum c;
 c.reset();
 return c+n;
}

bool check(int i,int j)
{
    FOR(k,1,maxd)
    if (F[i][j].a[k]!=0) return false;
    return true;
}

int main()
{
    //freopen("RABGAME.inp","r",stdin);
    //freopen("RABGAME.out","w",stdout);
    cin>>n>>k;
    F[0][0]=tobignum(1);
    ok[0][0]=true;
    int spt=0;
    GT[0]=tobignum(1);
    FOR(i,1,n) GT[i]=GT[i-1]*i;
    FOR(i,2,k)
    if (k%i==0)
    {
        U[++spt]=i;
        G[spt][i-1]=tobignum(1);
        T[spt][i-1]=G[spt][i-1]*GT[U[spt]-1];
        FOR(j,i,n)
        {
            G[spt][j]=G[spt][j-1]*j/(j-(i-1));
            T[spt][j]=G[spt][j]*GT[U[spt]-1];
        }
    }
    FOR(i,0,n-1)
    FOR(j,0,i)
    {
        //if (F[i][j]==0) continue;
        //if (check(i,j)) continue;
        FOR(l,1,spt)
        {
            if (j-U[l]+1>=0)
            {
                F[i+1][j-U[l]+1]=F[i+1][j-U[l]+1]+F[i][j]*T[l][j];
            }
            else break;
        }
        F[i+1][j+1]=F[i+1][j+1]+F[i][j];
    }
    res=tobignum(0);
    FOR(j,0,n)
        res=res+F[n][j];
    res.print();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
123
213
321
132
2
4
10 10*2+4+2
26 26*2+10*2+4
76 76*2+26*2+10*2+4*2
232
G[j]=C(j,k)
j!
___
k!(j-k+1)!
j!
*/
