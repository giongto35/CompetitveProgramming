// T-7 . O(Q) Solution
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=3007;

int m,n,k,lab[maxn],c[7],q,res;

int getroot(int u){
    if(lab[u]<0) return u;
    lab[u]=getroot(lab[u]);
    return lab[u];
}

void dsu(int a, int b){
    int r1=getroot(a), r2=getroot(b);
    if(r1==r2) return;
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

//#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    int x,y,z;
    scanf("%d%d%d%d",&k,&m,&n,&q);
    FOR(i,1,k+m+n) lab[i]=-1;
    REP(i,q){
        scanf("%d%d%d",&x,&y,&z);
        dsu(x,y+k);
        dsu(x,z+k+m);
    }
    reset(c,0);
    FOR(i,1,k+m+n)
        if(lab[i]<-1) c[0]++;
        else if(lab[i]==-1)
            if(i<=k) c[1]++;
            else if(i<=m+k) c[2]++;
            else c[3]++;
    if(c[0]+c[1]+c[2]+c[3]==1) puts("0");
    else{
        sort(c+1,c+4);
        FOR(i,1,3) if(c[0]==0){
            break;
        }else{
            c[i]++;
            c[0]--;
        }
        FOR(i,1,3) c[i]=max(0,c[i]-1); //first move, take out 3 from each c[]

        //each next move tack out 2
        sort(c+1,c+4);
        res=1+c[3]; //take all item in the biggest (c[3])

        //if chosing all item in c[3] doesn't enough...
        if(c[0]-(c[3]-c[2]-c[1])>0) res+=(c[0]-(c[3]-c[2]-c[1])+1)/2;
        printf("%d\n",res);
    }
    //getch();
    return 0;
}
