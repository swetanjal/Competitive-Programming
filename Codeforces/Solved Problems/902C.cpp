#include <bits/stdc++.h>
using namespace std;
int H;
int A[100005];
vector <int> nodes[100005];
int main()
{
	cin>>H;
	int N=0;
	for(int i=0; i<=H; i++)
	{
		cin>>A[i];
		N+=A[i];
	}
	int flag=1;
	for(int i=1; i<=H; i++)
	{
		if(A[i-1]>1 && A[i]>1)
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		cout<<"perfect\n";
		return 0;
	}
	cout<<"ambiguous\n";
	nodes[0].push_back(1);
	cout<<"0 ";
	int node=2;
	for(int i=1; i<=H; i++)
	{
		for(int j=1; j<=A[i]; j++)
			nodes[i].push_back(node++);
	}
	for(int i=1; i<=H; i++)
	{
		for(int j=1; j<=A[i]; j++)
			cout<<nodes[i-1][0]<<" ";
	}
	cout<<endl;
	cout<<"0 ";
	for(int i=1; i<=H; i++)
	{
		if(A[i]==1 || A[i-1]==1){
			for(int j=1; j<=A[i]; j++)
			cout<<nodes[i-1][0]<<" ";
		}
		else{
			cout<<nodes[i-1][0]<<" ";
			for(int j=1; j<A[i]; j++)
			cout<<nodes[i-1][1]<<" ";
		}
	}
	cout<<endl;
	return 0;
}