
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <cstring>
#include <set>
using namespace std;using namespace std;using namespace std;using namespace std;using namespace std;using namespace std;using namespace std;using namespace std;using namespace std;using namespace std;using namespace std;using namespace std;using namespace std;using namespace std;
#define pb push_back
#define inf 1000000000
#define L(s) (int)((s).size())
#define ll long long
#define all(c) (c).begin(), (c).end()
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define x first
#define y second
int f[1001][1 << 2][1 << 2][2];
int solve(int len, int st, int fn, int last) {

  if (f[len][st][fn][last] != -1) return f[len][st][fn][last];

  if (st == 3 || fn == 3) return f[len][st][fn][last] = -2;


//  if (len == 2) {
//
//  }
  if (len == 2 && st && fn && st != fn) return f[len][st][fn][last] = -2;

  set<int> mex;
  for(int bit = 1; bit <= 2; ++bit) {
    if (!(st & bit)) {
      mex.insert(solve(len, st | bit, fn, last));
    }
    if (last) {
      if (!(fn & bit)) {
        mex.insert(solve(len, st, fn  | bit, last));
      }
    }
    for(int put = 1; put < len - 1; ++put) {
      int v1 = solve(put + 1, st, bit, 0);
      int v2 = solve(len - put, bit, fn, last);
      if (v1 == -2 || v2 == -2) continue;
      mex.insert(v1 ^ v2);
    }
  }
  for(int num = 0;;++num) {
    if (!mex.count(num)) {
  //    cerr << len << " " << st << " " << fn << " " << last << " -> " << num << endl;
      return f[len][st][fn][last] = num;
    }
  }
}
class PathGame
  {
    public:
       string judge( vector <string> board )
    {
         memset(f, -1, sizeof(f));

         vector<int> rows(0);
         for(int i = 0; i < L(board[0]); ++i) {
           if (i == 0 || i == L(board[0]) - 1 || board[0][i] == '#' || board[1][i] == '#') {
             rows.pb(i);
           }
         }

         if (L(board[0]) == 1) {
           if (board[0][0] == '.' && board[1][0] == '.'){
             return "Snuke";
           }
           return "Sothe";
         }

     //    if (L(board[0]) != 5 || board[1][2] != '#') return "";

         int ans = 0;
         for(int i = 0; i < L(rows) - 1; ++i) {
           int st = 0;
           if (board[0][rows[i]] == '#') st |= 1;
           if (board[1][rows[i]] == '#') st |= 2;

           int fn = 0;
        if (board[0][rows[i + 1]] == '#') fn |= 1;
        if (board[1][rows[i + 1]] == '#') fn |= 2;

        int val = solve(rows[i + 1] - rows[i] + 1, st, fn, rows[i + 1] == L(board[0]) - 1);

        cerr << rows[i + 1] - rows[i] + 1 << " " << st << " " << fn << " " << (rows[i + 1] == L(board[0]) - 1) <<  " -> " << val << endl;

        ans ^= val;
         }
         //exit(0);
         if (ans == 0) return "Sothe"; else return "Snuke";
    }// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".."
,".#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Snuke"; verify_case(0, Arg1, judge(Arg0)); }
	void test_case_1() { string Arr0[] = {"#"
,"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sothe"; verify_case(1, Arg1, judge(Arg0)); }
	void test_case_2() { string Arr0[] = {"....."
,"..#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sothe"; verify_case(2, Arg1, judge(Arg0)); }
	void test_case_3() { string Arr0[] = {".#..."
,"....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Snuke"; verify_case(3, Arg1, judge(Arg0)); }
	void test_case_4() { string Arr0[] = {".....#..#........##......."
,"..........#..........#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Snuke"; verify_case(4, Arg1, judge(Arg0)); }

// END CUT HERE


  };


 // BEGIN CUT HERE
    int main()
        {
        PathGame ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE


// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
