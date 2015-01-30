#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define DOW(i, a, b) for(int i=a; i>=b; i--)
#define FOREACH(it, c) for(typeof(c.begin()) it=c.begin(); it!=c.end(); it++)
#define RESET(c, val) memset(c, val , sizeof(c))
#define maxn 100005

int sf[maxn], lcp[maxn], test, n;
string s;
int head[maxn], b[maxn], key[maxn], rank[maxn], Count[1000];
bool mark[maxn];

void suffixarray(string s, int *a, int *lcp) {
    //int head[maxn], b[maxn], key[maxn], rank[maxn], Count[1000];
    //bool mark[maxn];
    s=s+"@"; int n=s.length();
    //init
    RESET(Count, 0);
    FOR(i, 0, n-1) Count[s[i]]++;
    FOR(i, 1, 300) Count[i]+=Count[i-1];
    DOW(i, n-1, 0) {
        char c=s[i]; Count[c]--; a[Count[c]]=i;
    }
    mark[0]=true;
    FOR(i, 1, n-1) mark[i]=s[a[i]]!=s[a[i-1]];
    //process
    int len=1, nkeys, kv; 
    while (len<n) {
        nkeys=0;
        FOR(i, 0, n-1) {
            if (mark[i]) head[nkeys]=i, nkeys++;
            key[a[i]]=nkeys-1;
            b[i]=(a[i]-len+n)%n;
        }
        if (nkeys==n) break;
        FOR(i, 0, n-1) kv=key[b[i]], a[head[kv]]=b[i], head[kv]++;
        kv=-1;
        FOR(i, 0, n-1) {
            int j=(a[i]+len)%n;
            if (key[j]!=kv) mark[i]=true, kv=key[j];
        }
        len<<=1;
    }
    FOR(i, 0, n-1) rank[a[i]]=i;
    lcp[0]=0; int q=0;
    FOR(i, 0, n-2) {
        int j=a[rank[i]-1];
        while (s[i+q]==s[j+q]) q++;
        lcp[rank[i]]=q;
        if (q>0) q--;
    }
}
int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    scanf("%d\n", &test);
    FOR(t, 1, test) {
        getline(cin, s); n=s.length();
        suffixarray(s, sf, lcp);
        long long res=1LL*n*(n+1)/2;
        FOR(i, 0, n) res-=lcp[i];
        cout << res << endl;
    }
    //system("pause");
    return 0;
}
