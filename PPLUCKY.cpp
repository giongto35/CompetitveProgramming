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

const int maxn = 100000+10;
int spt,T,n;
string st;
int s[maxn];
int F[maxn];
int next[maxn];
long long res;
int BIT[maxn];
vector<pair<int,int> > d;
int top;
void update(int i,int gt)
{
    i++;
    while (i<=spt)
    {
        BIT[i]+=gt;
        i=i+(i & (-i));
    }
}


int get(int i)
{
    i++;
    int gt=0;
    while (i>=1)
    {
        gt+=BIT[i];
        i=i-(i & (-i));
    }
    return gt;
}

bool mycmp(pair<int,int> a,pair<int,int> b)
{
    if (a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}
int main()
{
    //freopen("PPLucky.inp","r",stdin);
    //freopen("PPlucky.out","w",stdout);
    scanf("%d",&T);
    FOR(i,1,T)
    {
        scanf("%d",&spt);
        getline(cin,st);
        getline(cin,st);
        top=0;
        res=0;
        memset(F,0,sizeof(F));
        memset(next,0,sizeof(next));
        memset(BIT,0,sizeof(BIT));
        FOR(i,0,spt-1) update(i,1);
        FOR(i,0,spt-1)
            {
                //cout<<st[i];
                if (st[i]=='7')
                {
                    if (top>0)
                    {
                        res+=s[top]+1,next[s[top]]=i,top--;
                        if (top>0) F[s[top]]=max(F[s[top]],F[s[top+1]]+1);
                    }
                }
                else
                {
                    s[++top]=i;
                    F[s[top]]=1;
                }
            }
        d.clear();
        FOR(i,0,spt-1)
        {
            if (st[i]='4'&&next[i]!=0) d.push_back(make_pair(F[i],i));
        }
        sort(d.begin(),d.end(),mycmp);
        res=0;
        FOR(i,0,d.size()-1)
        {
            //cout<<d[i].second<<' '<<get(d[i].second)<<endl;
            res=res+get(d[i].second);
            if (i<=d.size()-1&&d[i].first!=d[i+1].first)
            {
                int j=i;
                while (j>=0&&d[j].first==d[i].first)
                {
                    //cout<<"XOA "<<d[j].second<<" "<<i<<endl;
                    update(d[j].second,-1);
                    update(next[d[j].second],-1);
                    j--;
                }
            }
        }
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

