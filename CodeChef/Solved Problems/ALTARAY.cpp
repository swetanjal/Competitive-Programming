#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 5;
int T,N;
int DP[MAXN];
int A[MAXN];
//DP[i] = maximum alternating subarray starting from index i.

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=0; i<N; i++){
			cin>>A[i];
		}
		DP[N-1] = 1;
		for(int i=N-2; i>=0; i--){
			if(A[i]>0 && A[i+1]<0){
				DP[i] = 1 + DP[i+1];
				continue;
			}
			if(A[i]<0 && A[i+1]>0){
				DP[i] = 1 + DP[i+1];
				continue;
			}
			DP[i] = 1;
		}
		for(int i=0; i<N; i++)cout<<DP[i]<<" ";
			cout<<endl;
	}
	return 0;
}