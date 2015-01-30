#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> point;

inline int cmp1(const point a, const point b) { return make_pair(a.second, a.first) < make_pair(b.second, b.first); }
inline int cmp2(const point a, const point b) { return make_pair(a.second, a.first) > make_pair(b.second, b.first); }

inline int Cross(point p1, point p2, point p3) {
    int a1 = p2.first-p1.first;
    int b1 = p2.second-p1.second;
    int a2 = p3.first-p2.first;
    int b2 = p3.second-p2.second;
    return a1*b2 - a2*b1;
}

inline void getCover(vector<point> &a) {
    vector<point> ret; ret.clear();
    sort(a.begin(), a.end(), cmp1);
    ret.push_back(a[0]); ret.push_back(a[1]);
    for(int i = 2; i < a.size(); i++) {
        while (ret.size() > 1 && Cross(ret[ret.size()-2], ret[ret.size()-1], a[i]) <= 0) ret.pop_back();
        ret.push_back(a[i]);
    }
    for(int i = a.size()-2; i >= 0; i--) {
        while (ret.size() > 1 && Cross(ret[ret.size()-2], ret[ret.size()-1], a[i]) <= 0) ret.pop_back();
        ret.push_back(a[i]);
    }
    a = ret;
}

inline double abs(double n) { return n > 0 ? n : -n; }

inline double Size(vector<point> s) {
    double ret = 0;
    s.push_back(s[0]);
    for(int i = 1; i < s.size(); i++)
        ret += (s[i].first-s[i-1].first) * (s[i].second+s[i-1].second);
    return abs(ret)/2;
}
double Size(point p1, point p2, point p3) {
    vector<point> s; s.clear();
    s.push_back(p1); s.push_back(p2); s.push_back(p3); 
    return Size(s);
}

vector<point> a;

int main() {
    int n;
    while (cin >> n) {
        if (n == -1) break;
        a.clear();
        for(int i = 0; i < n; i++) {
            point aa; scanf("%d%d", &aa.first, &aa.second);
            a.push_back(aa);
        }
        getCover(a);
        if (a.size() < 3) {
            printf("%.2f\n", 0);
            continue;
        }
        double ret = Size(a[0], a[1], a[2]);
        for(int i1 = 0, i2 = 1, i3 = 2; i1 < a.size(); i1++) {
            bool change;
            do {
                change = 0;
                for(; Size(a[i1], a[i2], a[i3]) < Size(a[i1], a[i2], a[(i3+1)%a.size()]); i3 = (i3+1)%a.size()) change = 1;
                for(; Size(a[i1], a[i2], a[i3]) < Size(a[i1], a[(i2+1)%a.size()], a[i3]); i2 = (i2+1)%a.size()) change = 1;
            }
            while (change);
            ret = max(ret, Size(a[i1], a[i2], a[i3]));
        }
        printf("%.2f\n", ret);
    }
    return 0;
}

