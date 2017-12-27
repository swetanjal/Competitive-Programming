#include "bits/stdc++.h"
using namespace std;
const int MAX=1000005;
int A[MAX];
long long DP[MAX];
long long cum[MAX];
int main()
{
	int N;
	cin>>N;
	for(int i=1; i<=N; i++)
	{
		int tmp;
		cin>>tmp;
		A[tmp]++;
	}
	long long cnt=0;
	for(int i=N; i>0; i--)
	{
		if(A[i]==0){
			cnt=0;
		}
		else
		{
			DP[i]=cnt;
			cnt+=A[i];
		}
	}
	for(int i=1; i<=N; i++)cum[i]=cum[i-1]+A[i];
	long long ANS=INT_MAX;
	for(int i=1; i<=N; i++)
	{
		if(A[i]==0)continue;
		if(cum[i]==i){
			ANS=min(ANS,cum[i]);
		}
		else if(cum[i]<i){
			//do nothing.. invalid
		}
		else
		{
			ANS=min(ANS,cum[i]+DP[i]);
		}
	}
	cout<<ANS<<endl;
	return 0;
}