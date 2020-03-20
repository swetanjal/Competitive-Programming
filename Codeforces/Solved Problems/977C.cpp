#include "bits/stdc++.h"
using namespace std;

int main()
{
	int N,K;
	cin>>N>>K;
	long long A[N];
	for(int i=0; i<N; i++)cin>>A[i];
	sort(A,A+N);
	if(K == 0 && A[0]>1){
		cout<<"1\n";
		return 0;
	}
	if(K == 0){
		cout<<"-1\n";
		return 0;
	}
	if(K == N || A[K]!=A[K-1]){
		cout<<A[K-1]<<endl;
	}
	else
	{
		cout<<"-1\n";
	}
	return 0;
}