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
const int maxn=300;
int a[maxn][maxn];
int res[maxn],n,u;

void swap_row(int i,int j)
{
    FOR(k,1,n+1)
    {
        int tg=a[i][k];
        a[i][k]=a[j][k];
        a[j][k]=tg;
    }
}

void print()
{
    FOR(i,1,n)
    {
        FOR(j,1,n+1) cout<<a[i][j]<<' ';cout<<endl;
    }
    cout<<endl;
}
void gauss()
{
    //print();
    FOR(k,1,n)
    {
        int i_max=0;
        FOR(i,k,n)
            if (a[i][k]==1)
            {
                i_max=i;
                break;
            }
        if (i_max==0||a[i_max][k]==0) continue;
        swap_row(i_max,k);
        FOR(i,k+1,n)
            if (a[i][k]==1)
            FOR(j,k,n+1)
                a[i][j]=a[i][j] xor a[k][j];
    }
        //print();
    DOW(i,n,1)
    {
        if (a[i][i]==1)
        {
            res[i]=a[i][n+1];
            DOW(j,n,i+1)
            res[i]=res[i] xor (a[i][j]*res[j]);
        }
        else
        {
            res[i]=a[i][n+1];
            DOW(j,n+1,i+1)
            res[i]=res[i] xor (a[i][j]*res[j]);
            if (res[i]==1)
            {
                cout<<"No solution"<<endl;
                return;
            }
        }
    }
    vector<int> rs;
    FOR(i,1,n)
    if (res[i]==1) rs.push_back(i);
    FOR(i,0,rs.size()-2) cout<<rs[i]<<' ';
    cout<<rs[rs.size()-1]<<endl;
}

int main()
{
    //freopen("CentralHeating.inp","r",stdin);
    //freopen("CentralHeating.out","w",stdout);
    cin>>n;
    FOR(i,1,n)
    {
        FOR(j,1,n+1)
        {
            cin>>u;
            if (u==-1) break;
            a[u][i]=1;
        }
        a[i][n+1]=1;
    }
    gauss();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

