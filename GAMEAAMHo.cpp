#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int sval(int a, int b)
{
	if (a == b)
		return 0;
	if (a < b)
		std::swap(a, b);
	int p, r;  // a = p*b + r
	r = a % b;
	p = a / b;
	if (r == 0)
	{
		return p-1;
	}
	int aa = sval(b, r);
	if (aa == 0)
	{
		return p;
	}
	else if (p <= aa)
		return p-1;
	else
		return p;
}

int main()
{
    freopen("GAMEAAMho.out","w",stdout);
    for(int i  = 1 ; i <= 100 ; i ++){ for(int j  = 1 ; j <= 100 ; j ++) cout<<sval(i,j)<<' '; cout<<endl;}
    return 0;
	int t, T;
	int x = 0;
	scanf("%d", &T);
	for (t = 0; t < T; ++t)
	{
		int n;
		scanf("%d", &n);
		x = 0;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			x ^= sval(a, b);
		}

		if (x == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
