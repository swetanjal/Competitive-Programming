#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 5;

long long A[MAXN];

int main()
{
	int T, N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=0; i<N; i++)
			cin>>A[i];
		sort(A, A+N);
		for(int i=N-1; i>=0; i-=2)
		{
			if(i-1>=0)
			cout<<A[i-1]<<" "<<A[i]<<" ";
			else
				cout<<A[i]<<" ";
		}
		cout<<endl;
		//1 2 3 4 5 6 7 8 9	
	}
	return 0;
}