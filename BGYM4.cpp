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

string st;
vector<pair<int,int> > pos;
vector<string> kq;
int main()
{
    //freopen("BGYM4.inp","r",stdin);
    //freopen("","w",stdout);
    getline(cin,st);
    for (int i = 0, j =st.length()- 1; i <= j; i++,j--)
    {
        if (st[i]!=st[j])
        {
            pos.push_back(make_pair(i,j));
        }
    }
    if (pos.size() == 0)
    {
        cout<<1<<endl;
        printf("%s",st.c_str());
    }
    else
    if (pos.size() == 1 && st.length() % 2 == 1)
    {
        int mid = st.length() / 2;
        if (st[mid] == st[pos[0].first])
        {
            cout<<1<<endl;
            string res = st;
            swap(res[mid], res[pos[0].second]);
            printf("%s",res.c_str());
        }
        else
        if (st[mid] == st[pos[0].second])
        {
            cout<<1<<endl;
            string res = st;
            swap(res[mid], res[pos[0].first]);
            printf("%s",res.c_str());
        }
        else
            cout<<0<<endl;



    }
    else
    if (pos.size() == 2)
    {
        if (st[pos[0].first] == st[pos[1].first] && st[pos[0].second] == st[pos[1].second])
        {
            cout<<2<<endl;
            string res = st;
            swap(res[pos[0].first], res[pos[1].second]);
            //printf("%s\n",res.c_str());
            kq.push_back(res);
            res = st;
            swap(res[pos[1].first], res[pos[0].second]);
            //printf("%s\n",res.c_str());
            kq.push_back(res);
            sort(kq.begin(),kq.end());
            printf("%s\n%s",kq[0].c_str(),kq[1].c_str());
        }
        else
        if (st[pos[0].first] == st[pos[1].second] && st[pos[0].second] == st[pos[1].first])
        {
            cout<<2<<endl;
            string res = st;
            swap(res[pos[0].first], res[pos[1].first]);
            //printf("%s\n",res.c_str());
            kq.push_back(res);
            res = st;
            swap(res[pos[0].second], res[pos[1].second]);
            //printf("%s\n",res.c_str());
            kq.push_back(res);
            sort(kq.begin(),kq.end());
            printf("%s\n%s",kq[0].c_str(),kq[1].c_str());
        }
        else
            cout<<0<<endl;
    }
    else
        cout<<0<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

