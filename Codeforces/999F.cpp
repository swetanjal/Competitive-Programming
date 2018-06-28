#include "bits/stdc++.h"
using namespace std;
const int negINF = -1e8;
const int Ci = 1e5 + 5;
const int MAXN = 505;
const int MAXK = 15;
const int MAXNK = 5005;
int freq[Ci];
int H[MAXK];
int fav[Ci]; //fav[i] denotes number of ppl whose favourite number is 10^5.
int DP[MAXK][MAXNK][MAXN];
int N,K;
int rec(int ind, int sum, int cnt)
{
	if(cnt == 0 && sum == 0)return 0;
	if(cnt<0 || sum<0 || ind == (K+1))return negINF;
	if(DP[ind][sum][cnt] != -1)return DP[ind][sum][cnt];
	return DP[ind][sum][cnt] = max(H[ind] + rec(ind, sum - ind, cnt - 1), rec(ind + 1, sum, cnt));
}

int main()
{
	cin>>N>>K;
	for(int i=1; i<=(N*K); i++)
	{
		int tmp;
		cin>>tmp;
		freq[tmp]++;
	}
	for(int i=1; i<=N; i++)
	{
		int tmp;
		cin>>tmp;
		fav[tmp]++;
	}
	H[0] = 0;
	for(int i=1; i<=K; i++)
		cin>>H[i];
	for(int i=0; i<MAXK; i++)for(int j=0; j<MAXNK; j++)for(int k=0; k<MAXN; k++)DP[i][j][k] = -1;
	long long ret = 0;
	for(int i=1; i<=100000; i++)
		ret += rec(0, min(fav[i]*K, freq[i]), fav[i]);
	cout<<ret<<endl;
	return 0;
}