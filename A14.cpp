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

int win(int u,int v)
{
    if ( u == 3 && v == 2) return true;
    if ( u == 2 && v == 1) return true;
    if ( u == 1 && v == 3) return true;
    return false;
}
int main()
{
    //freopen("A14.inp","r",stdin);
    //freopen("","w",stdout);
    string st1,st2;
    cin>>st1;
    cin>>st2;
    int res =0;
    for (int i =0 ; i <st1.length(); i+=2)
    {
        int s1 = 0;
        if (st1[i] == '(' && st1[i+1] == ')') s1=1;
        if (st1[i] == '[' && st1[i+1] == ']') s1=2;
        if (st1[i] == '8' && st1[i+1] == '<') s1=3;
        int s2 = 0;
        if (st2[i] == '(' && st2[i+1] == ')') s2=1;
        if (st2[i] == '[' && st2[i+1] == ']') s2=2;
        if (st2[i] == '8' && st2[i+1] == '<') s2=3;
        if (s1 == s2) continue;
        if (win(s1,s2)) res++; else res--;
    }
    if (res > 0)
        cout<<"TEAM 1 WINS"<<endl;
    else
    if (res < 0)
        cout<<"TEAM 2 WINS"<<endl;
    else
        cout<<"TIE"<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

