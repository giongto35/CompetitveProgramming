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

int x1[10],y11[10],x2[10],y2[10],x3[10],y3[10];
int res,T;

void rot(int &x, int &y, int x0, int y0)
{
    x = x - x0;
    y = y - y0;
    swap(x, y);
    x = -x;
    x += x0;
    y += y0;
}

void rot(double &x, double &y, double x0, double y0)
{
    x = x - x0;
    y = y - y0;
    swap(x, y);
    x = -x;
    x += x0;
    y += y0;
}

bool check()
{
    double midx = (x1[4] + x1[1] + x1[2] + x1[3] + 0.0) / 4;
    double midy = (y11[4] + y11[1] + y11[2] + y11[3] + 0.0) / 4;
    /*pair<int,int> c[5];
    for (int i = 1; i <= 4; i++)
    {
        c[i] = make_pair(x1[i] - midx, x2[i] - midy);
    }
    sort(c + 1, c + 1 + 4);
    bool used[5];*/
    vector<int> xx;
    xx.clear();
    for (int i = 2; i <= 4; i++)
    {
        //if (c[i].first == c[i-1].first && c[i].second == c[i-1].second) return false;
        double x = x1[1];
        double y = y11[1];
        for (int k = 1; k <= 3; k++)
        {
            rot(x, y, midx, midy);
            if (x == x1[i] && y == y11[i])
            {
                xx.push_back(k);
                break;
            }
        }
    }
    sort(xx.begin(), xx.end());
    if (xx.size() == 3 && xx[0] == 1 && xx[1] == 2 && xx[2] == 3) return true;
    else return false;
}

int main()
{
    //freopen("C474.inp","r",stdin);
    //freopen("C474.out","w",stdout);
    scanf("%d",&T);
    /*x1[1] = -1; y11[1] = -1;
    x1[2] = 1; y11[2] = 1;
    x1[3] = -1; y11[3] = 1;
    x1[4] = 1; y11[4] = -1;
    cout<<check()<<endl;*/
    while(T--)
    {
        for (int i = 1; i <= 4; i++)
        {
            scanf("%d %d %d %d",&x1[i], &y11[i], &x2[i], & y2[i]);
            x3[i] = x1[i];
            y3[i] = y11[i];
        }
        res = 50;
        for (int i = 0; i <= 3; i++)
        {
            x1[3] = x3[3];
            y11[3] = y3[3];
            for (int j = 0; j <= 3; j++)
            {
                x1[2] = x3[2];
                y11[2] = y3[2];
                for (int k = 0; k <= 3; k++)
                {
                    x1[1] = x3[1];
                    y11[1] = y3[1];
                    for (int l = 0; l <= 3; l++)
                    {
                        /*if (l == 1 &&j == 2 && k == 0 & i == 0)
                        {
                            //cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<x1[1]<<' '<<y11[1]<<' '<<x1[2]<<' '<<y11[2]<<' '<<x1[3]<<' '<<y11[3]<<' '<<x1[4]<<' '<<y11[4]<<endl;
                        }*/
                        if (check())
                        {
                            res = min(res, i + j + k + l);
                        }
                        rot(x1[1],y11[1],x2[1],y2[1]);
                    }
                    rot(x1[2],y11[2],x2[2],y2[2]);
                }
                rot(x1[3],y11[3],x2[3],y2[3]);
            }
            rot(x1[4],y11[4],x2[4],y2[4]);
        }
        if (res == 50) cout<<-1<<endl;
        else cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

