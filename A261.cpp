#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,m,i,a[100005],b,x=100005,s=0;
	cin>>m;
	for(i=0;i<m;i++)
		cin>>b,x=min(x,b);
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	reverse(a,a+n);
	for(i=0;i<n;i++)
		if(i%(x+2)<x)
			s+=a[i];
	cout<<s;
	return 0;
}
