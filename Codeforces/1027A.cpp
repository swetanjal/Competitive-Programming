#include "bits/stdc++.h"
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int L;
		cin >> L;
		string S;
		cin>>S;
		char A[L];
		char B[L];
		for(int i = 0; i < L; i++){
			if(S[i] == 'a')
			{
				A[i] = 'b';
				B[i] = 'b';
			}
			else if(S[i] == 'z')
			{
				A[i] = 'y';
				B[i] = 'y';
			}
			else
			{
				A[i] = (char)(S[i] - 1);
				B[i] = (char)(S[i] + 1);
			}
		}
		int cnt = L - 1;
		int flag = 1;
		for(int i = 0; i < L; i++){
			if(A[i] == A[cnt] || A[i] == B[cnt] || B[i] == A[cnt] || B[i] == B[cnt])
			{
				cnt--;
				continue;
			}
			cnt--;
			flag = 0;
			break;
		}
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}