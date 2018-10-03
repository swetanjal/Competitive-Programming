#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N;
string S;
int DP1[MAXN];
int cont1[MAXN];
int DP2[MAXN];
int cont2[MAXN];
int DP[MAXN];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> S;
	N = S.size();
	DP1[0] = 1;
	cont1[0] = 1;
	for(int i = 1; i < N; i++)
	{
		if(cont1[i - 1] == 1 && S[i] != S[i - 1])
		{
			cont1[i] = 1;
			DP[i] = 1 + DP[i - 1];
		}
		else
		{
			cont1[i] = 0;
			DP[i] = DP[i - 1];
		}
	}
	DP2[N - 1] = 1;
	cont2[N - 1] = 1;
	for(int i = N - 2; i >= 0; i--)
	{
		if(cont2[i + 1] == 1 && S[i] != S[i + 1])
		{
			cont2[i] = 1;
			DP[i] = 1 + DP[i + 1];
		}
		else
		{
			cont2[i] = 0;
			DP[i] = DP[i + 1];
		}
	}
	DP[N - 1] = 1;
	for(int i = N - 2; i >= 0 ; i--)
	{
		if(S[i] != S[i + 1]){
			DP[i] = 1 + DP[i + 1];
		}
		else
			DP[i] = 1;
	}
	int ret = 0;
	for(int i = 0; i < N; i++)
		ret = max(ret, DP[i]);
	for(int i = 0; i < N - 1; i++)
	{
		if(S[0] != S[N - 1])
		ret = max(ret, DP1[i] + DP2[i + 1]);
	} 
	
	int cum = 1;
	for(int i = N - 2; i >= 0; i--)
	{
		if(S[i] != S[i + 1])
		{
			cum++;
		}
		else
			break;
	}
	if(S[0] != S[N - 1])
	ret = min(N, max(ret, min(N, DP[0] + cum)));
	cout << ret << endl;
	return 0;
}