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
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
string s;
int n;
int cnt[30];
string temp;
int chia(int a,int b)
{
    if (a%b==0) return a/b;
    else return a/b+1;
}

int main()
{
    //freopen("A335.inp","r",stdin);
    //freopen("A355.out","w",stdout);
    cin>>s;
    stringstream ss;
    FOR(i,0,s.length()-1)
    {
        cnt[s[i]-'a']++;
    }
    cin>>n;
    FOR(i,1,s.length())
    {
        int dem=0;
        FOR(j,0,'z'-'a')
        {
            dem=dem+chia(cnt[j],i);
        }
        if (dem<=n)
        {
            cout<<i<<endl;
            dem=0;
            FOR(j,0,'z'-'a')
            {
                dem=dem+chia(cnt[j],i);
                FOR(k,1,chia(cnt[j],i))
                {
                    char c=(j+'a');
                    cout<<c;
                }
            }
            while (dem<n) cout<<"a",dem++;
            return 0;
        }
    }
    cout<<-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

