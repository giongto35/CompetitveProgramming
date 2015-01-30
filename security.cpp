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
const int maxn=100+10;
string s1,s2;
string a1[maxn];
string a2[maxn];
int k,T;

int n, m, res;
vector<int> X[maxn];
int mX[maxn], mY[maxn];
bool mark[maxn];

int find(int x) {
	if (x == 0) return 1;
	if (mark[x]) return 0;
	mark[x] = 1;
	FOR(i,0, X[x].size()-1) {
		int y = X[x][i];
		if (find(mY[y])) {
			mX[x] = y; mY[y] = x;
			return 1;
		}
	}
	return 0;
}

bool match(int i,int j)
{
    FOR(x,0,k-1)
    {
        if (a1[i][x]==a2[j][x]||a1[i][x]=='?'||a2[j][x]=='?');
        else
            return false;
    }
    return true;
}

string ghep(string &s1,string &s2)
{
    string temp="";
    FOR(i,0,s1.length()-1)
    {
        if (s1[i]!='?') temp+=s1[i];
        else
        if (s2[i]!='?') temp+=s2[i];
        else
        temp+='a';
    }
    return temp;
}

int main()
{
    freopen("security.txt","r",stdin);
    freopen("security.out","w",stdout);
    cin>>T;
    FOR(ct,1,T)
    {
        cin>>m;
        getline(cin,s1);
        getline(cin,s1);
        getline(cin,s2);
        k=s1.length()/m;
        FOR(i,1,m) a1[i]=s1.substr((i-1)*k,k);
        FOR(i,1,m) a2[i]=s2.substr((i-1)*k,k);

        FOR(i,1,m) X[i].clear();
        memset(mX,0,sizeof(mX));
        memset(mY,0,sizeof(mY));

        FOR(i,1,m)
        FOR(j,1,m)
        {
            if (match(i,j))
                X[i].push_back(j);
        }
        res=0;
        FOR(i, 1, m)
		if (mX[i] == 0) {
			memset(mark, 0, sizeof mark);
			res += find(i);
		}
        cout<<"Case #"<<ct<<": ";
        if (res!=m)cout<<"IMPOSSIBLE";else
        FOR(i,1,m)
        {
            cout<<ghep(a1[i],a2[mX[i]]);
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

