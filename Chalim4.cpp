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

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int maxm=100+10;
const int maxn=20+10;
int needp[maxm];
int needn[maxm];
int addp[maxm];
int c[maxm];
int addn[maxm];
int d[(1<<20)-1];
string sneed;
const int oo=100000000;
string sadd;
priority_queue<pair<int, int> > f;
int u,ct;
int res,n,m;
int allbug;
int main()
{
    //freopen("chalim4.inp","r",stdin);
    //freopen("chalim4.out","w",stdout);
    while (true)
    {
        ct++;
        scanf("%d%d",&n,&m);
        if (n==0&&m==0) break;
        allbug=(1<<n)-1;
        FOR(i,1,m)
        {
            scanf("%d",&c[i]);
            cin>>sneed;
            cin>>sadd;
            needp[i]=0;
            needn[i]=0;
            addp[i]=0;
            addn[i]=allbug;
            FOR(j,0,sneed.length()-1)
            {
                if (sneed[j]=='+') needp[i]+=1<<j;
                if (sneed[j]=='-') needn[i]+=1<<j;
            }
            FOR(j,0,sadd.length()-1)
            {
                if (sadd[j]=='+') addp[i]+=1<<j;
                if (sadd[j]=='-') addn[i]-=1<<j;
            }
        }
        res=-1;
        while(!f.empty()) f.pop();
        FOR(i,0,allbug) d[i]=oo;
        d[allbug]=0;
        f.push(make_pair(0, allbug));
        while (!f.empty())
        {
            pair<int,int> now=f.top();f.pop();
            int u=now.second;
            if (u==0)
            {
                res=-now.first; break;
            }
            if (d[u]<-now.first) continue;
            FOR(j,1,m)
            {
                if (((u|needp[j])==u)&&((u&needn[j])==0))
                {
                    int v=((u|addp[j])&addn[j]);
                    if (d[v]>-now.first+c[j])
                    {
                        d[v]=-now.first+c[j];
                        f.push(make_pair(-d[v],v));
                    }
                }
            }
        }
        cout<<"Product "<<ct<<endl;
        if (res==-1) cout<<"Bugs cannot be fixed."<<endl;
        else cout<<"Fastest sequence takes "<<d[0]<<" seconds."<<endl;
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

