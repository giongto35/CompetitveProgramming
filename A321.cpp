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
int a,b;
string st;
pair<int,int> u,v;

pair<int,int> go(int sx,int sy,int l,int r)
{
    pair<int,int> u=make_pair(sx,sy);
    FOR(i,l,r)
    {
        if (st[i]=='U') u.second++;
        if (st[i]=='D') u.second--;
        if (st[i]=='L') u.first--;
        if (st[i]=='R') u.first++;
    }
    return u;
}
int main()
{
    //freopen("A321.inp","r",stdin);
    //freopen("A321.out","w",stdout);
    cin>>a>>b;getline(cin,st);
    getline(cin,st);
    u=go(0,0,0,st.length()-1);
    //cout<<u.first<<' '<<u.second<<endl;
    FOR(j,0,st.length()-1)
    {
        v=go(a,b,j+1,st.length()-1);
        //cout<<v.first<<' '<<v.second<<endl;
        if (u.first==0&&u.second==0)
        {
            if (v.first==0&&v.second==0)
            {
                cout<<"Yes";
                return 0;
            }
        }
        else
        if (u.first==0)
        {
            if (v.first==0&&(long long)v.second*u.second>=0&&v.second%u.second==0)
            {
                cout<<"Yes";
                return 0;
            }
        }
        else
        if (u.second==0)
        {
            if (v.second==0&&(long long)u.first*v.first>=0&&v.first%u.first==0)
            {
                cout<<"Yes";
                return 0;
            }
        }
        else
        {
            if ((long long)v.first*u.first>=0&&(long long)v.second*u.second>=0)
            if (v.first%u.first==0&&v.second%u.second==0&&v.first/u.first==v.second/u.second)
            {
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
    return 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

