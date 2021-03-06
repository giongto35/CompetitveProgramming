    #include<iostream>
    #include<cstdio>
    #include<string.h>
    #include<math.h>
    #include<string>
    #include<set>
    #include<cstring>
    #include<map>
    #include<algorithm>
    #include<vector>
    #include<queue>
    using namespace std;
    #define mp make_pair
    #define eps 1e-10
    const double inf = 1e16;
    const double PI = acos(-1.0);
    struct Point
    {
        Point(const Point&p) { x = p.x , y = p.y; }
        Point (double xx=0,double yy=0) : x(xx) , y(yy) { }
        double x;
        double y;
    };


    typedef Point Vector;
    Vector operator+(Vector  v1,Vector  v2) { return Vector(v1.x+v2.x,v1.y+v2.y); }
    Vector operator-(Vector  v1,Vector  v2) { return Vector(v1.x-v2.x,v1.y-v2.y); }
    Vector operator*(Vector  v, double p) { return Vector(v.x*p,v.y*p); }
    Vector operator/(Vector  v,double p) { return Vector(v.x/p,v.y/p); }

    int dcmp(double x)
    {
        if (fabs(x) < eps) return 0;
        return x < 0 ? -1 : 1;
    }
    bool operator < (Point  a,Point  b) { return dcmp(a.x-b.x)<0 || dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)<0; }
    bool operator==(const Point & a,const Point & b)
    {
        return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0;
    }

    inline double toRad(double x) { return x * PI/180; }
    inline double toDegreed(double rad) { return rad*180/PI; }
    double Dot(Vector  A,Vector  B) { return A.x*B.x+A.y*B.y; }
    double Length(Vector  A) { return sqrt(Dot(A,A)); }
    double Angle(Vector A,Vector B)
    {
        double cosine = Dot(A,B)/Length(A)/Length(B);
        if (dcmp(cosine-1.0)==0) return 0;
        return acos(cosine);
    }
    double Cross(Vector A,Vector B) { return A.x*B.y-A.y*B.x; }
    double Area2(Point a,Point b,Point c) {  return Cross(b-a,c-a); }
    double PolyArea(Point *poly, int n)
    {
        double ret = 0;
        for (int i = 1 ; i < n-1 ; ++i)
            ret += Cross(poly[i]-poly[0],poly[i+1]-poly[0]);
        return ret/2;
    }

    Vector Rotate(Vector A,double rad)
    {
        return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
    }

    Vector Normal(Vector A) { double L = Length(A); return Vector(-A.y/L,A.x/L); }

    Point GetLineIntersection(Point P,Vector v,Point Q,Vector w)
    {
        Vector u = P-Q;
        double t = Cross(w,u) / Cross(v,w);
        return P+v*t;
    }

    double DistanceToLine(Point P,Point A,Point B)
    {
        Vector v1 = B-A , v2 = P-A;
        return fabs(Cross(v1,v2))/Length(v1);
    }
    double DistanceToSegment(Point P,Point A,Point B)
    {
        if (A==B) return Length(P-A);
        Vector v1 = B-A , v2 = P-A , v3 = P-B;
        if (dcmp(Dot(v1,v2)) < 0) return Length(v2);
        else if (dcmp(Dot(v1,v3)) > 0) return Length(v3);
        else return fabs(Cross(v1,v2))/Length(v1);
    }

    Point GetLineProjection(Point P,Point A,Point B)
    {
        Vector v = B-A;
        return A+v*(Dot(v,P-A)/Dot(v,v));
    }

    bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2)
    {
        double c1 = Cross(a2-a1,b1-a1) , c2 = Cross(a2-a1,b2-a1) ,
                 c3 = Cross(b2-b1,a1-b1) , c4 = Cross(b2-b1,a2-b1);
        return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4)<0;
    }
    bool OnSegment(Point p,Point a,Point b)
    {
        return dcmp(Cross(a-p,b-p))==0 && dcmp(Dot(a-p,b-p)) < 0;
    }

    bool OnLine(Point p,Point a,Point b)
    {
        if (p==a || p==b) return true;
        return dcmp(Cross(a-p,b-p))==0;
    }

    bool SegmentIntersection(Point a1,Point a2,Point b1,Point b2)
    {
        if (SegmentProperIntersection(a1,a2,b1,b2)) return true;
        if (OnSegment(a1,b1,b2) || OnSegment(a2,b1,b2)) return true;
        if (OnSegment(b1,a1,a2) || OnSegment(b2,a1,a2)) return true;
        if (a1==b1 || a1==b2 || a2==b1 || a2==b2) return true;
        return false;
    }

    int isPointInPolygon(Point a,Point *p,int n)
    {
        int wn = 0;
        for (int i = 0 ; i < n ; ++i) {
            if (a==p[i]) return -2;
            if (OnSegment(a,p[i],p[(i+1)%n])) return -1;
            int k = dcmp(Cross(p[(i+1)%n]-p[i],a-p[i]));
            int d1 = dcmp(p[i].y-a.y);
            int d2 = dcmp(p[(i+1)%n].y-a.y);
            if (k > 0 && d1<=0 && d2>0) ++wn;
            if (k<0 && d2<=0 && d1>0) --wn;
        }
        if (wn!=0) return 1;
        return 0;
    }

    struct Line
    {
        Point P;
        Vector v;
        double ang;
        Line() { }
        Line(Point P,Vector v)
        {
            this->P = P ; this->v = v;
            ang = atan2(v.y,v.x);
        }
        bool operator < (const Line& L) const { return ang < L.ang; }
        Point point(double t) { return v*t+P; }
    };

    bool OnLeft(Line L , Point p) { return Cross(L.v,p-L.P) > 0; }

    Point GetIntersection(Line a,Line b)
    {
        Vector u = a.P-b.P;
        double t = Cross(b.v,u) / Cross(a.v,b.v);
        return a.P+a.v*t;
    }

    struct Circle
    {
        Circle() { }
        Point c;
        double r;
        Circle(Point c, double r) : c(c) , r(r) { }
        Point point (double a) { return Point(c.x+cos(a)*r,c.y+sin(a)*r); }
    };

    int getLineCircleIntersection(Line L,Circle C,double &t1,double &t2,vector<Point>& sol)
    {
        double a = L.v.x , b = L.P.x-C.c.x , c= L.v.y, d = L.P.y-C.c.y;
        double e = a*a+c*c , f = 2*(a*b+c*d) , g = b*b+d*d-C.r*C.r;
        double delta = f*f-4*e*g;
        if (dcmp(delta) < 0) return 0;
        if (dcmp(delta)==0) {
            t1 = t2 = -f/(2*e);
            sol.push_back(L.point(t1));
            return 1;
        }
        t1 = (-f-sqrt(delta)) / (2*e); sol.push_back(L.point(t1));
        t2 = (-f+sqrt(delta)) / (2*e); sol.push_back(L.point(t2));
        return 2;
    }

    double angle(Vector v) { return atan2(v.y,v.x); }

    int getCircleCircleIntersection(Circle C1,Circle C2,vector<Point>& sol)
    {
        double d = Length(C1.c-C2.c);
        if (dcmp(d)==0) {
            if (dcmp(C1.r-C2.r)==0) return -1;
            return 0;
        }
        if (dcmp(C1.r+C2.r-d) < 0) return 0;
        if (dcmp(fabs(C1.r-C2.r)-d) > 0) return 0;

        double a = angle(C2.c-C1.c);
        double da = acos((C1.r*C1.r+d*d-C2.r*C2.r)/(2*C1.r*d));
        Point p1 = C1.point(a-da) , p2 = C1.point(a+da);
        sol.push_back(p1);
        if (p1==p2) return 1;
        sol.push_back(p2);
        return 2;
    }

    int getTangents(Point p,Circle C,Vector* v)
    {
        Vector u= C.c-p;
        double dist = Length(u);
        if (dist < C.r) return 0;
        else if (dcmp(dist-C.r)==0) {
            v[0] = Rotate(u,PI/2);
            return 1;
        } else {
            double ang = asin(C.r/dist);
            v[0] = Rotate(u,-ang);
            v[1] = Rotate(u,+ang);
            return 2;
        }
    }

    int getTangents(Circle A,Circle B,Point* a, Point* b)
    {
        int cnt = 0;
        if (A.r < B.r) { swap(A,B); swap(a,b); }
        double d2 = Dot(A.c-B.c,A.c-B.c);
        double rdiff = A.r-B.r;
        double rsum = A.r+B.r;
        if (dcmp(d2-rdiff*rdiff) < 0) return 0;

        double base = atan2(B.c.y-A.c.y,B.c.x-A.c.x);
        if (d2==0 && dcmp(A.r-B.r)==0) return -1;
        if (dcmp(d2-rdiff*rdiff)==0) {
            a[cnt] = A.point(base);
            b[cnt] = B.point(base);
            ++cnt;
            return 1;
        }
        double ang = acos((A.r-B.r)/sqrt(d2));
        a[cnt] = A.point(base+ang); b[cnt] = B.point(base+ang); ++cnt;
        a[cnt] = A.point(base-ang); b[cnt] = B.point(base-ang); ++cnt;
        if (dcmp(d2-rsum*rsum)==0) {
            a[cnt] = A.point(base);
            b[cnt] = B.point(PI+base);
            ++cnt;
        } else if (dcmp(d2-rsum*rsum)>0) {
            double ang = acos((A.r+B.r)/sqrt(d2));
            a[cnt] = A.point(base+ang); b[cnt] = B.point(PI+base+ang); ++cnt;
            a[cnt] = A.point(base-ang); b[cnt] = B.point(PI+base-ang); ++cnt;
        }
        return cnt;
    }

    int PointCircleRelation(Point p,Circle c)
    {
        return dcmp(Dot(p-c.c,p-c.c)-c.r*c.r);
    }

    double torad(double deg) { return deg/180*PI; }

    void get_coord(double R,double lat,double lng,double& x,double& y,double& z)
    {
        lat = torad(lat);
        lng = torad(lng);
        x = R*cos(lat)*cos(lng);
        y = R*cos(lat)*sin(lng);
        z = R*sin(lat);
    }

    int ConvexHull(Point* p , int n, Point* ch)
    {
        sort(p,p+n);
        int m = 0;
        for (int i = 0 ; i < n ; ++i) {
            while (m>1 && dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) --m;
            ch[m++] = p[i];
        }
        int k = m;
        for (int i = n-2 ; i >= 0 ; --i) {
            while (m>k && dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) --m;
            ch[m++] = p[i];
        }
        if (n > 1) --m;
        return m;
    }

    int HalfplaneIntersection(Line* L,int n,Point* poly)
    {
        sort(L,L+n);

        int first , last;
        Point *p = new Point[n];
        Line *q = new Line[n];
        q[first=last=0] = L[0];
        for (int i = 1 ; i < n ; ++i) {
            while (first < last && !OnLeft(L[i],p[last-1])) --last;
            while (first < last && !OnLeft(L[i],p[first])) ++first;
            q[++last] = L[i];
            if (dcmp(Cross(q[last].v,q[last-1].v))==0 ) {
                --last;
                if (OnLeft(q[last],L[i].P)) q[last] = L[i];
            }
            if (first < last) p[last-1] = GetIntersection(q[last-1],q[last]);
        }
        while (first < last && !OnLeft(q[first],p[last-1])) --last;

        if (last - first <=1 ) { delete [] p; delete [] q; return 0; }
        p[last] = GetIntersection(q[last],q[first]);

        int m = 0;
        for (int i = first ; i <= last ; ++i) poly[m++] = p[i];
        delete [] p; delete[] q;
        return m ;
    }

    bool OnLine(Point p,Line L)
    {
        Vector v = p-L.P;
        return dcmp(Cross(v,L.v))==0;
    }
    double dist(Point p1, Point p2) { // Euclidean distance
  return hypot(p1.x - p2.x, p1.y - p2.y); } // return double

// returns the area, which is half the determinant
double area(const vector<Point> &P) {
  double result = 0.0, x1, y1, x2, y2;
  for (int i = 0; i < (int)P.size()-1; i++) {
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;
    result += (x1 * y2 - x2 * y1);
  }
  return fabs(result) / 2.0; }

    pair<double,double> RotateCalipers(Point* hull,int n)
    {
        hull[n] = hull[0];
        Line L1, L2, L3, L4;
        int q=0, w=0, e=0, r=0;
        for (int i = 0 ; i < n ; ++i) {
            if (dcmp(hull[i].y-hull[q].y)<0) q = i;
            if (dcmp(hull[i].x-hull[w].x)<0) w = i;
            if (dcmp(hull[i].y-hull[e].y)>0) e = i;
            if (dcmp(hull[i].x-hull[r].x)>0) r = i;
        }
        L1 = Line(hull[q],Vector(1,0));
        L2 = Line(hull[w],Vector(0,-1));
        L3 = Line(hull[e],Vector(-1,0));
        L4 = Line(hull[r],Vector(0,1));
        double sum = 0;
        double ansA = inf , ansC = inf;
     double res = 0;
        while (dcmp(sum-PI/2)<0) {
            double ang = Angle(hull[q+1]-hull[q],L1.v);
            ang = min(ang,Angle(hull[w+1]-hull[w],L2.v));
            ang = min(ang,Angle(hull[e+1]-hull[e],L3.v));
            ang = min(ang,Angle(hull[r+1]-hull[r],L4.v));
            sum += ang;
            L1.v = Rotate(L1.v,ang);
            L2.v = Rotate(L2.v,ang);
            L3.v = Rotate(L3.v,ang);
            L4.v = Rotate(L4.v,ang);
            if (dcmp(ang-Angle(hull[q+1]-hull[q],L1.v))==0) { L1.P = hull[q+1]; q = (q+1)%n; }
            if (dcmp(ang-Angle(hull[w+1]-hull[w],L2.v))==0) { L2.P = hull[w+1]; w = (w+1)%n; }
            if (dcmp(ang-Angle(hull[e+1]-hull[e],L3.v))==0) { L3.P = hull[e+1]; e = (e+1)%n; }
            if (dcmp(ang-Angle(hull[r+1]-hull[r],L4.v))==0) { L4.P = hull[r+1]; r = (r+1)%n; }
            double A = DistanceToLine(L1.P,L3.P,L3.P+L3.v*Length(L1.P-L3.P));
            double B = DistanceToLine(L2.P,L4.P,L4.P+L4.v*Length(L2.P-L4.P));
            ansA = min(ansA,A*B);
            ansC = min(ansC,A+B);
         Point L[8];
         L[0] = L1.P;
         L[1] = L2.P;
         L[2] = L3.P;
         L[3] = L4.P;
         for (int i = 0; i < 4; i++)
         for (int j = i + 1; j < 4; j++)
         res = max(res,dist(L[i],L[j]));

        }
        ansC *= 2;
        return mp(ansA,res);
    }
    //-----------------------------------------------------------------------
    int n , r , m;
    double res;



   // returns the perimeter, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double perimeter(const vector<Point> &P) {
  double result = 0.0;
  for (int i = 0; i < (int)P.size()-1; i++) // remember that P[0] = P[n-1]
    result += dist(P[i], P[i+1]);
  return result; }

const int maxn = 50000+10;
Point a[maxn],H[maxn],p[maxn];
int TC;
    int main()
    {
//      freopen("C.inp","r",stdin);
        scanf("%d",&TC);
        while(TC>0)
        {
            scanf("%d",&n);
            for (int i = 0; i < n; i++)
                scanf("%lf%lf",&a[i].x,&a[i].y);
            int np = ConvexHull(a,n,p);
            pair<double,double> res = RotateCalipers(p,np);
            printf("%.4lf\n",res.second);
            TC--;
        }
    }
