#include "bits/stdc++.h"
using namespace std;
const int MAXN = 55;
int N, K;
int T;
long long int A[MAXN];
int main()
{
	cin >> T;
	while(T--)
	{
		cin >> N >> K;
		for(int i = 0; i < N; i++)
			cin >> A[i];
		long long sumLess = 0;
		for(int i = 0; i < N; i++)
			if(A[i] < K)
				sumLess += A[i];
		long long ans = sumLess;
		vector <int> extra;
		for(int i = 0; i < N; i++){
			if(A[i] >= K)
				extra.push_back(A[i] - K);
		}
		ans = ans + (extra.size() * K);
		
		sort(extra.begin(), extra.end());
		//Boundary Cases
		if(extra.size() == 0){

		}
		else if(extra.size() == 1){
			ans = ans + extra[0];
		}
		else if(extra.size() == 2){
			ans = ans + abs(extra[0] - extra[1]);
		}
		else{
			
			long long s = 0;
			for(int i = 0; i < extra.size() - 2; ++i)
			{
				s += extra[i];
			}
			if(s < extra[extra.size() - 2]){
				//Case 1
				ans = ans + (extra[extra.size() - 1] - (extra[extra.size() - 2] - s));
			}
			else{
				//Case 2
				if(s % 2 == extra[extra.size() - 2] % 2)
					ans = ans + extra[extra.size() - 1];
				else
					ans = ans + extra[extra.size() - 1] - 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}