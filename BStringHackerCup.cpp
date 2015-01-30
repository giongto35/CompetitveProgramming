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
string st;
int m;
int res;
int cnt[30];
vector<int> x;
int main()
{
    freopen("beautiful_stringstxt.txt","r",stdin);
    freopen("Bstring.out","w",stdout);
    cin>>m;getline(cin,st);
    FOR(i,1,m)
    {
        getline(cin,st);
        res=0;
        memset(cnt,0,sizeof(cnt));
        FOR(j,0,st.length()-1)
        {
            //cout<<toupper(st[j])<<' '<<'A'<<' '<<toupper(st[j])-'A'<<endl;
            //res+=toupper(st[j])-'A';
            if (toupper(st[j])>='A'&&toupper(st[j])<='Z')
            cnt[toupper(st[j])-'A'+1]++;
        }
        sort(cnt+1,cnt+26+1);
        FOR(j,1,26)
        res+=cnt[j]*j;
        printf("Case #%d: %d\n",i,res);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

