#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000+10;
int n,m;
double res;
double C[maxn][maxn], Cn[maxn*maxn];
double F[maxn], G[maxn];

int main(){
		//freopen("C452.inp","r",stdin);
		//freopen("C452.out","w",stdout);
		cin>>n>>m;/*
		C[0][0] = 1;
		for (int i = 1; i <= max(n,m); i++)
		{
			C[i][0] = 1;
			for (int j = 1; j <= max(n,m); j++)
				C[i][j] = C[i-1][j] + C[i-1][j-1];
		} 
		Cn[n] = 1;
		for (int i = n + 1; i <= n * m; i++)
		{
			Cn[i] = Cn[i - 1] * i / (i - n);
		}
		res = 0;
		for (int i = 1; i <= m; i++)
		{
			F[i] =  Cn[i * n];
			for (int j = 1; j < i; j++)
			{
				F[i] = F[i] - F[j] * C[i][j];
				cout<<i<<' '<<j<<' '<<F[j]<<' '<<C[i][j]<<endl;
			}
			cout<<i<<' '<<F[i]<<endl;
			res = res + C[m][i] * F[i] / Cn[m * n] * 1.0 / i;
		}
		printf("%.6f",res);*/
		if ( n == 1 && m == 1) cout <<1<<endl;
		else
		{
			double res = 1.0 / n + (n - 1.0) / n * ( m - 1.0 ) / (m * n - 1);
			printf("%.6f", res);
		}
		fclose(stdin);
		fclose(stdout);
}
