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
string s2,st;
int i,j;
int main()
{
    //freopen("B291.in","r",stdin);
    //freopen("B291.out","w",stdout);
    getline(cin,st);
    i=0;
    st=st+' ';
    s2="";
    while (i<st.length())
    {
        if (st[i]==' ')
        {
            if (s2!="")
            cout<<"<"<<s2<<">"<<endl;
            s2="";
        }
        else
        s2=s2+st[i];
        if (st[i]=='"')
        {
            j=i+1;
            s2="";
            while (st[j]!='"')
            {
                s2=s2+st[j];
                j++;
            }
            cout<<"<"<<s2<<">"<<endl;
            s2="";
            i=j;
        }
        i++;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

