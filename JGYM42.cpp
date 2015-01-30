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
#define RESET(c,x) memset (c, x, sizeof (c))
#define oo 1000111000
#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

int n,q;
const int maxn = 60000+10;
pair<string, int> a[maxn];
int lcp[maxn];
long long sum;
int res[maxn];
int st[maxn];
int top;
string temp;

bool cmp2(pair<string,int> u, pair<string,int> v)
{
    if (u.first == v.first) return u.second > v.second;
    return u.first > v.first;
}

void process()
{
    sum = 0;
    top = 0;
    memset(lcp, 0, sizeof(lcp));
    for (int i = 1; i <= n + q; i ++)
    {
        if (i < n+q){
        int l1 = a[i].first.length();
        int l2 = a[i + 1].first.length();
        for (int j = 0; j < min(l1, l2); j++)
            if (a[i].first[j] == a[i + 1].first[j])
            {
                lcp[i]++;
            }
            else
                break;
        }
        //cout<<a[i].first<<' '<<a[i].second<<' '<<lcp[i]<<' '<<top<<' '<<sum<<endl;
        if (a[i].second > 0)
            res[a[i].second] += sum;
        if (i < n + q){
        while (top > 0 && lcp[i] < lcp[st[top]])
        {
            if (a[st[top]].second < 0) sum -= lcp[st[top]];
            top--;
        }
        top++;
        st[top] = i;
        if (a[st[top]].second < 0) sum += lcp[st[top]];
        }
    }
}

int main()
{
    freopen("JGYM4.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    getline(cin,temp);
    for (int i = 1; i <= n; i++)
    {
        getline(cin,a[i].first);
        a[i].second = -i;
    }
    scanf("%d",&q);
    getline(cin,temp);
    for (int i = 1; i <= q; i++)
    {
        getline(cin,a[i + n].first);
        a[i + n].second = i;
    }
    sort(a + 1, a + 1 + n + q);
    sum = 0;
    top = 0;
    memset(lcp, 0, sizeof(lcp));
    for (int i = 1; i <= n + q; i ++)
    {
        if (i < n+q){
        int l1 = a[i].first.length();
        int l2 = a[i + 1].first.length();
        for (int j = 0; j < min(l1, l2); j++)
            if (a[i].first[j] == a[i + 1].first[j])
            {
                lcp[i]++;
            }
            else
                break;
        }
        cout<<a[i].first<<' '<<a[i].second<<' '<<lcp[i]<<' '<<sum<<endl;
        if (a[i].second > 0)
            res[a[i].second] += sum;
        if (i < n + q){
        while (top > 0 && lcp[i] < lcp[st[top]])
        {
            if (a[st[top]].second < 0) sum -= lcp[st[top]];
            top--;
        }
        top++;
        st[top] = i;
        if (a[st[top]].second < 0) sum += lcp[st[top]];
        }
    }

cout<<endl;
    top = 0;
    sum = 0;
    memset(lcp ,0 , sizeof(0));
    for (int i = n + q; i >= 1; i --)
    {
        if (i > 1){
        int l1 = a[i].first.length();
        int l2 = a[i - 1].first.length();
        lcp[i] = 0;
        for (int j = 0; j < min(l1, l2); j++)
            if (a[i].first[j] == a[i - 1].first[j])
            {
                lcp[i]++;
            }
            else
                break;
        }
        cout<<a[i].first<<' '<<a[i].second<<' '<<a[i].first<<' '<<a[i-1].first<<' '<<lcp[i]<<' '<<sum<<endl;
        if (a[i].second > 0)
            res[a[i].second] += sum;
        if (i > 1){
        while (top > 0 && lcp[i] < lcp[st[top]])
        {
            if (a[st[top]].second < 0) sum -= lcp[st[top]];
            top--;
        }
        top++;
        st[top] = i;
        if (a[st[top]].second < 0) sum += lcp[st[top]];
        }
    }

    for (int i = 1; i <= q; i++)
        printf("%d\n",res[i] + n);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

