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
#include "conio.h"
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
const int maxd=521196;
const int maxn=50+10;
const int oo=1000000000;
string d[maxd+10];
string g[20][maxd];
int sl[20];
int F[maxn][10];
int c[maxn][maxn];
string st;
int n,T;
int res;

void process()
{
    FOR(i,0,n) FOR(j,0,5) F[i][j]=oo;
    F[0][5]=0;
    FOR(i,0,n)
    {
        FOR(j,i+1,i+12)
        {
            int l=j-i;
            FOR(x,1,sl[l])
            {
                string s=g[l][x];
                int cnt=0;
                int vt=-1;
                FOR(l,0,s.length()-1)
                {
                    cout<<l<<endl;
                    if (st[i+1+l]!=s[l])
                    {
                        cnt++;
                        vt=l;
                    }
                    if (cnt>1) break;
                }
                if (cnt<=1)
                FOR(k,0,5)
                {
                    if (F[i][k]==oo) continue;
                    if (cnt==0)
                        F[j][min(5,k+j-i)]=min(F[j][min(5,k+j-i)],F[i][k]);
                    else
                    if (cnt==1)
                    {w
                        if (i+1+vt>=i-k+5||k==5)
                            F[j][j-(l-1-vt)]=min(F[j][j-(l-1-vt)],F[i][k]+1);
                    }

                }
            }

        }
    }
    res=oo;
    FOR(k,0,n)
    {
        //if (F[n][k]==0) cout<<n<<' '<<k<<endl;
        res=min(res,F[n][k]);
    }
}

int main()
{
    freopen("garbled_email_dictionary.txt","r",stdin);
    FOR(i,1,maxd)
    {
        getline(cin,d[i]);
        g[d[i].length()][++sl[d[i].length()]]=d[i];
    }
    fclose(stdin);
    freopen("BCJB1.inp","r",stdin);
    freopen("B.out","w",stdout);
    cin>>T;
    getline(cin,st);
    FOR(t,1,T)
    {
        cout<<"Case #"<<t<<": ";
        getline(cin,st);
        n=st.length();
        st=' '+st;
        cerr<<t<<endl;
        process();
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

