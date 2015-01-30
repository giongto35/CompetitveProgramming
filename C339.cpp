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

string st;
const int maxm = 1000+10;
const int maxd = 50;
const int s0=25;
bool F[maxm][maxd][20];
pair< pair<int,int>,int> tr[maxm][maxd][20];
int m;

void trace(int i,int j,int k)
{
    if (i==0) return ;
    trace(i-1,tr[i][j][k].first.first,tr[i][j][k].second);
    cout<<tr[i][j][k].first.second<<' ';
}

int main()
{
    //freopen("C339.inp","r",stdin);
    //freopen("","w",stdout);
    getline(cin,st);
    scanf("%d",&m);
    st=" "+st;
    F[0][s0][0]=true;
    FOR(i,0,m)
    {
        FOR(j,-10+s0,10+s0)
        FOR(x,0,10)
        {
            if (F[i][j][x]==false) continue;
            if (i%2==0)
            {
                FOR(k,1,10)
                if (st[k]=='1'&&j+k>s0&&k!=x)
                {
                    F[i+1][j+k][k]=true;
                    tr[i+1][j+k][k]=make_pair(make_pair(j,k),x);
                }
            }
            else
            {
                FOR(k,1,10)
                if (st[k]=='1'&&j-k<s0&&k!=x)
                {
                    F[i+1][j-k][k]=true;
                    tr[i+1][j-k][k]=make_pair(make_pair(j,k),x);
                }
            }
        }
    }
    FOR(j,-10+s0,10+s0)FOR(x,1,10) if (F[m][j][x])
    {
        cout<<"YES"<<endl;
        trace(m,j,x);
        return 0;
    }
    cout<<"NO";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

