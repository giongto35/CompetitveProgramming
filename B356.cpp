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

string st1,st2;
const int maxn = 1000000+10;
int next[maxn];
vector<int> s[maxn];
int cs[maxn];
int vt[maxn];
bool vis[maxn];
int cnt;
int l1,l2;
int ch;
int sum;
int sumd;
long long res;
long long maxl;
long long n,m;

void DFS(int u)
{
    vis[u]=true;
    sum=sum+(st2[u]-'a'==ch);
    s[cnt].push_back(sum);
    cs[u]=cnt;
    vt[u]=s[cnt].size()-1;

    if (vis[(u+l1)%l2]==false) DFS((u+l1)%l2);
}
int main()
{
    //freopen("B356.inp","r",stdin);
    //freopen("B356.out","w",stdout);
    cin>>n>>m;getline(cin,st1);
    getline(cin,st1);
    getline(cin,st2);
    if (st1.length()>st2.length())
    {
        long long tg=n;n=m;m=tg;
        string stg=st1;st1=st2;st2=stg;
    }
    maxl=n*st1.length();

    l1=st1.length();    l2=st2.length();
    res=0;
    for(ch='a'-'a';ch<='z'-'a';ch++)
    {
        memset(vis,false,sizeof(vis));
        cnt=0;
        FOR(i,0,l2-1)
        {
            if (vis[i]==false)
            {
                cnt++;
                sum=0;
                sumd=0;
                DFS(i);
            }
        }
        FOR(i,0,l1-1)
        {
            if (st1[i]-'a'==ch)
            {
                int u=cs[i%l2];
                int v=vt[i%l2];
                int l=s[u].size();
                long long sl=(maxl-1-i)/l1;
                res+=(long long)(sl/l)*s[u][l-1];
                int v2=((v+sl)%s[u].size());
                if (v2<v)
                {
                    if (v==0) res+=s[u][l-1]; else res+=s[u][l-1]-s[u][v-1];
                    res+=s[u][v2];
                }
                else
                {
                    if (v==0) res+=s[u][v2];else
                    res+=s[u][v2]-s[u][v-1];
                    //cout<<res<<' '<<s[u][v2]<<' '<<s[u][v-1]<<' '<<s[u][v2]-s[u][v-1]<<endl;
                }
            }
        }
        FOR(i,1,cnt)s[i].clear();
    }
    cout<<maxl-res;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

