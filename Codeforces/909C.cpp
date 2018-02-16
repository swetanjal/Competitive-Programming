#include "bits/stdc++.h"
using namespace std;
const int MOD=1000000007;
char A[5005];
int dp[5005][5005];
int N;
int main()
{
	cin>>N;
	for(int i=0; i<N; i++)cin>>A[i];
	dp[0][0]=1;
	for(int i=1; i<N; i++)
	{
		if(A[i-1]=='f')dp[i][0]=0;
		else{
			long long lol=0;
			for(int k=0; k<N; k++)
			lol=(lol+dp[i-1][k])%MOD;
			dp[i][0]=lol;	
		} 
		for(int j=1; j<=i; j++)
		{
			if(A[i-1]=='f')dp[i][j]=dp[i-1][j-1];
			else{
				long long tmp=dp[i][j-1];
				tmp=(tmp-dp[i-1][j-1]+MOD)%MOD;
				dp[i][j]=tmp;
			}
		}
	}
	long long ANS=0;
	for(int i=0; i<N; i++)ANS=(ANS+dp[N-1][i])%MOD;
	cout<<ANS<<endl;
	return 0;
}