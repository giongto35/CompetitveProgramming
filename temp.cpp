#include "bits/stdc++.h"
#include <iostream>

using namespace std;

unsigned long long a;
unsigned long long b;
unsigned long long a1,a2;
unsigned long long b1,b2;
int main()
{
	//freopen("temp.inp","r",stdin);
	//freopen("temp.out","w",stdout);
	while(cin>>a>>b){
		a1 = a / 10;
		b1 = b / 10;
		a2 = a % 10;
		b2 = b % 10;
		if (a1 + b1 + (a2 + b2) / 10 > 0)
		cout<<a1 + b1 + (a2 + b2) / 10;
		cout<<(a2 + b2)% 10<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
