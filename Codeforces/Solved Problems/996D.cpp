#include "bits/stdc++.h"
using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[2*N];
	for(int i=0; i<(2 * N); i++)
	{
		cin>>A[i];
	}
	int ret = 0;
	for(int i=0; i<(2 * N); i+=2)
	{
		for(int j = i + 1; j<(2 * N); j++)
		{
			if(A[i] == A[j])
			{
				for(int k = j - 1; k > i; k--){
					swap(A[k], A[k + 1]);
					ret++;
				}
				break;
			}
		}

	}
	cout<<ret<<endl;
	return 0;
}