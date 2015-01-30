#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#define fi "K.INP"
#define fo "K.OUT"
#define nmax 1000000+5
using namespace std;
typedef double dd;
typedef pair<dd,dd> DD;
typedef pair<int,int> II;
const int delta=30;
const int alpha=200;
const dd INF=dd(1e16);
//VARIABLES
int n,f[nmax];
II a[nmax];
DD b[nmax];
dd res;
//FUNCTION PROTOTYPES
void Init();
void Process();

//MAIN
int main()
{
	//freopen(fi,"r",stdin);
	//freopen(fo,"w",stdout);
	Init();
	Process();
	return 0;
}

//FUNCTIONS AND PROCEDURES
void Init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d%d",&a[i].first,&a[i].second);
}
dd Dist(II &p, II &q)
{
	return sqrt(dd(p.first-q.first)*dd(p.first-q.first)+dd(p.second-q.second)*dd(p.second-q.second));
}
bool cmp(const int &p, const int &q)
{
	return b[p]<b[q];
}
void Cal(int rotate)
{
	dd theta=(dd(rotate)/180.0)*M_PI;
	dd Sin=sin(theta),Cos=cos(theta),tmp;
	for (int i=1;i<=n;++i) b[i]=DD(1.0*a[i].first*Cos-1.0*a[i].second*Sin,1.0*a[i].first*Sin+1.0*a[i].second*Cos);
	//cerr << rotate << endl;
	//cout << rotate << endl;
	//for (int i=1;i<=n;++i) cout << b[i].first << " " << b[i].second << endl;
	sort(f+1,f+n+1,cmp);
	//cout<<res<<endl;
    for (int x=1;x<=n;x++)
	{
	    int i=((long long)rand()*rand())%n+1;
	    int j=((long long)rand()*rand())%n+1;
	    int k=((long long)rand()*rand())%n+1;
	    //cout<<Dist(a[f[i]],a[f[j]])+Dist(a[f[j]],a[f[k]])+Dist(a[f[k]],a[f[i]])<<endl;
	    if (i!=j&&i!=k&&j!=k)
	    res=min(res,Dist(a[f[i]],a[f[j]])+Dist(a[f[j]],a[f[k]])+Dist(a[f[k]],a[f[i]]));
	}
	for (int i=1;i<=n;++i)
	for (int j=i+1;j<=min(n,i+alpha);++j)
	{
		tmp=Dist(a[f[i]],a[f[j]]);
		if (tmp<res)
		if (i!=j)
		for (int k=j+1;k<=min(n,j+alpha);++k)
		if ((i!=k) && (j!=k))
		{
			res=min(res,Dist(a[f[i]],a[f[j]])+Dist(a[f[j]],a[f[k]])+Dist(a[f[k]],a[f[i]]));
			if (dd(a[f[k]].first-a[f[i]].first)+dd(a[f[k]].first-a[f[j]].first)+tmp>res) break;
			//cout << rotate << "   " << i << " " << j << " " << k << "   " << res << endl;
		}
	}
	//cout << res << endl << endl;
}
void Process()
{
	for (int i=1;i<=n;++i) f[i]=i;
	res=dd(INF);
	for (int i=0;i<180;i+=delta) Cal(i);
	printf("%.12lf\n",res);
}
