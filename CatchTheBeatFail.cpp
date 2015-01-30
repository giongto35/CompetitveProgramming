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

const int maxn = 500000+10;
const int oo = 1000000000;
struct kdl
{
    int x;
    int y;
    int d1;
    int d2;
    int idx;
} a[maxn];
vector<int> b;
int F[maxn*2];
int BIT[maxn*2];
int BIT2[maxn*2];
int maxso1;
int maxso2;

void update1(int i,int gt)//change long long
{
    while (i<=maxso1)
    {
        BIT[i]= max(BIT[i],gt);
        i=i+(i & (-i));
    }
}


int get1(int i)//change long long
{
    int gt=-oo;//change long long
    while (i>=1)
    {
        gt=max(BIT[i],gt);
        i=i-(i & (-i));
    }
    return gt;
}

void update2(int i,int gt)//change long long
{
    i = maxso2 - i + 1;
    while (i<=maxso2)
    {
        BIT2[i]=max(BIT2[i],gt);
        i=i+(i & (-i));
    }
}


int get2(int i)//change long long
{
    int gt=-oo;//change long long
    i = maxso2 - i + 1;
    while (i<=maxso2)
    {
        gt=max(BIT2[i],gt);
        i=i-(i & (-i));
    }
    return gt;
}


bool mycmp(kdl a,kdl b)
{
    return a.y < b.y;
}

class CatchTheBeat {
  public:
  int maxCatched(int n, int x0, int y0, int sa, int sb, int c, int d, int mod1, int mod2, int offset) {
    int res = 0;
      a[1].x = x0;
    for (int i = 2; i <= n; i ++)
        a[i].x = (a[i-1].x * sa + sb) % mod1;
      a[1].y = y0;
    for (int i = 2; i <= n; i++)
        a[i].y = (a[i-1].y * c + d) % mod2;

    n++;
    a[n].x = offset;
    a[n].y = 0;

    b.clear();
    for (int i = 1; i <= n; i++)
    {
        a[i].x -= offset;
        a[i].d1 = a[i].x - a[i].y;
        b.push_back(a[i].d1);
        a[i].idx = i ;
    }
    sort(b.begin(),b.end());
    b.resize(distance(b.begin(),unique(b.begin(),b.end())));
    maxso1 = b.size();
    for (int i = 1; i <= n; i++)
    a[i].d1 = lower_bound(b.begin(),b.end(),a[i].d1) - b.begin() + 1;

    b.clear();
    for (int i = 1; i <= n; i++)
    {
        a[i].d2 = a[i].x + a[i].y;
        b.push_back(a[i].d2);
    }
    sort(b.begin(),b.end());
    b.resize(distance(b.begin(),unique(b.begin(),b.end())));
    maxso2 = b.size();
    for (int i = 1; i <= n; i++)
        a[i].d2 = lower_bound(b.begin(),b.end(),a[i].d2) - b.begin() + 1;

    sort(a+1,a+1+n,mycmp);
    a[0].y = -241;
    a[n+1].y = -231;
    int bd = 0;
    int kt = 0;
    for (int i = 1; i <= n; i++)
    {
        cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].d1<<' '<<a[i].d2<<endl;
    }
    return 0;
    for (int i = 1; i <= maxso1; i++) BIT[i] = -oo;
    for (int i = 1; i <= maxso2; i++) BIT2[i]= -oo;

    for (int i = 1; i <= n; i++)
    {
        if (a[i].y != a[i-1].y) bd = i;
        if (a[i].y != a[i+1].y)
        {
            kt = i;
            if (a[i].y == 0)
            {
                int cnt0 = 0;
                for (int j = bd; j <= kt; j++)
                    cnt0+=(a[j].x == 0);
                cnt0 --;
                for (int j = bd; j <= kt; j++)
                    if (a[j].x == 0) F[j] = cnt0; else F[j] = -oo;
            }
            else
            {
                for (int j = bd; j <= kt; j++)
                    F[j] = get2(a[j].d2) + 1;
                for (int j = kt; j >= bd; j--)
                    F[j] = get1(a[j].d1) + 1;
            }

            for (int j = bd; j <= kt; j++)
            {
                update1(a[j].d1,F[j]);
                update1(a[j].d2,F[j]);
                res = max(res,F[j]);
            }
        }

    }
    return res;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arg6 = 1; int Arg7 = 100; int Arg8 = 100; int Arg9 = 1; int Arg10 = 2; verify_case(0, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 1234; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1000000000; int Arg8 = 1000000000; int Arg9 = 1000; int Arg10 = 1; verify_case(1, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 999; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1000000000; int Arg8 = 1000000000; int Arg9 = 1000; int Arg10 = 0; verify_case(2, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 0; int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arg6 = 1; int Arg7 = 3; int Arg8 = 58585858; int Arg9 = 1; int Arg10 = 66; verify_case(3, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_4() { int Arg0 = 500000; int Arg1 = 123456; int Arg2 = 0; int Arg3 = 1; int Arg4 = 0; int Arg5 = 1; int Arg6 = 1; int Arg7 = 1000000000; int Arg8 = 1000000000; int Arg9 = 0; int Arg10 = 376544; verify_case(4, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_5() { int Arg0 = 500000; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1; int Arg8 = 1; int Arg9 = 0; int Arg10 = 500000; verify_case(5, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_6() { int Arg0 = 10; int Arg1 = 999999957; int Arg2 = 79; int Arg3 = 993948167; int Arg4 = 24597383; int Arg5 = 212151897; int Arg6 = 999940854; int Arg7 = 999999986; int Arg8 = 999940855; int Arg9 = 3404; int Arg10 = 3; verify_case(6, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }

// END CUT HERE

};

 // BEGIN CUT HERE
    int main()
        {
        CatchTheBeat ___test;
        ___test.run_test(0);
       int X ;
       scanf("%d",&X) ;
        }
    // END CUT HERE
