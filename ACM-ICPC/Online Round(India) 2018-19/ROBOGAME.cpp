#include "bits/stdc++.h"
using namespace std;

int T;
string S;


int main()
{
	cin >> T;
	while(T--)
	{
		cin >> S;
		int L = S.size();
		int A[L];
		for(int i = 0; i < L; i++)
			A[i] = -1;
		int safe = 1;
		for(int i = 0; i < L; i++)
		{
			if(S[i] == '.')
				continue;
			int num = S[i] - '0';
			for(int j = max(0, i - num); j <= min(i + num, L - 1); j++)
			{
				if(A[j] != -1)
				{
					safe = 0;
				}
				else
					A[j] = i;
			}
		}
		if(safe)
			cout << "safe\n";
		else
			cout << "unsafe\n";
	}
	return 0;
}