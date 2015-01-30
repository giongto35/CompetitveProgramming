#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

#define EPS 1e-9
#define PI acos(-1.0)

struct point {
	double x, y; // we use double for most examples in this source code
	point() {
	}
	;
	point(double _x, double _y) {
		x = _x, y = _y;
	}
	bool operator <(point p) const { // declare as const otherwise won't compile
		if (fabs(x - p.x) > EPS)
			return x < p.x;
		return y < p.y;
	}
	bool operator ==(point p) const {
		return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
	}
};

struct vec {
	double x, y; // similar to point
	vec(double _x, double _y) {
		x = _x, y = _y;
	}
};

vec toVector(point p1, point p2) { // convert 2 points to vector
	return vec(p2.x - p1.x, p2.y - p1.y);
}

double dist(point p1, point p2) { // get Euclidean distance of two points
	return hypot(p1.x - p2.x, p1.y - p2.y);
} // as shown earlier

double dot(vec a, vec b) {
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
	return v.x * v.x + v.y * v.y;
}

double angle(point a, point o, point b) { // returns angle aob in rad
	vec oa = toVector(o, a), ob = toVector(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) {
	return a.x * b.y - a.y * b.x;
}

bool ccw(point p, point q, point r) {
	return cross(toVector(p, q), toVector(p, r)) > 0;
}

// returns true if point p is in either convex/concave polygon P
bool inPolygon(point p, point* P, int n) {
	if (n == 0)
		return false;
	double sum = 0; // assume first vertex = last vertex
	for (int i = 0; i < n - 1; i++) {
		if (ccw(p, P[i], P[i + 1]))
			sum += angle(P[i], p, P[i + 1]);   // left turn/ccw
		else
			sum -= angle(P[i], p, P[i + 1]);
	} // right turn/cw
	return fabs(fabs(sum) - 2 * PI) < EPS;
}

double cross(point o, point a, point b) {
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

int CHAMC(point* P, int n, point* H) {
	sort(P, P + n);
	int nh = 0;
	for (int i = 0; i < n; i++) {
		while (nh >= 2 && cross(H[nh - 2], H[nh - 1], P[i]) <= 0)
			nh--;
		H[nh++] = P[i];
	}
	int l = nh + 1;
	for (int i = n - 1; i >= 0; i--) {
		while (nh >= l && cross(H[nh - 2], H[nh - 1], P[i]) <= 0)
			nh--;
		H[nh++] = P[i];
	}
	return nh;
}

bool onLineSegment(point &v, point &a, point &b) {
	return fabs(cross(a, v, b) - 0) < EPS && min(a, b) < v && v < max(a, b);
}

bool checkInside(point &v, point* P, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (v == P[i] || onLineSegment(v, P[i], P[i + 1]))
			return true;
	}
	return inPolygon(v, P, n);
}

bool segmentIntersect(point &as, point &at, point &bs, point &bt) {
	if (cross(as, at, bs) * cross(as, at, bt) < 0
			&& cross(at, as, bs) * cross(at, as, bt) < 0
			&& cross(bs, bt, as) * cross(bs, bt, at) < 0
			&& cross(bt, bs, as) * cross(bt, bs, at) < 0)
		return true;
	return false;
}

point p[100000+10];
point a[100000+10];

int main() {
    //freopen("input.txt","r",stdin);
	int n;
	while (scanf("%d",&n) == 1) {
        for (int i = 0; i <= n-1; i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        a[n++] = a[0];
        int np = CHAMC(a,n,p);
        int m;
        scanf("%d",&m);
        for (int i = 0; i <= m-1; i++)
        {
            point u;
            scanf("%lf%lf",&u.x,&u.y);
            if (checkInside(u,p,np))
                printf("inside\n");
            else
                printf("outside\n");
        }
	}
}
