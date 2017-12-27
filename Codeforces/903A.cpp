#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int X;
		cin>>X;
		int flag=0;
		for(int i=0; i<=100; i++)
		{
			for(int j=0; j<=100; j++)
			{
				if(((3*i)+(7*j))==X)
				{
					flag=1;
				}
			}
		}	
		if(flag)
			cout<<"YES\n";
		else 
			cout<<"NO\n";
	}
	return 0;
}