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
#include <ctime>
#include <cstring>
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
int n,m,i,j;
int a[200][200];

void process(int m)
{
    memset(a,0,sizeof(a));
    FOR (j,1,m) a[i][j]=0;
    a[1][m+1]=1;
    FOR(i,2,m+1)
    FOR(j,1,m+1)
    {
        if (j==1)
        {
            a[i][j]=a[i-1][j+1];
        }
        else
        {
            if (j==m+1)
            {
                a[i][j]=a[i-1][j-1];
            }
            else
            {
                a[i][j]=a[i-1][j-1] xor a[i-1][j+1];
            }
        }
    }
    int sum=0;
    FOR (i,1,m+1)
        sum+=a[m+1][i];/*
    FOR(i,1,m+1)
{
    FOR(j,1,m+1)
    cout<<a[i][j];
    cout<<endl;
}*/
    cout<<sum<<' ';
}

int main()
{
//    freopen("C261.inp","r",stdin);
    freopen("C261.out","w",stdout);
    FOR(i,1,100)
    process(i);

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

