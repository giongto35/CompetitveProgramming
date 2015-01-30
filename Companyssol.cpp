#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,K;
struct edge{
    int a,b,c,x;
}E[100009];
int fa[50009];

bool cmp(const edge &a,const edge &b){if(a.c==b.c) return a.x<b.x;return a.c<b.c;}
int find(int a){return a==fa[a]?a:fa[a]=find(fa[a]);}
bool union_set(int a,int b){a=find(a),b=find(b);if(a==b) return false;fa[a]=b;return true;}

int cal(int &cnt,int x){
    int ret=0;
    cnt=0;
    for(int i=0;i<m;i++) if(!E[i].x) E[i].c+=x;
    for(int i=0;i<n;i++) fa[i]=i;
    sort(E,E+m,cmp);
    for(int i=0,c=n-1;c;i++)
        if(union_set(E[i].a,E[i].b))
            c--,ret+=E[i].c,cnt+=!E[i].x;
    for(int i=0;i<m;i++) if(!E[i].x) E[i].c-=x;
    return ret;
}

int main(){
    freopen("companys.inp","r",stdin);
    //freopen("companys.out","w",stdout);
    int cas=0;
    while(scanf("%d%d%d",&n,&m,&K)+1)
    {
        for(int i=0;i<m;i++)
            scanf("%d%d%d%d",&E[i].a,&E[i].b,&E[i].c,&E[i].x);
        int cnt,s=-100,e=100,mid,res;
        while(s<=e){
            mid=(s+e)/2;
            cal(cnt,mid);
            if(cnt>=K) res=mid,s=mid+1;
            else e=mid-1;
        }
        printf("Case %d: %d\n",++cas,cal(cnt,res)-K*res);
    }
}
