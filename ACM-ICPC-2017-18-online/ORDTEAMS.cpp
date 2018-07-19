#include <bits/stdc++.h>
using namespace std;
int A[3][3];
bool chk(int a, int b)
{
	int greater=0;
	for(int i=0; i<3; i++)
	{
		if(A[a][i]>A[b][i])greater=1;
		else if(A[a][i]==A[b][i])continue;
		else return false;
	}
	if(greater)return true;
	return false;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)cin>>A[i][j];
		}
		int flag=0;
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				if(i==j)continue;
				for(int k=0; k<3; k++)
				{
					if(k==i || k==j)continue;
					if(chk(i,j) && chk(j,k))
					{
						flag=1;
						break;
					}
				}
			}
		}
		if(flag==1)cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}