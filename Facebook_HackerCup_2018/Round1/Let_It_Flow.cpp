#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1000000007;
const int MAXN = 1e3 + 5;
int N;
char A[3][MAXN];
long long DP[3][MAXN][4];
//0 - Left
//1 - Right
//2 - Up
//3 - Down

long long rec(int X, int Y, int dir)
{
	if(X < 0 || X == 3 || Y < 0 || Y >= N)
		return 0;
	if(A[X][Y] == '#')
		return 0;
	if(X == 2 && Y == (N - 1)){
		if(dir == 2)
			return 1;
		return 0;
	}
	if(DP[X][Y][dir] != -1)
		return DP[X][Y][dir];
	
	DP[X][Y][dir] = 0;
	if(dir == 0)
	{
		DP[X][Y][dir] = (DP[X][Y][dir] + rec(X + 1, Y, 2)) % MOD;
		DP[X][Y][dir] = (DP[X][Y][dir] + rec(X - 1, Y, 3)) % MOD;
	}
	else if(dir == 2){
		DP[X][Y][dir] = (DP[X][Y][dir] + rec(X, Y + 1, 0)) % MOD;	
	}
	else if(dir == 3){
		DP[X][Y][dir] = (DP[X][Y][dir] + rec(X, Y + 1, 0)) % MOD;	
	}
	else
		assert(false);
	return DP[X][Y][dir];
}

int main()
{
	ifstream cin("let_it_flow.txt");
	ofstream cout("Let_It_Flow.out");
	int t;
	cin>>t;
	for(int T = 1; T <= t; T++)
	{
		cin>>N;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < N; j++)
				cin>>A[i][j];
		}
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < N; j++)
				for(int k = 0; k < 4; k++)
					DP[i][j][k] = -1;
		}
		cout<<"Case #"<<T<<": "<<rec(0, 0, 0)<<endl;
	}
	return 0;
}