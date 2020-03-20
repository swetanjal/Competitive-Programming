#include "bits/stdc++.h"
using namespace std;
const long long MOD = 998244353;
const int MAXN = 1e6 + 5;
long long power[MAXN];
long long A[MAXN];
long long DP1[MAXN];
long long DP2[MAXN];
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>N;
	power[0] = 1;
	for(int i = 1; i < MAXN; i++)
		power[i] = (power[i - 1] * 2) % MOD;
	for(int i = 0; i < N; i++)
		cin>>A[i];
	DP2[0] = (A[0] * power[N - 1]) % MOD;
	for(int i = 1; i < N; i++)
		DP2[i] = (DP2[i - 1] + (A[i] * power[N - 1 - i]) % MOD) % MOD;
	DP1[0] = 0;
	DP1[1] = (A[0] * power[N - 1]) % MOD;
	for(int i = 2; i <= N; i++)
	{
		DP1[i] = (((((2 * DP1[i - 1]) % MOD + DP2[i - 2]) % MOD + (A[i - 1] * power[N - 1 - (i - 2)]) % MOD) % MOD) * 499122177) % MOD;
	}
	cout<<DP1[N]<<endl;
	return 0;
}