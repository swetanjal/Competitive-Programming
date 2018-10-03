#include "bits/stdc++.h"
using namespace std;
const int MAXN = 3e5 + 5;
const int LIM = 1.5e7 + 5;
map <int, int> H;
int prime[LIM];
int cnt[LIM];
int A[MAXN];
int freq[LIM];
int N;
void sieve()
{
	for(int i = 1; i < LIM; i++)
		prime[i] = 1;
	for(int i = 2; i < LIM; i++)
	{
		if(prime[i] == 0)
			continue;
		for(int j = i + i; j < LIM; j += i)
		{
			prime[j] = 0;
			cnt[i] = cnt[i] + freq[j];
		}
		cnt[i] += freq[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> N;
	int G = A[0];
	for(int i = 0; i < N; i++){
		cin >> A[i];
		G = __gcd(G, A[i]);
	}
	for(int i = 0; i < N; i++){
		A[i] = A[i] / G;
	}
	for(int i = 0; i < N; i++){
		freq[A[i]] += 1;
	}
	sieve();
	int ans = INT_MAX;
	//cout << freq[] << " " << cnt[3] << " " << cnt[5] << endl;
	for(int i = 2; i < LIM; i++){
		if(prime[i])
		{
			if((N - cnt[i]) != N){
				ans = min(ans, N - cnt[i]);
			}
		}
	}
	if(ans == INT_MAX)
		cout << "-1" << endl;
	else
		cout << ans << endl;
	return 0;
}