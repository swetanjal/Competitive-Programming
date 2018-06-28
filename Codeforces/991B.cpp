#include "bits/stdc++.h"
using namespace std;

int main()
{
	int N;
	cin>>N;
	long long A[N];
	for(int i=0; i<N; i++)cin>>A[i];
	long long cum[N];
	sort(A, A+N);
	cum[0] = A[0];
	for(int i=1; i<N; i++)
	{
		cum[i] = cum[i-1] + A[i];
	}
	if(round(cum[N-1]*1.0/N) >= 5)
	{
		cout<<"0\n";
		return 0;
	}
	for(int i=0; i<N; i++)
	{
		long long gr = round((cum[N-1] - cum[i] + (5*(i+1)))*1.0/N);
		if(gr >= 5)
		{
			cout<<(i+1)<<endl;
			return 0;
		}
	}
	return 0;
}