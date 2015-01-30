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
#include <iomanip>

using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
const int maxN=100000+10;
int n;
int nGroup;
int tam[maxN];
char a[maxN];
int s[maxN];
int pos[maxN];
int key[maxN];
int inv[maxN];
int lcp[maxN];
string st;
int T;

void initsuffix() {
     int i,h,x;
     RESET(tam,0);
     FOR(i,1,n) tam[a[i]]++;
     FOR(i,1,256) tam[i] += tam[i-1];
     DOW(i,n,1) s[tam[a[i]]--] = i;
     x = 0;
     pos[0] = 1;
     key[s[1]] = 0;
     FOR(i,2,n) {
         if (a[s[i]] != a[s[i-1]]) pos[++x] = i;
         key[s[i]] = x;
     }
     h = 1;
     while (h < n) {
           FOR(i,1,n) tam[i]=s[i];
           FOR(i,1,n) if (tam[i] > h) {
               x = tam[i] - h;
               s[pos[key[x]]] = x;
               pos[key[x]]++;
           }
           x = 0;
           pos[0] = 1;
           tam[s[1]] = 0;
           FOR(i,2,n) {
              if ((key[s[i-1]] < key[s[i]]) || ((key[s[i-1]] == key[s[i]]) && (s[i-1] + h <=n) && (s[i] + h <= n) && (key[s[i-1] + h] < key[s[i] + h])))
              pos[++x] = i;
              tam[s[i]] = x;
           }
           FOR(i,1,n) key[i] = tam[i];
           if (x == n-1) break;
           h = h << 1;
     }
};
/*--------------------------------------*/
void initlcp() {
     int i,j,h = 0,x;
     a[n + 1] = '@';
     int result = 0;
     FOR(i,1,n) inv[s[i]] = i;
     FOR(i,1,n)
     if (inv[i] == 1) lcp[1] = 0;
     else {
              x = inv[i];
              j = s[x - 1];
              while (a[j + h] == a[i + h]) h++;
              lcp[x] = h;
              if (h > 0) h--;
          }
}

int main()
{
    //freopen("subst1.inp","r",stdin);
    //freopen("subst1.out","w",stdout);
    cin>>T;getline(cin,st);
    FOR(i,1,T)
    {
        getline(cin,st);
        FOR(i,0,st.length()-1) a[i+1]=st[i];
        n=st.length();
        initsuffix();
        initlcp();
        long long res=(long long)n*(n+1)/2;
        FOR(i,1,n) res-=lcp[i];
        cout<<res<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
