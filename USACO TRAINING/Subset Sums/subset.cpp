/*
ID: swetanj2
LANG: C++
TASK: subset
*/
#include <bits/stdc++.h>
using namespace std;
int N,n;
int dp[50][(50*51)/2];
int rec(int ind, int sum)
{
	if(sum==0){
		return 1;
	}
	if(ind==n)return 0;
	if(sum<0)return 0;
	if(dp[ind][sum]!=-1)return dp[ind][sum];
	return dp[ind][sum]=rec(ind+1,sum)+rec(ind+1,sum-ind);
}
int main()
{
	for(int i=0; i<50; i++)
	for(int j=0; j<(50*51)/2; j++)dp[i][j]=-1;
	ifstream cin("subset.in");
	ofstream cout("subset.out");
	cin>>N;
	n=N;
	N=(N*(N+1))/4;
	if(N*4!=n*(n+1)){
		cout<<"0"<<endl;
		return 0;
	}
	cout<<rec(1,N)<<endl;
	return 0;
}
