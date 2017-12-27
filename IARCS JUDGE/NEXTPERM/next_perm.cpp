#include <bits/stdc++.h>
using namespace std;
int N,T;
int A[1005];
int main()
{
	cin>>N>>T;
	for(int i=1; i<=T; i++)
	{
		for(int j=0; j<N; j++)cin>>A[j];
		next_permutation(A,A+N);
		for(int j=0; j<N; j++)cout<<A[j]<<" ";
		cout<<endl;
	}
	return 0;
}
