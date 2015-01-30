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

const int cmod = 1000000007;
const int maxn = 50000+10;
string st1;
string st2;
string st11;
long long res;
int pow10mod[maxn];

long long Tinh(int l, int r, string &st)
{
	long long res = 0;
	FOR(i,l,r)
	{
		res = ((res * 10) % cmod + (st[i] - '0')) % cmod;
	}
	return (res + cmod) % cmod;
}

long long calc(int dig, int vt, string &st)
{
	long long res = 0;
	int minus1 = 1;
	if (dig < st[vt] - '0') minus1 = 0;
	res = (((long long)Tinh(0, vt - 1, st) + 1 - minus1) * pow10mod[st.length() - vt - 1]) % cmod;
	if (st[vt] - '0' == dig)
	res = (res + Tinh(vt+1, st.length() - 1, st) + 1) % cmod;

	return (res + cmod) % cmod;
}

long long countnum(int dig, int vt)
{
 	return (calc(dig,vt,st2) - calc(dig,vt,st11) + cmod) % cmod;
}

void stringminus()
{
	st11 = st1;
	bool is0 = true;
	FOR(i,0,st1.length()) if (st1[i]!=0) is0 = false;
	if (is0 == true) return;
	DOW(i,st11.length()-1, 0)
	{
		if (st11[i] == '0')
			st11[i] = '9';
		else
		{
			st11[i]--;
			break;
		}
	}
}

int main()
{
    //freopen("parovi.inp","r",stdin);
    //freopen("parovi.out","w",stdout);
    cin>>st1>>st2;
    while (st1.length() < st2.length()) st1 = "0" + st1;
    while (st2.length() < st1.length()) st2 = "0" + st2;
    pow10mod[0] = 1;
    FOR(i,1,st1.length()) pow10mod[i] = (pow10mod[i-1]*10) % cmod;
    stringminus();
    FOR(i,0,st1.length()-1)
    {
    	FOR(j,0,9)
    	FOR(k,0,9)
    	{
    		int c1 = countnum(j, i);
    		int c2 = countnum(k, i);
    		if (c1 > 0 && c2 > 0)
    		res = (res + (((long long)c1 * c2) % cmod) * abs ( j - k )) % cmod;
    	}	
    }
   	cout<< (res % cmod + cmod ) % cmod<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
