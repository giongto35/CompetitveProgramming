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

vector<int> v;
class TheLargestString {
  public:
  string find(string s, string t) {
    string maxs = "";
    string maxs2= "";
    int i = 0;
    v.clear();
    while (i < s.length())
    {
        int vt = -1;
        for (int j = i; j < s.length(); j++)
            if (vt == -1 || make_pair(s[vt],t[vt]) < make_pair(s[j],t[j])  )
            {
                vt = j;
            }
        i = vt + 1;
        maxs += s[vt];
        maxs2 += t[vt];
        cout<<s[vt]<<' '<<t[vt]<<' '<<vt<<endl;
        if (s[vt] < t[vt]) break;
        v.push_back(vt);
    }
    return maxs+maxs2;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ab"; string Arg1 = "zy"; string Arg2 = "by"; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abacaba"; string Arg1 = "zzzaaaa"; string Arg2 = "cbaaaa"; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "x"; string Arg1 = "x"; string Arg2 = "xx"; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abbabbabbababaaaabbababab"; string Arg1 = "bababbaabbbababbbbababaab"; string Arg2 = "bbbbbbbbbbbbbbbbbbaaab"; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

 // BEGIN CUT HERE
    int main()
        {
        TheLargestString ___test;
        ___test.run_test(-1);
       int X ;
       scanf("%d",&X) ;
        }
    // END CUT HERE
