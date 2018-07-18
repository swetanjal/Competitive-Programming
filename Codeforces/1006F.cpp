#include "bits/stdc++.h"
using namespace std;
const int MAXNM = 25;
int N, M, mid;
long long K, ans;
long long A[MAXNM][MAXNM];
map <long long, int > H[MAXNM][MAXNM];


void calcl(int x, int y, int cnt, long long val)
{
	if(x >= N || y >= M)
		return;
	val = val ^ A[x][y];
	if(cnt == mid){
		H[x][y][val]++;
		return;
	}
	calcl(x, y + 1, cnt + 1, val);
	calcl(x + 1, y, cnt + 1, val);
}



void calcr(int x, int y, int cnt, long long val)
{
	if(x < 0 || y < 0)
		return;
	if(cnt == (N + M - 2 -mid))
	{
		if(H[x][y].find(val ^ K) != H[x][y].end())
			ans += H[x][y][val ^ K];
		return;
	}
	val = val ^ A[x][y];
	calcr(x - 1, y, cnt + 1, val);
	calcr(x, y - 1, cnt + 1, val);
}

int main()
{
	cin>>N>>M>>K;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++)
			cin>>A[i][j];
	}
	mid = (N + M - 2)/2;
	calcl(0, 0, 0, 0);
	calcr(N - 1, M - 1, 0, 0);
	cout<<ans<<endl;
	return 0;
}