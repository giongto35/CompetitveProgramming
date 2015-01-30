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
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iomanip>

using namespace std;

 #define FOR(i,a,b) for (int i = (a),_b=(b);i<=_b;i++)
 #define DOW(i,b,a) for (int i = (b),_a=(a);i>=_a;i--)
 #define oo 1000111000
 const double eps = 0.0000001;

using namespace std;
struct circle
{
	int x,y;
	int r;
} a[100];
int TC;
int n;

double dist(double x1,double y1,double x2,double y2)
{
	return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

bool comp(double x,double y,double r,double x1,double x2,double y1,double y2)
{
	if (abs((x2-x1)*(y2-y1)-r*r)<=eps) return true;
	for(double i=x1;i<=x2;i+=0.001)
	{
		if (dist(x,y,i,y1)<=r*r) return true;
		if (dist(x,y,i,y2)<=r*r) return true;
	}
	for(double i=y1;i<=y2;i+=0.001)
	{
		if (dist(x,y,x1,i)<=r*r) return true;
		if (dist(x,y,x2,i)<=r*r) return true;
	}
	return false;
}


bool check(double x1,double y1,double x2,double y2,double x,double y,int r)
{
// clamp(value, min, max) - limits value to the range min..max

// Find the closest point to the circle within the rectangle
double cX = min(max(x,x1),x2);
double cY = min(max(y,y1),y2);

// Calculate the distance between the circle's center and this closest point
//double distanceX = circle.X - closestX;
//double distanceY = circle.Y - closestY;

// If the distance is less than the circle's radius, an intersection occurs
//double distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
return dist(x,y,cX,cY) <= r*r;
}
/*
{
		//if (x2<=1&&y2<=1) cout<<"ABC"<<' '<<x-r<<" "<<x+r<<' '<<y-r<<' '<<y+r<<endl;
	if (max(x-r,x1)<=min(x+r,x2)&&max(y-r,y1)<=min(y+r,y2))
	return comp(x,y,r,max(x-r,x1),min(x+r,x2),max(y-r,y1),min(y+r,y2));
	//return true;
	return false;
}*/

double calc(double x1,double y1,double  x2,double y2)
{
    //cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
	int cnt=0;
	FOR(i,1,n)
	{
		int dem=0;
		if (dist(a[i].x,a[i].y,x1,y1)<=a[i].r*a[i].r) dem++;
		if (dist(a[i].x,a[i].y,x2,y2)<=a[i].r*a[i].r) dem++;
		if (dist(a[i].x,a[i].y,x1,y2)<=a[i].r*a[i].r) dem++;
		if (dist(a[i].x,a[i].y,x2,y1)<=a[i].r*a[i].r) dem++;
		if (dem==4) return (x2-x1)*(y2-y1);
		if (dem==0)
		{
			if (!check(x1,y1,x2,y2,a[i].x,a[i].y,a[i].r))cnt++;
		}
	}
	if (cnt==n) return 0;
	if ((x2-x1)*(y2-y1)<=eps) return ((x2-x1)*(y2-y1)+0.0)/2;

	double midx = (x1+x2+0.0)/2;
	double midy = (y1+y2+0.0)/2;
	return calc(x1,y1,midx,midy)+calc(midx,y1,x2,midy)+calc(x1,midy,midx,y2)+calc(midx,midy,x2,y2);
}

int main()
{
	//freopen("Scircle.inp","r",stdin);
	//freopen("H.out","w",stdout);
		scanf("%d",&n);
		FOR(i,1,n)
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].r);
        double res=calc(0,0,10000 ,10000);
		cout<<fixed<<setprecision(5)<<((long long)(res*100000)+0.0)/100000<<endl;
	fclose(stdin);
	fclose(stdout);
}
