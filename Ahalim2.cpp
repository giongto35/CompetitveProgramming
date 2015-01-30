#include <bits/stdc++.h>

using namespace std;
int main()
{
	int count;
	string st;
	//freopen("A.inp","r",stdin);
	//freopen("A.out","w",stdout);
	for (int i = 1; i<=10; i++)
	{
		getline(cin,st);
		st += "*";
		count = 0;
		for( int j = 0; j <= (int)st.length()-2 ; j++)
		{
			count++;
			if (st[j] != st[j+1])
			{
				cout<<count<<st[j];
				count = 0;
			}
		}
		cout<<endl;
	}

	for (int i = 1; i<=10; i++)
	{
		getline(cin,st);
		for( int j = 0; j <= (int)st.length()-1 ; j+=2)
		{
			for(int k = 1; k <= st[j] - '0'; k++)
			cout<<st[j+1];
		}
		cout<<endl;
	}

	fclose(stdin);
	fclose(stdout);
}
