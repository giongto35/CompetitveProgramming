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

string st1,st2;
int fr[100];
int ch[100];
pair<int,int> p[100];
char pp[100];
string res;
int T;

int main()
{
    //freopen("CHODE.inp","r",stdin);
    //freopen("CHODE.out","w",stdout);
    scanf("%d",&T);getline(cin,st1);
    FOR(i,1,T)
    {
    	getline(cin,st1);
    	getline(cin,st2);
    	memset(p,0,sizeof(p));
    	FOR(c,'a'-'a','z'-'a')
    	{
    		p[c].second = c;
    		FOR(i,0,st2.length()-1)
    		{
    			if (tolower(st2[i]) - 'a' == c) p[c].first++;
    		}
    	}

    	sort(p,p+'z'-'a'+1);
    	FOR(i,0,st1.length()-1)
    		pp[p[i].second] = tolower(st1[i]);
    	res="";
    	FOR(i,0,st2.length()-1)
    	{
    		if (tolower(st2[i])<'a' || tolower(st2[i])>'z') res+=st2[i];else
    		{
    		if (tolower(st2[i]) == st2[i]) res+=pp[st2[i]-'a'];
    		else
    			res+=toupper(pp[tolower(st2[i])-'a']);
    		}
    	}
    	printf("%s\n",res.c_str());
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
