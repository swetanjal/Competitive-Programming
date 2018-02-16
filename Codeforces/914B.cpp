#include "bits/stdc++.h"
using namespace std;
int main()
{
	int N;
	cin>>N;
	long long A[N];
	for(int i=0; i<N; i++)
		cin>>A[i];
	sort(A,A+N);
	int even[N];
	int odd[N];
	for(int i=0; i<N; i++){
		even[i]=0;
		odd[i]=0;
	}
	odd[0]=1;
	for(int i=1; i<N; i++)
	{
		odd[i]=even[i-1];
		even[i]=odd[i-1];
		if(A[i]!=A[i-1])
			odd[i]=1;
	}
	if(odd[N-1]==1)cout<<"Conan\n";
	else cout<<"Agasa\n";
	return 0;
}