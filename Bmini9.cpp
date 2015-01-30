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
const int maxn=100000+10;
int sf[maxn], lcp[maxn], test, n,l;
string s;
int head[maxn], b[maxn], key[maxn], rank[maxn], Count[1000];
bool mark[maxn];


void suffixarray(string s, int *a, int *lcp) {

    int n=s.length();
    //init
    memset(Count,0,sizeof(Count));
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
string mat;

bool behonbang(int vt)
{
    FOR(i,0,min((int)mat.length()-1,l-vt))
    {
        if (mat[i]<s[vt+i]) return true;
        if (s[vt+i]<mat[i]) return false;
    }
    return true;
}

bool lonhonbang(int vt)
{
    FOR(i,0,min((int)mat.length()-1,l-vt))
    {
        if (mat[i]>s[vt+i]) return true;
        if (s[vt+i]>mat[i]) return false;
    }
    return true;
}

void process()
{
    int resl=l+1;
    int resr=-1;
    int mid;
    int left=0;
    int right=l;

    while (left<=right)
    {
        mid=(left+right)/2;
        if (behonbang(sf[mid]))
        {
            resl=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }

    left=0;
    right=l;
    while (left<=right)
    {
        mid=(left+right)/2;
        if (lonhonbang(sf[mid]))
        {
            resr=mid;
            left=mid+1;
        }
        else
            right=mid-1;
    }
    //cout<<resl<<' '<<resr<<endl;
    cout<<max(0,resr-resl+1)<<endl;
}
int main()
{
    //freopen("Bmini9.inp","r",stdin);
    //freopen("Amini9.out","w",stdout);

    int T;
    cin>>T;
    while (T>0)
    {
        scanf("\n");
        getline(cin,s);
        l=s.length();
        s=s+'@';
        suffixarray(s, sf, lcp);
        cin>>n;
        FOR(i,1,n)
        {
            cin>>mat;
//            cout<<s<<' '<<mat<<endl;
            process();
        }
        scanf("\n");
        T--;
        if (T>0)
        cout<<endl;
    }
}
