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

struct pl {
	string nm;
	int sp, ht;
	int sT, tT, idx;

	inline friend bool operator < (pl a, pl b) {
		return make_pair(a.sp, a.ht) > make_pair(b.sp, b.ht);
	}
};


int nTest;
int n, m, p;
pl a[100];
deque<pl> playing1, playing2, sitout1, s2;


bool cmpp(pl a, pl b) {
	return make_pair(a.tT - a.sT, a.idx) > make_pair(b.tT - b.sT, b.idx);
}
bool cmps(pl a, pl b) {
	return make_pair(a.tT - a.sT, a.idx) < make_pair(b.tT - b.sT, b.idx);
}


int main() {
	freopen("basketball_game.txt", "r", stdin);
	freopen("basketball.out", "w", stdout);

	cin >> nTest;
	for(int test = 1; test <= nTest; test++) {

		cin >> n >> m >> p;
		for(int i = 1; i <= n; i++)
			cin >> a[i].nm >> a[i].sp >> a[i].ht;
		sort(a+1, a+1+n);
		for(int i = 1; i <= n; i++) {
			a[i].sT = 0;
			a[i].tT = 0;
			a[i].idx = i;
		}

		playing1.clear(); sitout1.clear(); playing2.clear(); s2.clear();
		for(int i = 1; i <= n; i++)
			if (i % 2)
				if (playing1.size() < p) playing1.push_back(a[i]);
				else sitout1.push_back(a[i]);
			else
				if (playing2.size() < p) playing2.push_back(a[i]);
				else s2.push_back(a[i]);

		for(int i = 1; i <= m; i++) {
			if (sitout1.size()) {
				sort(playing1.begin(), playing1.end(), cmpp);
				sort(sitout1.begin(), sitout1.end(), cmps);

				sitout1.push_back(playing1.front());
				playing1.pop_front();
				sitout1.back().sT = i;
				playing1.push_back(sitout1.front());
				sitout1.pop_front();
				playing1.back().sT = i;
			}

			if (s2.size()) {
				sort(playing2.begin(), playing2.end(), cmpp);
				sort(s2.begin(), s2.end(), cmps);

				s2.push_back(playing2.front());
				playing2.pop_front();
				s2.back().sT = i;
				playing2.push_back(s2.front());
				s2.pop_front(); playing2.back().sT = i;
			}
		}

		vector<string> ret; ret.clear();
		for(int i = 0; i < playing1.size(); i++) ret.push_back(playing1[i].nm);
		for(int i = 0; i < playing2.size(); i++) ret.push_back(playing2[i].nm);
		sort(ret.begin(), ret.end());

		cout << "Case #" << test << ": ";
		for(int i = 0; i < ret.size(); i++) cout << ret[i] << " ";
		cout << endl;

	}

	return 0;
}
