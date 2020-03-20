#include "bits/stdc++.h"
using namespace std;
int main()
{
	int x,y;
	char A[9][9];
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
			cin>>A[i][j];
	/*for(int i=0; i<9; i++){
		for(int j=0; j<9; j++)
			cout<<A[i][j];
		cout<<endl;
	}*/
	cin>>x>>y;
	x=x%3;
	y=y%3;
	if(x==0)x=3;
	if(y==0)y=3;
	x--;
	y--;
	int flag=0;
	for(int i=(3*x); i<(3*x)+3; i++)
	{
		for(int j=(3*y); j<(3*y)+3; j++)
		{
			if(A[i][j]=='.'){
				flag=1;
				break;
			}
		}
	}
	if(flag)
	{
		for(int i=(3*x); i<(3*x)+3; i++)
		{
			for(int j=(3*y); j<(3*y)+3; j++)
			{
				if(A[i][j]=='o' || A[i][j]=='x'){
					
				}
				else A[i][j]='!';
			}
		}	
	}
	else
	{
		for(int i=0; i<9; i++)
		{
			for(int j=0; j<9; j++)
			{
				if(A[i][j]=='.')
					A[i][j]='!';
			}
		}
	}
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9;j++)
		{
			cout<<A[i][j];
			if(j==2 || j==5)cout<<" ";
		}
		cout<<endl;
		if(i==2 || i==5)cout<<endl;
	}
	return 0;
}