#include <bits/stdc++.h>
using namespace std;
int N,K,A[1000005];
int dp[1000005][4];
void rec2(int ind, int prev)
{
	if(ind==N)return;
	int previous=(prev==3)?A[ind-1]:prev;
	int tmp[]={0,1,2,A[ind]};
	sort(tmp,tmp+4);
	for(int i=0; i<=3; i++)
	{
		if(previous==tmp[i])continue;
		if(A[ind]==tmp[i])
		{
			if(dp[ind][prev]==dp[ind+1][3])
			{
				cout<<tmp[i]<<" ";
				rec2(ind+1,3);
				break;
			}
		}
		else
		{
			if(dp[ind][prev]==(1+dp[ind+1][tmp[i]]))
			{
				cout<<tmp[i]<<" ";
				rec2(ind+1,tmp[i]);
				break;
			}
		}
		
	}
}
int rec(int ind, int prev)
{
	if(ind==N)return 0;
	/*prev=3 signifies A[ind-1] is unchanged*/
	/*prev=1 signifies A[ind-1]=1*/
	/*prev=0 signifies A[ind-1]=0*/
	if(dp[ind][prev]!=-1)return dp[ind][prev];
	dp[ind][prev]=INT_MAX;
	int previous=(prev==3)?A[ind-1]:prev;
	int tmp[]={0,1,2,A[ind]};//possible values A[ind] can take up.
	sort(tmp,tmp+4);
	for(int i=0; i<=3; i++)
	{
		if(previous==tmp[i])continue;
		if(A[ind]==tmp[i])
		dp[ind][prev]=min(dp[ind][prev],rec(ind+1,3));
		else
		dp[ind][prev]=min(dp[ind][prev],1+rec(ind+1,tmp[i]));
	}
	return dp[ind][prev];
}
int main()
{
	cin>>N>>K;
	for(int i=0; i<N; i++)cin>>A[i];
	for(int i=0; i<N; i++)for(int j=0; j<=3; j++)dp[i][j]=-1;
	int tmp[]={0,1,2,A[0]};
	sort(tmp,tmp+4);
	int ans=INT_MAX;
	for(int i=0; i<=3; i++)
	{
		if(A[0]==tmp[i])
		ans=min(ans,rec(1,3));
		else ans=min(ans,1+rec(1,tmp[i]));
	}
	cout<<ans<<endl;
	for(int i=0; i<=3; i++)
	{
		if(A[0]==tmp[i])
		{
			if(ans==dp[1][3])
			{
				cout<<A[0]<<" ";
				rec2(1,3);
				break;
			}	
		}
		else
		{
			if(ans==(1+dp[1][tmp[i]]))
			{
				cout<<tmp[i]<<" ";
				rec2(1,tmp[i]);
				break;
			}
		}
	}
	return 0;
}
