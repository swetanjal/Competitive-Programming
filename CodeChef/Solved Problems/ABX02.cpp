#include "bits/stdc++.h"
using namespace std;
const long long MOD=1000000007;
int T,N,P,Q,B1,B2,S1,S2;

long long dp[105][55][55][2];

long long rec(int opened, int p, int q, int key)
{
	if((p+q)>N)return 0;
	if((p+q)==N)return 1;
	if(dp[opened][p][q][key]!=-1)return dp[opened][p][q][key];
	dp[opened][p][q][key]=0;
	if((opened%2)==key)
	{
		/*Open BOX 1*/
		if((opened/2)==B1)return 0;
		if(p==P)return 0;
		int limit=min(P-p,S1);
		for(int i=1; i<=limit; i++)
			dp[opened][p][q][key]=(dp[opened][p][q][key]+rec(opened+1,p+i,q,key))%MOD;
	}
	else
	{
		/*Open Box 2*/
		if((opened/2)==B2)return 0;
		if(q==Q)return 0;
		int limit=min(Q-q,S2);
		for(int i=1; i<=limit; i++)
			dp[opened][p][q][key]=(dp[opened][p][q][key]+rec(opened+1,p,q+i,key))%MOD;
	}
	return dp[opened][p][q][key];
}

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>P>>Q>>N;
		cin>>B1>>B2;
		cin>>S1>>S2;
		for(int i=0; i<=(P+Q); i++)
		{
			for(int j=0; j<=P; j++)
			{
				for(int k=0; k<=Q; k++)
				{
					for(int l=0; l<=1; l++)dp[i][j][k][l]=-1;
				}
			}
		}
		long long ret=(rec(0,0,0,0)+rec(0,0,0,1))%MOD;
		cout<<ret<<endl;
	}
	return 0;
}