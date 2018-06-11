#include "bits/stdc++.h"

using namespace std;

int L,T;
string S;

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>L;
		cin>>S;
		int A[L];
		if(S[L-1] == '1')
			A[L-1] = 1;
		else
			A[L-1] = 0;
		for(int i=L-2; i>=0; i--)
			A[i] = A[i + 1] + (S[i] - '0');
		long long ret = 0;
		for(int i=0; i<L; i++)
		{
			if(S[i] == '1')
				ret += A[i];
		}
		cout<<ret<<endl;
	}
	return 0;
}