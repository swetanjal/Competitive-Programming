#include "bits/stdc++.h"
using namespace std;



int main()
{
	int a, b, x;
	cin>>a>>b>>x;
	vector <int> A;
	if(a >= b)
	{
		for(int i=1; i<=x; i++)
		{
			a--;
			b--;
			A.push_back(0);
			A.push_back(1);
			//if(i != x)
			i++;
		}
	}
	else
	{
		for(int i=1; i<=x; i++)
		{
			a--;
			b--;
			A.push_back(1);
			A.push_back(0);
			i++;
		}
	}
	if(A[0] == 0)
	{
		if((x%2)==0)a--;
		cout<<A[0];
		for(int j = 1; j <= a; j++)
		{
			cout<<"0";
		}
		cout<<A[1];
		for(int j = 1; j <= b; j++)
		{
			cout<<"1";
		}
		for(int j = 2; j < A.size(); j++)
			cout<<A[j];
		if((x%2)==0)
		cout<<A[0];
		cout<<endl;
	}
	else
	{
		if((x%2)==0)b--;
		cout<<A[0];
		for(int j = 1; j <= b; j++)
		{
			cout<<"1";
		}
		cout<<A[1];
		for(int j = 1; j <= a; j++)
		{
			cout<<"0";
		}
		for(int j = 2; j < A.size(); j++)
			cout<<A[j];
		if((x%2)==0)
		cout<<A[0];
		cout<<endl;	
	}
	return 0;
}