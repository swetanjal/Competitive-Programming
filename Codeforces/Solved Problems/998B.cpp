#include "bits/stdc++.h"
using namespace std;
const long long negINF = -100000000;
const int MAXN = 1e2 + 5;
int N,B;
long long A[MAXN];
long long dp[MAXN][MAXN][MAXN];
bool chk(int l, int r)
{
	int o = 0; int e = 0;
	for(int i=l; i<=r; i++){
		if((A[i]%2) == 0)e++;
		else o++;
	}
	return (e==o);
}

long long rec(int ind, int last, int cost)
{
	if(cost > B)return negINF;
	if(ind == (N-1))
	{
		if(chk(last, N - 1)){
			//cost = cost + abs(A[N-1] - A[last]);
			if(cost <= B)
				return 0;
			return negINF;
		}
		else
			return negINF;
	}
	if(dp[ind][last][cost]!=-1)return dp[ind][last][cost];
	if(chk(last, ind))
	{
		return dp[ind][last][cost] = max(1 + rec(ind + 1, ind + 1, cost + abs(A[ind] - A[ind + 1])), rec(ind + 1, last, cost));
	}
	else
		return dp[ind][last][cost] = rec(ind + 1, last, cost);
}


int main()
{
	cin>>N>>B;
	for(int i=0; i<N; i++)
		cin>>A[i];
	for(int i=0; i<MAXN; i++)
		for(int j=0; j<MAXN; j++)
			for(int k=0; k<MAXN; k++)
				dp[i][j][k] = -1;
	cout<<rec(0, 0, 0)<<endl;
	return 0;
}