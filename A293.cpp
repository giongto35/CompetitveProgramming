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
string s1;
string s2;
int t[2][2];
int num1,num2,n;

void ketluan()
{
    if (num1==num2) cout<<"Draw"<<endl;
    else
    if (num1>num2)
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
}

int main()
{
    //freopen("A293.inp","r",stdin);
    //freopen("A293.out","w",stdout);
    cin>>n;
    n=n*2;
    getline(cin,s1);
    getline(cin,s1);
    getline(cin,s2);
    FOR(i,0,n-1) t[s1[i]-'0'][s2[i]-'0']++;
    num1=(t[1][1]+1)/2;
    num2=t[1][1]/2;
    if (t[0][1]==0&&t[1][0]==0)
    {
        ketluan();
        return 0;
    }
    if (t[1][1]%2==1)
    {
        if (t[0][1]>0)
        {
            t[0][1]--;
            num2++;
        }
        else
            t[1][0]--;
    }
    int v=min(t[1][0],t[0][1]);
    num1=num1+v;
    num2=num2+v;
    t[1][0]-=v;
    t[0][1]-=v;
    if (t[1][0]>0) num1=num1+(t[1][0]+1)/2;
    if (t[0][1]>0) num2=num2+t[0][1]/2;
    ketluan();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

