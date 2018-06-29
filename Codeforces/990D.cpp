#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1005;
int N, A, B;
vector <int> edges[MAXN];
int mat[MAXN][MAXN];
int main()
{
	cin>>N>>A>>B;
	if(A == 1 && B == 1 && N == 2)
	{
		cout<<"NO\n";
		return 0;
	}
	if(A == 1 && B == 1 && N == 3)
	{
		cout<<"NO\n";
		return 0;	
	}
	if(A == 1 && B == 1  && N == 1)
	{
		cout<<"YES\n";
		cout<<"0\n";
		return 0;
	}
	if(A!=1 && B!=1 || A>N || B>N)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	int cnt = 1;
	int complement = 0;
	if(A == 1){
		swap(A, B);
		complement = 1;
	}
	for(int i=1; i<=A; i++)
	{
		cnt += 1;	
	}
	for(int i = cnt; i <= N; i++)
	{
		edges[i].push_back(i - 1);
		edges[i - 1].push_back(i);
	}
	for(int i=1; i<=N; i++)
	{
		int L = edges[i].size();
		for(int j=0; j<L; j++)
		{
			mat[i][edges[i][j]] = 1;
		}
	}
	if(complement)
	{
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				if(i == j)continue;
				mat[i][j] = 1 - mat[i][j];
			}
		}
	}
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)cout<<mat[i][j];
			cout<<endl;
	}
	return 0;
}