#include <bits/stdc++.h>
using namespace std;
int N,target;
string p;
int A[50];
//map < pair <int, pair <long,long> > , int > dp;
short dp[50][100005][7];
int rec(int ind, int sum, int curr)
{
	if(ind<0)
	{
		if((sum==0)&&(curr==0))return (-1);
		return 100;
	}
	//place a sign
	if(curr>5)return 100;
	if(sum<0)return 100;
	//pair <long long, long long> p;
	//p=make_pair(sum,curr);
	//pair <int, pair <long long,long long> > q; 
	//q=make_pair(ind,p);
	if(dp[ind][sum][curr]!=-1)return dp[ind][sum][curr];
	return dp[ind][sum][curr]=min(1+rec(ind-1,sum-((pow(10,curr)*A[ind])),0),rec(ind-1,sum-((pow(10,curr)*A[ind])),curr+1));
}
int main()
{
	for(int r=0; r<50; r++)for(int i=0; i<100005; i++)for(int j=0; j<=6; j++)dp[r][i][j]=-1;
	cin>>N;
	cin>>p;
	for(int i=0; i<N; i++)
	A[i]=p[i]-48;
	/*while(p>0)
	{
		A[--cnt]=p%10;
		p=p/10;
	}*/
	cin>>target;
	int ans=rec(N-1,target,0);
	if(ans<100)cout<<ans<<endl;
	else cout<<"-1"<<endl;
	return 0;
}
