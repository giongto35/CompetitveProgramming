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
int cnt[10],n,spt,s;
int a[10];

void calc(int so,int x1,int x5,int x10)
{
    if (so==1) cnt[x1]+=1,cnt[x5]+=0;
    if (so==2) cnt[x1]+=2,cnt[x5]+=0;
    if (so==3) cnt[x1]+=3,cnt[x5]+=0;
    if (so==4) cnt[x1]+=1,cnt[x5]+=1;
    if (so==5) cnt[x1]+=0,cnt[x5]+=1;
    if (so==6) cnt[x1]+=1,cnt[x5]+=1;
    if (so==7) cnt[x1]+=2,cnt[x5]+=1;
    if (so==8) cnt[x1]+=3,cnt[x5]+=1;
    if (so==9) cnt[x1]+=1,cnt[x10]+=1;
}

int main()
{
    int dem=0;
    //freopen("Ahalim7.inp","r",stdin);
    //freopen("Ahalim7.out","w",stdout);
    while(true)
    {
        cin>>n;
        dem++;
        if (n==0) break;
        FOR(i,0,9) cnt[i]=0;
        FOR(i,1,n)
        {
            cin>>s;
            spt=0;
            memset(a,0,sizeof(a));
            while(s>0)
            {
                a[++spt]=s%10;
                s/=10;
            }
            calc(a[1],0,1,2);
            calc(a[2],2,3,4);
            calc(a[3],4,5,6);
            calc(a[4],6,7,8);
        }
            FOR(i,0,5)
                cout<<cnt[i]<<' ';
            cout<<cnt[6];
            cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

