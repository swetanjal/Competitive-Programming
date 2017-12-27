/*
ID: swetanj2
LANG: C++
TASK: comehome
*/
#include <bits/stdc++.h>
using namespace std;
const long long INF=20000000000;
int N,u,v;
char x,y;
long long dp[60][60],w;
int get(char t)
{
	if(t>='A' && t<='Z')return (t-'A'+1);
	return (t-'a'+27);
}
int main()
{
	ifstream cin("comehome.in");
	ofstream cout("comehome.out");
	cin>>N;
	for(int i=1; i<=59; i++)for(int j=1; j<=59; j++)dp[i][j]=INF;
	for(int i=1; i<=N; i++)
	{
		cin>>x>>y>>w;
		u=get(x); v=get(y);
		dp[u][v]=min(dp[u][v],w);
		dp[v][u]=min(dp[v][u],w);
	}
	for(int i=1; i<=59; i++)dp[i][i]=min(0LL,dp[i][i]);
	for(int k=1; k<=59; k++)
	{
		for(int i=1; i<=59; i++)
		{
			for(int j=1; j<=59; j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	long long ret=LONG_LONG_MAX; int pos;
	for(int i=1; i<=25; i++){
		if(dp[i][26]<ret){
			ret=dp[i][26];
			pos=i;
		}
	}
	cout<<(char)(pos+'A'-1)<<" "<<ret<<endl;
	return 0;
}
