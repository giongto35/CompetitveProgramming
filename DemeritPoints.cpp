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

const int maxn = 100000;
int T;
string st;
pair<int,int> a[maxn];
int spt;
int merit;
int demerit;
int t;

void printday(int t)
{
    printf("%d-",t/10000);
    if ((t/100) % 100 < 10) printf("0%d-",(t / 100) % 100); else printf("%d-",(t / 100) % 100);
    if (t % 100 < 10) printf("0%d ",t % 100); else printf("%d ",t % 100);

    //printf("%4d-%2d-%2d ",t / 10000, (t / 100) % 100, t % 100);
}

void print(int t)
{
    printday(t);
    if (merit == 0 && demerit == 0) printf("No merit or demerit points.\n");else
    if (merit > 0) printf("%d merit point(s).\n",merit);else
    printf("%d demerit point(s).\n",demerit);
}

int main()
{
    //freopen("D.4.dat","r",stdin);
    //freopen("DemertiPoints.out","w",stdout);
    scanf("%d",&T);
    getline(cin,st);
    getline(cin,st);
    FOR(i,1,T)
    {
        spt = 1;
        while(true)
        {
            getline(cin,st);
            if (st.length() == 0|| st[0] == ' ') break;
            int vt = 0;
            FOR(i,0,st.length()-1) if (st[i] == ' ')  vt = i;
            a[spt].first = atoi( st.substr(0,8).c_str());
            if (spt > 1)
            a[spt].second = atoi(st.substr(vt+1,st.length() - 9).c_str());
            spt++;
        }
        spt--;
        t = a[1].first;
        merit = 0; demerit = 0;
        print(t);
        int j = 2;
        while (true)
        {
            //t = t + 10000;
            if (demerit == 0)
            {
                t += 20000;
                if (j > spt || t <= a[j].first)
                {
                    merit++;
                    print(t);
                }
            }
            else
            {
                t += 10000;
                if (j > spt || t <= a[j].first)
                {
                    demerit = max(0,min(demerit / 2, demerit - 2));
                    print(t);
                }
            }
            if (j <= spt && t >= a[j].first)
            {
                t = a[j].first;
                demerit = demerit + a[j].second;
                if (demerit > merit * 2) {demerit -= merit * 2; merit = 0;}else
                {
                    merit -= demerit / 2;
                    demerit = 0;
                }
                print(t);
                j++;
            }
            if (merit >= 5 && j == spt+1) break;
        }
        if (i != T)
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

