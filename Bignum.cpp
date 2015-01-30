#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

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
