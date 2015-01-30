#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i ++)
#define DOW(i, a, b) for(int i = a; i >= b; i --)
#define RESET(c, val) memset(c, val, sizeof(c))
#define FOREACH(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it ++)
#define oo 1000000000
#define base
#define eps 0.00000000001

long long l, v1, v2, t;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
long long cal(long long l, long long v1, long long v2, long long t) {
	long long a = v1 / gcd(v1, v2*2);
	long long b = v2 * 2 / gcd(v1, v2*2);
	long long k1 = t * v1 / (l * 2);
	long long k2 = t * v2 / l;

	if (b % 2 == 0) return 0;

	long long r1, r2;
	if (a > k1) r1 = 0;
		else r1 = (k1 - a) / (a * 2) + 1;
	if (b > k2) r2 = 0;
		else r2 = (k2 - b) / (b * 2) + 1;

	return min(r1, r2);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> l >> v1 >> v2 >> t;
	long long res = max(v1 * t / l, v2 * t / l);

	long long a1, b1, a2, b2;
	if ((v1 * t / l) % 2 == 1) {
		a1 = l - (v1 * t) % l;
		b1 = l;
	} else {
		a1 = 0;
		b1 = (v1 * t) % l;
	}

	if ((v2 * t / l) % 2 == 1) {
		a2 = 0;
		b2 = (v2 * t) % l;
	} else {
		a2 = l - (v2 * t) % l;
		b2 = l;
	}

	long double t1, t2;
	t1 = 1.0*(((v1 * t))) * v2;
	t2 = 1.0*(((v2 * t))) * v1;

	//cout << t1 << " " << t2 << endl;
	//cout << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
	if (a1 == a2 && a1 == 0) {
		if (b1 < b2) {
			res += t1<=t2;
		} else {
			res += t2<=t1;
		}
	} else if (b1 == b2 && b1 == l) {
		if (a1 < a2) {
			res += t2 <= t1;
		} else {
			res += t1 <= t2;
		}
	} else if (a1 == 0 && b2 == l && b1 >= a2) {
		res ++;
	} else if (a2 == 0 && b1 == l && b2 >= a1) {
		res ++;
	}

	cout << res - cal(l, v1, v2, t) - cal(l, v2, v1, t);
	return 0;
}
