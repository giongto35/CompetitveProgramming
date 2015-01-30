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

vector<pair<int, int > > p;

const int maxn = 1000+10;
int s[maxn][maxn];
vector<int> x2;
vector<int> y2;
class MinimumSquare {
  public:
  long long minArea(vector <int> x, vector <int> y, int Need) {
      int n = x.size();
      //p.clear();
      l = 1;
      r = 1000000000;
      while (l <= r){
          K = (l + r) / 2;

          x2.clear();
          y2.clear();
          for (int i = 0 ; i < n; i++)
          {
            x2.push_back(x[i]-1);
            x2.push_back(x[i]);
            x2.push_back(x[i]+1);
            x2.push_back(x[i]-1+K);
            x2.push_back(x[i]+K);
            x2.push_back(x[i]+1+K);
            y2.push_back(y[i]-1);
            y2.push_back(y[i]);
            y2.push_back(y[i]+1);
            y2.push_back(y[i]-1+K);
            y2.push_back(y[i]+K);
            y2.push_back(y[i]+1+K);
          }
          //sort(p.begin(),p.end());
          sort(x2.begin(),x2.end());
          sort(y2.begin(),y2.end());
          unique(x2.begin(),x2.end());
          unique(y2.begin(),y2.end());
          int ny = y2.size();
          int nx = x2.size();
          for (int i = 0; i < n; i++)
          {
              int vtx = 0;
              int vty = 0;
              for (int j = 0; j < ny; j++)
                if (x2[j] == x[i]) vtx = j;
              for (int j = 0; j < nx; j++)
                if (y2[j] == y[i]) vty = j;
              s[vty+1][vtx+1]++;
          }
          long long res = 1000000000000100000ll;
          for (int i = 1; i <= ny; i++)
          for (int j = 1; j <= nx; j++)
          {
              int i2;
              int j2;
              for (int k = 0; k < ny; k++)
                if (y2[k] == y[i] + K) i2 = k;
              for (int k = 0; k < nx; k++)
                if (x2[k] == x[i] + K) j2 = k;

              bool ok = true;
              for (int k = 0; k < n; k++)
              {
                  if ( y[k] == y2[i-1] || y[k] == y2[i2-1] || x[k] = x2[j-1] || y[k] == x2[j2-1])
                  {
                      ok =false;
                      break;
                  }
              }
              if (ok)
          }
      }
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; long long Arg3 = 81LL; verify_case(0, Arg3, minArea(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {-4, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3 , -1, -2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; long long Arg3 = 16LL; verify_case(1, Arg3, minArea(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, 0, 1, 1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; long long Arg3 = 9LL; verify_case(2, Arg3, minArea(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000, 0, -1000000000, 1000000000, 0, -1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; long long Arg3 = 4000000008000000004LL; verify_case(3, Arg3, minArea(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; long long Arg3 = 1695545329LL; verify_case(4, Arg3, minArea(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

 // BEGIN CUT HERE
    int main()
        {
        MinimumSquare ___test;
        ___test.run_test(-1);
       int X ;
       scanf("%d",&X) ;
        }
    // END CUT HERE
