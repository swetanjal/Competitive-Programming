#include "bits/stdc++.h"
using namespace std;

int main()
{
	int N;
	cin >> N;
	long long int A[N];
	for(int i = 0; i < N; i++)
		cin >> A[i];
	int DP[N];
	for(int i = 0; i < N; i++)
		DP[i] = 0;
	DP[N - 1] = 1;
	for(int i = N - 2; i >= 0; i--)
	{
		long long val = A[i];
		int low = i; int high = N - 1;
		int mid; int pos = i;
		while(high >= low)
		{
			mid = (high + low) / 2;
			if(A[mid] > (2 * val))
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
				pos = mid;
			}
		}
		//cout << pos << endl;
		if(pos == i)
			DP[i] = 1;
		else
			DP[i] = (pos - i) + DP[pos];
	}
	int ret = 0;
	for(int i = 0; i < N; i++)
		ret = max(ret, DP[i]);
	cout << ret << endl;
	return 0;
}