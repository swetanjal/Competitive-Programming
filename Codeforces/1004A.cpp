#include "bits/stdc++.h"
using namespace std;

int main()
{
	int N;
	long long D;
	cin>>N>>D;
	long long A[N];
	for(int i=0; i<N; i++)
		cin>>A[i];
	sort(A, A + N);
	int ans = 2;
	for(int i = 0; i < N - 1; i++)
	{
		long long pt = A[i] + D;
		if(!((A[i + 1] - pt) < D))ans++;
		long long pt2 = A[i + 1] - D;
		if(pt2 != pt && ((pt2 - A[i])>=D))
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}