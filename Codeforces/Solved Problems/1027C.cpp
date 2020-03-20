#include "bits/stdc++.h"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		long long A[N];
		for(int i = 0; i < N; i++)
			cin >> A[i];
		sort(A, A + N);
		vector <long long> S;
		S.push_back(A[0]);
		int cnt = 1;
		for(int i = 1; i < N; i++)
		{
			if(A[i] != A[i - 1])
			{
				if((cnt % 2) != 0)
					S.pop_back();
				cnt = 1;
				S.push_back(A[i]);
			}
			else{
				S.push_back(A[i]);
				cnt++;
			}
		}
		if((cnt%2) != 0){
			S.pop_back();
		}
		int L = S.size();
		long double aaa = 100000000000;
		int ans = -1;
		for(int i = 3; i < L; i+=2){
			long double tmp = (S[i] * 1.0 / S[i - 2] * 1.0) + (S[i - 2] * 1.0 /  S[i] * 1.0);
			if(tmp < aaa)
			{
				ans = i;
				aaa = tmp;
			}
		}
		cout << S[ans] << " " << S[ans] << " " << S[ans - 2] << " " << S[ans - 2] << endl;
	}
	return 0;
}