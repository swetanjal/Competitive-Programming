#include "bits/stdc++.h"
using namespace std;

int N,M;
int exists[10];
int A[15];
int main()
{
	cin>>N>>M;
	for(int i=0; i<N; i++)
		cin>>A[i];
	for(int i=0; i<M; i++)
	{
		int x;
		cin>>x;
		exists[x] = 1;
	}
	for(int i=0; i<N; i++)
		if(exists[A[i]])cout<<A[i]<<" ";
	cout<<endl;
	return 0;
}