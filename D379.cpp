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

const int maxn = 100+10;
char ch[2] = {'A','C'};
long long F[maxn];
int L[maxn],R[maxn];
int l1,r1,l2,r2;
int maxAC1,maxAC2;
string st1,st2;
int k,x,n,m;
int main()
{
    //freopen("D379.inp","r",stdin);
    //freopen("D379.out","w",stdout);
    scanf("%d%d%d%d",&k,&x,&n,&m);
    FOR(i,1,n) st1 = st1 + " ";
    FOR(i,1,m) st2 = st2 + " ";
    FOR(l1,0,1)
    FOR(r1,0,1)
    FOR(l2,0,1)
    FOR(r2,0,1)
    {
        if (n==1&&l1!=r1) continue;
        if (m==1&&l2!=r2) continue;
        L[1] = l1; R[1] = r1; L[2] = l2; R[2] = r2;
        maxAC1 = n - 2;
        maxAC2 = m - 2;
        if (L[1] == 0) maxAC1++;
        if (R[1] == 1) maxAC1++;
        if (L[2] == 0) maxAC2++;
        if (R[2] == 1) maxAC2++;
        maxAC1 /= 2;
        maxAC2 /= 2;
        FOR(j,0,maxAC1)
        FOR(j2,0,maxAC2)
        {
            F[1] = j;
            F[2] = j2;
            FOR(i,3,k)
            {
                F[i] = F[i-2] + F[i-1] + (R[i-2]==0)*(L[i-1]==1);
                R[i] = R[i-1];
                L[i] = L[i-2];
            }
            if (F[k] == x)
            {
                st1[0] = ch[L[1]];
                st1[n-1]= ch[R[1]];
                st2[0] = ch[L[2]];
                st2[m-1]= ch[R[2]];
                int s1 = j;
                int s2 = j2;
                int bd1 = 1;
                int bd2 = 1;
                if (n > 1 && s1 > 0 && st1[0] == 'A') st1[1] ='C',s1--,bd1++;
                if (m > 1 && s2 > 0 && st2[0] == 'A') st2[1] ='C',s2--,bd2++;
                if (n > 1 && s1 > 0 && st1[n-1] == 'C') st1[n-2] ='A',s1--;
                if (m > 1 && s2 > 0 && st2[m-1] == 'C') st2[m-2] ='A',s2--;
                while(s1>0)
                {
                    st1[bd1] = 'A';
                    st1[bd1+1]= 'C';
                    bd1+=2;
                    s1--;
                }
                while(s2>0)
                {
                    st2[bd2] = 'A';
                    st2[bd2+1]= 'C';
                    bd2+=2;
                    s2--;
                }
                FOR(i,0,n-1) if (st1[i] == ' ') st1[i] = 'B';
                FOR(i,0,m-1) if (st2[i] == ' ') st2[i] = 'B';
                cout<<st1<<endl;
                cout<<st2<<endl;
                return 0;
            }
        }
    }
    cout<<"Happy new year!"<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

