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
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
string s;
string s2;
string res;

int main()
{
    //freopen("Amini9.inp","r",stdin);
    //freopen("Amini9.out","w",stdout);
    res="";
    while (true)
    {
        getline(cin,s);
        s2="";
        s=s+' ';
        FOR(i,0,s.length()-1)
        {
            if ((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]=='-'))
            s2=s2+s[i];
            else
            {
                if (s2=="E-N-D")
                {
                    FOR(j,0,res.length()-1) res[j]=tolower(res[j]);
                    cout<<res<<endl;
                    return 0;
                }
                if (s2.length()>res.length()) res=s2;
                s2="";
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

