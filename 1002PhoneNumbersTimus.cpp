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
const int maxn= 50000+10;
string st;
string a[maxn];
const int oo=1000000000;
struct tracer
{
    int tr;
    int id;
}tr[maxn];
int n;
int F[maxn];
bool OK[30][10];

void trace(int vt)
{
    if (vt==0) return ;
    trace(tr[vt].tr);
    cout<<a[tr[vt].id]<<' ';
}

void gan(string st,int so)
{
    FOR(i,0,st.length()-1)
    OK[st[i]-'a'][so]=true;
}

int main()
{
    //freopen("PhoneNumbers.inp","r",stdin);
    //freopen("PhoneNumbers.out","w",stdout);
    gan("ij",1);
    gan("abc",2);
    gan("def",3);
    gan("gh",4);
    gan("kl",5);
    gan("mn",6);
    gan("prs",7);
    gan("tuv",8);
    gan("wxy",9);
    gan("oqz",0);
    while (getline(cin,st))
    {
        if (st=="-1") return 0;
        scanf("%d\n",&n);
        FOR(i,1,n) getline(cin,a[i]);
        F[0]=0;
        FOR(i,0,st.length()-1)
        {
            F[i+1]=oo;
            FOR(k,1,n)
            {
                bool ok=true;
                int l=a[k].length();
                if (i-l+1<0) continue;
                FOR(j,0,l-1)
                    if (OK[a[k][j]-'a'][st[i-l+j+1]-'0']==false) {ok=false;break;}
                if (ok)
                {
                    if (F[i+1]>F[i-l+1]+1)
                    {
                        F[i+1]=F[i-l+1]+1;
                        tr[i+1].tr=i-l+1;
                        tr[i+1].id=k;
                    }
                }
            }
        }
        //cout<<"KETQUA"<<F[st.length()]<<' '<<tr[st.length()].tr<<endl;
        if (F[st.length()]==oo)  cout<<"No solution."; else trace(st.length());
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

