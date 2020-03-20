#include <bits/stdc++.h>
using namespace std;
int N,M,X,Y;
char A[1005][1005];
int hashes[1005];
int ans=INT_MAX;
int dp[1005][1005][2];
int rec(int ind, int cnt, int prev)
{
	if(ind==M)
	{
		//int tmp=0;
		if(cnt<X || cnt>Y)return 100000000;
		return 0;
			/*for(int j=0; j<M; j++)
			{
				if(S[j]==1)tmp+=(N-hashes[j]);
				else if(S[j]==0)tmp+=hashes[j];
			}
		
		ans=min(tmp,ans);
		//for(int i=0; i<M; i++)cout<<S[i]<<endl;
		return;*/
	}
	if(dp[ind][cnt][prev]!=-1)return dp[ind][cnt][prev];
	if(cnt<X){
		//only option
		int tempo=0;
		if(prev==1)tempo=(N-hashes[ind]);else tempo=hashes[ind];
		return dp[ind][cnt][prev]=tempo+rec(ind+1,cnt+1,prev);
	}
	else if(cnt>Y){
		return 100000000;
	}
	else
	{
		//two options
		int tempo=0;
		if(prev==1)tempo=(N-hashes[ind]);else tempo=hashes[ind];
		return dp[ind][cnt][prev]=min(tempo+rec(ind+1,cnt+1,prev),(N-tempo)+rec(ind+1,1,!prev));
	}
}
int main()
{
	for(int i=0; i<1005; i++)for(int j=0; j<1005; j++)for(int k=0; k<=1; k++)dp[i][j][k]=-1;
	cin>>N>>M>>X>>Y;
	for(int i=0; i<N; i++)for(int j=0; j<M; j++)cin>>A[i][j];
	int lmb[M];
	for(int i=0; i<M; i++)
	{
		//count the hashes
		hashes[i]=0;
		for(int j=0; j<N; j++)
		if(A[j][i]=='#')hashes[i]++;
	}
	int faf=min(rec(0,0,0),rec(0,0,1));
	if(faf<100000000)
	cout<<faf<<endl;
	else cout<<"0"<<endl;
	return 0;
}
