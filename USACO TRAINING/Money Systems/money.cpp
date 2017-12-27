/*
ID: swetanj2
LANG: C++
TASK: money
*/
#include <bits/stdc++.h>
using namespace std;
int N,V;
int A[25];
long long dp[30][10005];
long long rec(int ind, int val)
{
	if(val<0)return 0;
	if(ind>=V)return 0;
	//cout<<ind<<" "<<val<<endl;
	if(val==0){
		//for(int i=0; i<cnt; i++)cout<<X[i]<<" ";
		//cout<<endl;
		return 1;
	}
	if(dp[ind][val]!=-1)return dp[ind][val];
	//int tmp[cnt+1];
	//for(int i=0; i<cnt; i++)tmp[i]=X[i];
	//tmp[cnt]=A[ind];
	dp[ind][val]=rec(ind,val-A[ind])+rec(ind+1,val);
	//rec(ind+1,val-A[ind],tmp,cnt+1);
	//;
	return dp[ind][val];
}
int main()
{
	ifstream cin("money.in");
	ofstream cout("money.out");
	cin>>V>>N;
	for(int i=0; i<V; i++)cin>>A[i];
	for(int j=0; j<25; j++)for(int i=0; i<10005; i++)dp[j][i]=-1;
	cout<<rec(0,N)<<endl;
	return 0;
}
