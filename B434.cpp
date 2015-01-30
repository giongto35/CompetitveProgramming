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

const int maxn = 1000+10;
int a[maxn][maxn];
int u,x,y;
int h[4][maxn][maxn];
int res;
vector<int> st;
int s[maxn];
int n,m,q;
int vt[maxn];

int cal(int bd, int x)
{
    st.push_back(0);
    int top = 0;
    memset(vt,0,sizeof(vt));
    memset(s,0,sizeof(s));
    s[top] = 0;
    int res = 0;
    for (int i = 1; i < st.size(); i++)
    {
        int temp = i;
        //cout<<bd + i - 1<<endl;
        while (top > 0 && s[top] > st[i])
        {
            //cout<<bd + vt[top] - 1<<' '<<x<<' '<<bd + i - 2<<endl;
            if (bd + i - 2>= x && x >= bd + vt[top] - 1)
            res = max(res,(i - vt[top]) * s[top]);
            temp = vt[top];
            top--;
        }
        if (s[top] != st[i])
        {
            top++;
            s[top] = st[i];
            vt[top] = temp;
        }
    }
    return res;
}
/*
Procedure Tinh(r:longint);
var i,Temp:longint;
Begin
        top:=0;s[top]:=0;H[r,m+1]:=0;
        for i:=1 to m+1 do
        Begin
          Temp:=i;
          while S[top]>H[r,i] do
          Begin
            Res:=Max(Res,(i-VT[top])*S[top]);
            Temp:=VT[top];
            Dec(Top);
          End;
          if S[top]<>H[r,i] then
          Begin
            inc(top);
            S[top]:=H[r,i];
            VT[top]:=Temp;
          End;
        End;
End;
*/
int main()
{
    //freopen("B434.inp","r",stdin);
    //freopen("B434.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        scanf("%d",&a[i][j]);

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
        if (a[i][j] == 0) h[0][i][j] = 0; else h[0][i][j] = h[0][i-1][j]+1;
    }

    for (int i = n; i >= 1; i--)
    for (int j = 1; j <= m; j++)
    {
        if (a[i][j] == 0) h[1][i][j] = 0; else h[1][i][j] = h[1][i+1][j]+1;
    }


    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
        if (a[i][j] == 0) h[2][i][j] = 0; else h[2][i][j] = h[2][i][j-1]+1;
    }

    for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--)
    {
        if (a[i][j] == 0) h[3][i][j] = 0; else h[3][i][j] = h[3][i][j+1]+1;
    }
    for (int cq = 1; cq <= q; cq++)
    {
        scanf("%d%d%d",&u,&y,&x);
        if (u == 1)
        {
            a[y][x] = a[y][x] ^ 1;
            for (int i = 1; i <= n; i++)
            if (a[i][x] == 0) h[0][i][x] = 0; else h[0][i][x] = h[0][i-1][x]+1;
            for (int i = n; i >= 1; i--)
            if (a[i][x] == 0) h[1][i][x] = 0; else h[1][i][x] = h[1][i+1][x]+1;
            for (int j = 1; j <= m; j++)
            if (a[y][j] == 0) h[2][y][j] = 0; else h[2][y][j] = h[2][y][j-1]+1;
            for (int j = m; j >= 1; j--)
            if (a[y][j] == 0) h[3][y][j] = 0; else h[3][y][j] = h[3][y][j+1]+1;
        }
        if (u == 2)
        {
            res = 0;
            st.clear();
            st.push_back(0);
            for (int i = y - h[0][y][x] + 1; i <= y + h[1][y][x] - 1; i++) st.push_back(h[2][i][x]);
            res = max(res,cal(y - h[0][y][x] + 1,y));
            st.clear();
            st.push_back(0);
            for (int i = y - h[0][y][x] + 1; i <= y + h[1][y][x] - 1; i++) st.push_back(h[3][i][x]);
            res = max(res,cal(y - h[0][y][x] + 1,y));
            st.clear();
            st.push_back(0);
            for (int j = x - h[2][y][x] + 1; j <= x + h[3][y][x] - 1; j++) st.push_back(h[0][y][j]);
            res = max(res,cal(x - h[2][y][x] + 1,x));
            st.clear();
            st.push_back(0);
            for (int j = x - h[2][y][x] + 1; j <= x + h[3][y][x] - 1; j++) st.push_back(h[1][y][j]);
            res = max(res,cal(x - h[2][y][x] + 1,x));
            cout<<res<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

