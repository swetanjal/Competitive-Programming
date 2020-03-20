#include <bits/stdc++.h>
using namespace std;
int M,K;
long long R;
char A[50005];
map < char , int > pos;
long long dp[50005][15][5];
long long curr=0;
char print(int u)
{
	if(u==0)return 'A';
	if(u==1)return 'C';
	if(u==2)return 'G';
	return 'T';
}
void build(int ind, int k, int last)
{
	if(ind==M)return;
	if(A[ind]!='N')
	{
		cout<<A[ind];
		if(pos[A[ind]]<last)build(ind+1,k+1,pos[A[ind]]);
		else build(ind+1,k,pos[A[ind]]);
		return;
	}
	for(int i=0; i<4; i++)
	{
		if(i<last)
		{
			if((curr+dp[ind+1][k+1][i])>=R)
			{
				cout<<print(i);
				build(ind+1,k+1,i);
				return;
			}
			else
			{
				curr+=dp[ind+1][k+1][i];
			}
		}
		else
		{
			if((curr+dp[ind+1][k][i])>=R)
			{
				cout<<print(i);
				build(ind+1,k,i);
				return;
			}
			else
			{
				curr+=dp[ind+1][k][i];
			}
		}
	}
	if(3<last)
	build(ind+1,k+1,3);
	else build(ind+1,k,3);
}
long long rec(int ind, int k, int last)
{
	if(ind==M && k<=K)return dp[ind][k][last]=1;
	if(ind==M)return 0;
	if(dp[ind][k][last]!=-1)return dp[ind][k][last];
	if(A[ind]!='N')
	return dp[ind][k][last]=(pos[A[ind]]<last)?rec(ind+1,k+1,pos[A[ind]]):rec(ind+1,k,pos[A[ind]]);
	dp[ind][k][last]=0;
	for(int i=0; i<4; i++)
	{
		if(i<last)dp[ind][k][last]+=rec(ind+1,k+1,i);
		else dp[ind][k][last]+=rec(ind+1,k,i);
	}
	return dp[ind][k][last];
}
int main()
{
	cin>>M>>K>>R;
	for(int i=0; i<M; i++)cin>>A[i];
	pos['A']=0; pos['C']=1; pos['G']=2; pos['T']=3;
	for(int i=0; i<=M; i++)for(int j=0; j<=K; j++)for(int k=0; k<=4; k++)dp[i][j][k]=-1;
	rec(0,1,0);
	build(0,1,0);
	return 0;
}
