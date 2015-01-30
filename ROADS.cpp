#include <iostream>
#include <cstdio>

using namespace std ;
const int maxn=30000+10;
int V[maxn];
int H[maxn];
char c;
int s,n,m,k;
int kq1[5],kq2[5];

int main()
{
    freopen("ROADS.inp","r",stdin);
    freopen("ROADS.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for (int i=1;i<=k;i++)
    {
        scanf("%s %d",&c,&s);
        if (c=='V')
        {
            V[s+1]++;// o canh hang s+1 co duong di qua
            V[s]++;//   o canh hang s   co duong di qua
        }
        else
        {
            H[s+1]++;// o canh cot s+1 co duong di qua
            H[s]++;//   o canh cot s   co duong di qua
        }
    }
    for(int i=1;i<=n;i++) kq1[V[i]]++;
    //mang kq1[i] nghia la so luong hang co i cai ke
    for(int i=1;i<=m;i++)
    for(int j=0;j<=2;j++) kq2[H[i]+j]+=kq1[j];
    //mang kq2, xu li tung cot de cong vao kq2, moi cot thi voi j la so luong ke cua cot them voi so luong ke cua hang + vao ket qua
    //in ra mang kq2
    for(int i=0;i<=4;i++) cout<<kq2[i]<<' ';
}
