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
const int maxn=100+10;
const int oo=1500000000;
string st1,st2;
int G[maxn][maxn],G2[maxn][maxn];
int next[maxn][30];
int cnt,c2,b,d;
int l1,l2,fl1;
int main()
{
    //freopen("B314.inp","r",stdin);
    //freopen("B314.out","w",stdout);
    cin>>b>>d;
    getline(cin,st1);
    getline(cin,st1);
    getline(cin,st2);
    int n=st1.length();
    int m=st2.length();
    l1=n*b;
    l2=m*d;

    st1=" "+st1+st1;
    st2=" "+st2;
    FOR(j,0,'z'-'a') next[(int)st1.length()-1][j]=oo;
    DOW(i,st1.length()-2,0)
    {
        FOR(j,'a'-'a','z'-'a') next[i][j]=next[i+1][j];
        next[i][st1[i+1]-'a']=i+1;
    }
    int x=0;
    int y=0;
    int c2=0;
    int cnt=0;
    //cout<<n<<' '<<m<<' '<<c2<<' '<<l1<<endl;
    while (c2<l1)
    {
        y++;
        if (y>m) y-=m;

        if (c2+next[x][st2[y]-'a']-x>l1) break;
        cnt++;
        c2=c2+next[x][st2[y]-'a']-x;
        x=next[x][st2[y]-'a'];
        //cout<<x<<' '<<st2[y]<<endl;
        if (x>n) x-=n;
        //cout<<x<<' '<<y<<' '<<c2<<' '<<cnt<<endl;
        if (G[x][y]==0)
        {
            G[x][y]=cnt;
            G2[x][y]=c2;
        }
        else
        {
            int u1=G[x][y];
            int ck1=cnt-u1;
            int u2=G2[x][y];
            int ck2=c2-u2;
            int sl=(l1-u2)/ck2;
            cnt=u1+sl*ck1;
            c2 =u2+sl*ck2;
            break;
        }
    }
    //cout<<cnt<<' '<<c2<<endl;
    while (c2<l1)
    {
        y++;
        if (y>m) y-=m;

        if (c2+next[x][st2[y]-'a']-x>l1) break;
        cnt++;
        c2=c2+next[x][st2[y]-'a']-x;
        x=next[x][st2[y]-'a'];
        if (x>n) x-=n;
    }
    //cout<<cnt<<' '<<c2<<endl;

    cnt=cnt/m;
    cnt=cnt/d;
    cout<<cnt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

