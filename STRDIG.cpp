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
#include <iomanip>

using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

string st;
int T;

long long tonum(string s)
{
    //stringstream ss;
    //ss<<s;
    //int res;
    //ss>>res;
    //return res;
    return atoll(s.c_str());
}

string tostr(long long num)
{
    stringstream ss;
    ss<<num;
    return ss.str();
}

int l10(long long so)
{
    if (so==0) return 0; else return log10(so);
}

bool check()
{
    long long so;
    int cnt=0;
    FOR(j,0,st.length()-1) if (st[j]=='0')cnt++;
    if (cnt==st.length()&&cnt<=9)return true;
    if (st.length()<=10&&st[0]!='0')
    {
        so=tonum(st);
        if (so<=1000000000) return true;
    }

        FOR(dd,1,min((int)st.length(),10))//do dai
        FOR(i,0,dd-1)
        {//87457
            //if ((dd==1&&i==0)==false) continue;
            /*if ((st.length()-i)/dd>0)
            {*/
            //cout<<i<<' '<<dd<<endl;
                if (i+dd>st.length())//((st.length()-i)/dd==0)
                {
                    int j=st.length()-i;
                    string s1=st.substr(0,i);
                    string s2=st.substr(st.length()-j,j);
                    while (s1.length()<dd) s1="x"+s1;
                    while (s2.length()<dd) s2=s2+"x";
                    bool ok=true;
                    FOR(k,0,s1.length())
                    {
                        if (s1[k]=='x')
                            s1[k]=s2[k];
                        else
                        if (s1[k]!='x'&&s2[k]!='x'&&s1[k]!=s2[k])
                            ok=false;
                    }
                    if (ok)
                    {
                        so=tonum(s1);
                        so++;
                    }
                } else
                so=tonum(st.substr(i,dd));
                //if (so-1<0) continue;
                string bf=tostr(so-1);
                while (bf.length()<dd) bf="0"+bf;
                if (st.substr(0,i)==bf.substr(dd-i,i)&&so>0&&so<=1000000000) //(match(0,i-1,so-1))
                {

                    bool ok=true;
                    int k;
                    for(k=i;k+l10(so)+1<=st.length();k+=(l10(so-1)+1))
                    {
                        //cout<<tonum(st.substr(k,l10(so)))<<' '<<so<<endl;
                        if (tonum(st.substr(k,l10(so)+1))==so)
                            so++;
                        else
                        {
                            ok=false;
                            break;
                        }
                    }
                    if (ok)
                    {
                        if (k==st.length()) so--;
                        if ((tostr(so).substr(0,st.length()-k))==st.substr(k,st.length()-k))
                            return (so<=1000000000);

                    }
                //}
            }
        }
        return false;
}

int main()
{
    freopen("STRDIG.inp","r",stdin);
    //freopen("STRDIG.out","w",stdout);
    scanf("%d",&T);
        getline(cin,st);
    FOR(i,1,T)
    {
        getline(cin,st);
        if (check()) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

