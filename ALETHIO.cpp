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
string st;
string res,sres;
int i,j,k;
int main()
{
    //freopen("ALETHIO.inp","r",stdin);
    //freopen("ALETHIO.out","w",stdout);
    cin>>st;
    st="A"+st;
    st=st+"A";
    FOR(i,1,st.length()-1)
    {
        if (st[i]>='0'&&st[i]<='9');
        else
        {
            j=i-1;
            k=i+1;
            while (st[j]>='0'&&st[j]<='9'&&j-1>=0) j--;
            while (st[k]>='0'&&st[k]<='9'&&k+1<=st.length()-1) k++;
            j+=1;
            k-=1;
            if (k==(int)st.length()-1) k--;
            if (j>k) continue;
            res="";
            FOR(x,j,k)
            if (!(st[x]>='0'&&st[x]<='9')) res+="9"; else res+=st[x];
            while (res[0]=='0'&&res.length()>1) res.erase(0,1);
            if (sres.length()<res.length())sres=res;
            else
            if (sres.length()==res.length()) sres=max(sres,res);
        }
    }
    cout<<sres<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

