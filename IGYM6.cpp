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

int n,m;

struct status {
int num;
int time;
vector<pair<int,int> > last;
status(int n, int t, int l): num(n), time(t), last(l){};
status(): num(0), time(0){};
};

struct kq
{
    string s;
    status st;
};

bool operator < ( status a, status b)
{
    if (a.num == b.num && a.time == b.time)
    {
        for (int i = a.last.size() - 1; i >= 0; i--)
        {
            if (a.last[i].first != b.last[i].first) return a.last[i].first < b.last[i].first;
            if (a.last[i].second != b.last[i].second) return a.last[i].second > b.last[i].second;
        }
    }

    if (a.num == b.num) return a.time < b.time;
    return a.num > b.num;

}
/*
bool operator == ( status a, status b)
{
    if (a.num == b.num) return make_pair(a.time, a.last) == make_pair(b.time, b.last);
    return false;
}
*/
map<string, status> ma;
map<pair<string, string>,int > cnt;
string st;
int ttime,  T;
string res;
string team;
string prob;
const int maxn = 100;
string a[maxn];

bool mycmp(string u, string v)
{
    if (!(ma[u] < ma[v]) && !(ma[v] < ma[u])) return u < v;
    return ma[u] < ma[v];
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("IGYM6.inp","r",stdin);
    //freopen("IGYM6.out","w",stdout);
    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        ma.clear();
        cnt.clear();
        for (int  i = 1; i<=n; i++)
        {
            cin>>st;
            a[i] = st;
            ma[st] = status(0,0,0);
        }
        for (int i = 1; i <= m; i++)
        {
            cin>>ttime>>team>>prob>>res;
            if (cnt[make_pair(team,prob)] != -1){
            if (res == "rejected")
            {
                cnt[make_pair(team,prob)] ++;
            }
            else
            {
                ma[team].time = ma[team].time + ttime + cnt[make_pair(team,prob)] * 20;
                ma[team].num = ma[team].num ++;
                ma[team].last.push_back(make_pair(ttime,cnt[make_pair(team,prob)]));
                cnt[make_pair(team,prob)] = -1;
            }
            }
        }
        int dem =0;/*
        FOREACH(it, ma)
        {
            //cout<<++dem<<' '<<(*it).first<<' '<<(*it).second.num<<' '<<(*it).second.time<<endl;
            sres.push_back()
        }*/
        sort(a+1, a + 1 + n, mycmp);

        for (int i = 1; i <=n; i++)
        {
            if (i == 1 || ma[a[i-1]] < ma[a[i]] ) dem = i;
            cout<<dem<<' '<<a[i]<<' '<<ma[a[i]].num<<' '<<ma[a[i]].time<<' '<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

