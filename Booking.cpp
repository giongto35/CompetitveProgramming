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

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int nummin = 1440;
const string oddmonth[7] = {"01","03","05","07","08","10","12"};
const string evenmonth[5] = {"02","04","06","09","11"};
int B;
int C;
string st;
string d1;
string t1;
string d2;
string t2;
int day,tt;
int date1;
int date2;
int T;	
vector<string> c;
vector<pair<long long,long long> > v;
struct event{
	int t;
	int idx;
	int v;
} e[100000];
int spt;
int res;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    elems.clear();
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

int convert2(vector<string> t)
{
	return (atoi(t[0].c_str()) * 60 + atoi(t[1].c_str()));

}

int convert1(vector<string> d)
{
	int res = 0;
	if (d[0] > "2013") res += 365;
	if (d[0] > "2014") res += 365;
	if (d[0] > "2015") res += 365;
	if (d[0] > "2016") res += 366;
	FOR(i,0,6)
	{
		if (d[1] > oddmonth[i])
		{
			res += 31;
		}
	}
	FOR(i,0,4)
		if (d[1] > evenmonth[i])
		{
			if (evenmonth[i] == "02")
			{
				if (d[0] == "2016") res += 29;
				else res+=28;
			}
			else res+= 30;
		}
	res+=atoi(d[2].c_str());
	return res;
}

bool mycmp(event a,event b)
{
	if (a.v == b.v) return a.t > b.t;
	return a.v < b.v;
}

int main()
{
    //freopen("Booking.inp","r",stdin);
    //freopen("Booking.out","w",stdout);
    cin>>T;
    FOR(sT,1,T)
    {
    	scanf("%d%d",&B,&C);
    	spt = 0;
    	FOR(i,1,B)
    	{
    		cin>>st>>d1>>t1>>d2>>t2;
    		
    		split(d1,'-',c);
    		day = convert1(c);
    		split(t1,':',c);
    		tt = convert2(c);
    		date1 = day * nummin + tt;

    		split(d2,'-',c);
    		day = convert1(c);
    		split(t2,':',c);
    		tt = convert2(c);
    		date2 = day * nummin + tt;

			++spt; 
			e[spt].t = 1;e[spt].idx = i;e[spt].v = date1;
			++spt;
			e[spt].t = 2;e[spt].idx = i;e[spt].v = date2 + C;
    	}
    	sort(e+1,e+1+spt,mycmp);
    	int cnt = 0;
    	res = 0;
    	FOR(i,1,spt)
    	{
    		if (e[i].t == 1) cnt++;
    		else cnt--;
    		res = max(res,cnt);
    	}
    	cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
