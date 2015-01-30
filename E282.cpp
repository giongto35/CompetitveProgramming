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
const int maxn=100000+10;

struct Node{long long so;Node * a[2];};
Node *root;
int n;
Node* InitNode(long long s)
{
    Node* node;
    node=(Node*)(malloc) (sizeof(Node));
    FOR(i,0,1) node->a[i]=NULL;
    node->so=s;
    return node;
}

long long s[maxn],a[maxn],u,v,res;
int main()
{
    //freopen("E282.in","r",stdin);
    cin>>n;
    //freopen("E282.out","w",stdout);
    FOR(i,1,n)
    cin>>a[i];
    DOW(i,n,1)
    s[i]=s[i+1]^a[i];
    root=InitNode(0);
    FOR(x,0,n)
    {
        u=s[x+1];
        v=v ^ a[x];
        Node* p=root;
        DOW(i,40,0)
{
            if (p->a[1-((u>>i)&1)]!=NULL) p=p->a[1-((u>>i)&1)];else
            if (p->a[(u>>i)&1]!=NULL) p=p->a[(u>>i)&1];
            else break;
        //if (x==n) cout<<1-((u>>i)&1)<<' '<<p->so;

}
        if (p!=NULL)
        res=max(res,u^(p->so));
        p=root;
        DOW(i,40,0)
        {
            //c<<((v>>i)&1);
            if (p->a[(v>>i)&1]==NULL) p->a[(v>>i)&1]=InitNode(v);
            p=p->a[(v>>i)&1];

        }
    }
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
