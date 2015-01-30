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

const int maxn = 1000+10;
int fr;
int re;
int q[maxn];
vector<int> b;
pair<int,int> a[maxn];
vector<int> c[maxn];

event make_event(int t, int r, int i)
{
    event x;
    x.t = t;
    x.r = r;
    x.i = i;
    return x;
}

class CatsOnTheLineDiv1 {
  public:
  int getNumber(vector <int> position, vector <int> count, int time) {
    int n = position.size();
    b.clear();
    for (int i = 0; i < n; i++)
    {
        b.push_back(position[i] - time);
        b.push_back(position[i] + time + 1);
    }
    sort(b.begin(),b.end());
    b.resize(distance(b.begin(),unique(b.begin(),b.end())));
    maxso = b.size();
    for (int i = 0; i < n; i++)
    {
        a[i].first = lower_bound(b.begin(),b.end(),position[i] - time) - b.begin() + 1;
        a[i].second = lower_bound(b.begin(),b.end(),position[i] + time + 1) - b.begin() + 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i].first; j < a[i].second; j++)
        {
            c[j].push_back(i);
        }
    }
    for (int j = 1; j <= maxso; j++)
    {

    }
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 0; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 1; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {4, 7, 47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 7, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 3; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {3, 0, 7, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 7, 4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 2; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {-5, 0, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {47, 85, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 1; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {-8, 12, -15, -20, 17, -5, 7, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20, 10, 7, 9, 2, 8, 11, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 5; verify_case(5, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

 // BEGIN CUT HERE
    int main()
        {
        CatsOnTheLineDiv1 ___test;
        ___test.run_test(-1);
       int X ;
       scanf("%d",&X) ;
        }
    // END CUT HERE

