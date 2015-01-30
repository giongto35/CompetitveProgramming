#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
pair<char, int> input[100010];
vector<pair<int, int>> seg[100010];
bool continuous[100010];

int main() {

	scanf("%d%d", &n, &m);
	memset(continuous, 1, sizeof continuous);
	int C = 0;
	int minC = 0;
	for (int i = 1; i <= m; i++) {
		char c[3];
		int id;
		scanf("%s%d", c, &id);
		if (c[0] == '+') {
			seg[id].push_back(make_pair(i, 1e9));
		}
		else {
			if (seg[id].empty()) {
				seg[id].push_back(make_pair(-1e9, i));
				minC++;
			}
			else seg[id].back().second = i;
			
		}
		input[i] = make_pair(c[0], id);
	}
	C = minC;
	for (int i = 1; i <= m; i++) {
		if (input[i].first == '+') {
			C++;
		}
		else {
			if (C > 1) 
				continuous[input[i].second] = 0;
			C--;
		}
	}


	int mMin = 1e9, mMax = -1e9;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < seg[i].size(); j++) {
			mMin = min(mMin, seg[i][j].first);
			mMax = max(mMax, seg[i][j].second);
		}
	}

	vector<int> ret;
	for (int i = 1; i <= n; i++) {
		if (seg[i].empty()) {
			ret.push_back(i);
		}
		else {
			int nMin = 1e9, nMax = -1e9;
			for (int j = 0; j < seg[i].size(); j++) {
				nMin = min(nMin, seg[i][j].first);
				nMax = max(nMax, seg[i][j].second);
			}
			if (continuous[i] && nMin == mMin && nMax == mMax)
				ret.push_back(i);
		}
	}

	printf("%d\n", ret.size());
	for (int i = 0; i < ret.size(); i++)
		printf("%d ", ret[i]);

	return 0;
}