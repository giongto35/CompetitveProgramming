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

vector<pair<int,int> > d[7];
int W,H,n;
int t,r,x,T;
bool b[200][200];

pair<int,int> block[4];

void gen()
{
    d[0].push_back(make_pair(0,0));
    d[0].push_back(make_pair(1,0));
    d[0].push_back(make_pair(1,1));
    d[0].push_back(make_pair(2,1));

    d[1].push_back(make_pair(0,1));
    d[1].push_back(make_pair(1,1));
    d[1].push_back(make_pair(1,0));
    d[1].push_back(make_pair(2,0));

    d[2].push_back(make_pair(0,0));
    d[2].push_back(make_pair(1,0));
    d[2].push_back(make_pair(2,0));
    d[2].push_back(make_pair(2,1));

    d[3].push_back(make_pair(0,1));
    d[3].push_back(make_pair(1,1));
    d[3].push_back(make_pair(2,0));
    d[3].push_back(make_pair(2,1));

    d[4].push_back(make_pair(0,0));
    d[4].push_back(make_pair(0,1));
    d[4].push_back(make_pair(1,0));
    d[4].push_back(make_pair(1,1));

    d[5].push_back(make_pair(0,0));
    d[5].push_back(make_pair(1,0));
    d[5].push_back(make_pair(2,0));
    d[5].push_back(make_pair(3,0));

    d[6].push_back(make_pair(0,1));
    d[6].push_back(make_pair(1,0));
    d[6].push_back(make_pair(1,1));
    d[6].push_back(make_pair(1,2));
}

void rot(int t, int r)
{
    for (int i = 0; i <= 3; i ++)
        block[i] = d[t][i];
    for (int tr = 1; tr <= r; tr ++)
    {
        int miny = 100000;
        int minx = 100000;
        for (int i = 0; i <= 3; i++)
        {
            block[i] = make_pair(block[i].second, -block[i].first);
            miny = min(miny, block[i].first);
            minx = min(minx, block[i].second);
        }
        for (int i = 0; i <= 3; i++)
        {
            block[i] = make_pair(block[i].first - miny, block[i].second - minx);
        }

    }

}

bool check(int y)
{
    for (int x = 0; x < W; x++)
        if (b[y][x] == false) return false;
    return true;
}

void pull(int y)
{
    for (int i = y; i >= 0; i--)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0)
                b[i][j] = false;
            else
                b[i][j] = b[i-1][j];
        }
    }
}

bool process()
{
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d",&t,&r,&x);
            rot(t - 1, r);
            int j = -4;
            for (; j <= H + 1; j++)
            {
                bool ok = true;
                for (int k = 0; k <= 3; k++)
                {
                    int ny = block[k].first + j;
                    int nx = block[k].second + x;
                    //cout<<ny<<' '<<nx<<endl;
                    if (ny >= H || (ny >= 0 && ny < H && nx >= 0 && nx < W && b[ny][nx] == true)) {
                        ok = false;
                        break;
                    }
                }
                if (ok == false) break;
            }
            j--;
            for (int k = 0; k <= 3; k++)
            {
                int ny = block[k].first + j;
                int nx = block[k].second + x;
                if (ny < 0)
                {
                    for (int k = i + 1; k <= n; k++)
                        scanf("%d%d%d",&t,&r,&x);
                    return false;
                }
            }
            int miny = 10000;
            for (int k = 0; k <= 3; k++)
            {
                int ny = block[k].first + j;
                int nx = block[k].second + x;
                miny = min(miny, ny);
                b[ny][nx] = true;
            }/*
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    if (b[i][j] == false) printf(".");
                    else printf("x");
                }
                printf("\n");
            }*/
            for (int ny = miny; ny <= min(ny + 5, H - 1); ny++)
            {
                if (check(ny))
                    pull(ny);
            }
        }
        return true;
}

int main()
{
    freopen("DAPAC.inp","r",stdin);
    //freopen("DAPAC.out","w",stdout);
    scanf("%d",&T);
    gen();
    for (int ste = 1; ste <= T; ste++)
    {
        scanf("%d%d%d",&W,&H,&n);
        //cerr<<W<<" "<<H<<" "<<n<<endl;
        memset(b, false, sizeof(b));
        cout<<"Case #"<<ste<<": "<<endl;
        if (process() == false)
        {
            cout<<"Game Over!"<<endl;
        }
        else
        {
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    if (b[i][j] == false) printf(".");
                    else printf("x");
                }
                printf("\n");
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

