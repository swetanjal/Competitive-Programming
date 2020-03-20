#include "bits/stdc++.h"
using namespace std;

int main()
{
	int N,M;
	cin>>N>>M;
	long long A[N], B[M];
	for(int i=0; i<N; i++)cin>>A[i];
	for(int i=0; i<M; i++)cin>>B[i];
	sort(A,A+N);
	sort(B,B+M);
	long long ans=LONG_LONG_MAX;
	for(int i=0; i<N; i++){
		//hidding the ith lantern
		long long tmp=LONG_LONG_MIN;
		for(int j=0; j<M; j++)
		{
			for(int k=0; k<N; k++){
				if(k==i)continue;
				tmp=max(tmp,A[k]*B[j]);
			}
		}
		ans=min(ans , tmp);
	}
		cout<<ans<<endl;	
	return 0;
}