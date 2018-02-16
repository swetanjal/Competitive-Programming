#include "bits/stdc++.h"
using namespace std;
int N,pos;
long long L,min_cost;
long long C[35];
long long two[35];
long long dp[35];
long long comp(long long litres, int P)
{
	if(litres==0)return 0;
	long long nos=ceil(litres*1.0/two[P]);
	
	long long AMT=(nos*dp[P]);
	//cout<<AMT<<endl;
	long long AMT2=((litres/two[P])*dp[P])+comp(litres%two[P],P-1);
	//cout<<AMT2<<endl;
	return min(AMT,AMT2);
}

int main()
{
	cin>>N>>L;
	min_cost=LONG_LONG_MAX;
	two[0]=1;
	for(int i=1; i<=30; i++)
		two[i]=two[i-1]*2;
	for(int i=0; i<N; i++)
	{
		cin>>C[i];
		if(min_cost>C[i]){
			min_cost=C[i];
			pos=i;
		}
	}
	for(int i=0; i<=pos; i++)
		dp[i]=min_cost;
	for(int i=pos+1; i<N; i++)
	{
		long long MIN=LONG_LONG_MAX;
		for(int j=0; j<i; j++)
		{
			int NOS=two[i]/two[j];
			MIN=min(MIN,(NOS*C[j]));
		}
		MIN=min(MIN,C[i]);
		dp[i]=MIN;
	}
	//for(int i=0; i<N; i++)cout<<dp[i]<<" ";
	//	cout<<endl;
	long long ret=comp(L,N-1);
	//cout<<ret<<endl;
	//L=L%two[N-1];
	/*
	int cnt=N-1;
	while(L>0)
	{
		if(cnt<=pos){
			int bottles=ceil(L*1.0/two[cnt]);
			ret=ret+(bottles*dp[cnt]);
			break;	
		}
		int bottles=ceil(L*1.0/two[cnt]);
		L=0;
		ret=ret+(bottles*dp[cnt]);
		cnt--;
	}
	//ret=ret+dp[L];*/
	cout<<ret<<endl;
	return 0;
}