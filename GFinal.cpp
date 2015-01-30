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
const int maxn=1000+10;
char so[maxn];
int n;

bool check(int bd,int l)
{
    bd=bd*bd;
    if (bd>9) l=l*2;
    else l=l*2-1;
    //cout<<s<<endl;
    //cout<<s2<<endl;
    if (l<n) return true;
    if (l>n) return false;
    //cout<<bd<<' '<<l<<endl;
    if (bd>9)
    {
        if (bd<=(so[0]-'0')*10+(so[1]-'0')) return true;
        else return false;
    }
    else
    {
        if (bd<=so[0]-'0') return true;
        else return false;
    }
}

int main()
{
    //freopen("GFinal.inp","r",stdin);
    //freopen("GFinal.out","w",stdout);
    while (true)
    {
        //getline(cin,so);
        scanf("%s\n",so);
        n=strlen(so);
        if (n==1&&so[0]=='0') break;
        int kq=0;
        DOW(i,9,1)
        {
            if (check(i,(n+1)/2)) {kq=i;break;}
        }
        printf("%d",kq);
        FOR(i,1,(n+1)/2-1) printf("%c",'0');
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

