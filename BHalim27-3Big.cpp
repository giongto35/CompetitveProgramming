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

//BIGNUM
#define maxd 30
#define digit 9
#define base 1000000000
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
};
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
//BIGNUM

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
long long p,q,n;

bignum pow(long long x,long long n)
{
    if (n==0) return tobignum(1);
    if (n%2==0)
    {
        bignum s=pow(x,n/2);
        return s*s;
    }
    else
        return pow(x,n-1)*tobignum(x);
}
bignum F(long long n)
{
    if (n==0) return tobignum(2);
    if (n==1) return tobignum(p);
    if (n%2==0)
    {
        bignum s=F(n/2);
        return s*s-tobignum(2)*pow(q,n/2);
    }
    else
        return F(n-1)*tobignum(p)-F(n-2)*tobignum(q);
}

int main()
{
    //freopen("Bhalim.inp","r",stdin);
    //freopen("Bhalim.out","w",stdout);
    while (true)
    {
        cin>>p>>q>>n;
        if (p==0&&q==0) break;
        //cout<<F(n)<<endl;
        F(n).print();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

