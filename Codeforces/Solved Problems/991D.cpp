#include "bits/stdc++.h"
using namespace std;
const long long negINF = -100000000;
const int MAXN = 105;

char A[MAXN][2];
int N;
string S;

long long DP[MAXN][3];

long long rec(int ind, int flag)
{
	if(ind == N && flag!=0 )return negINF;
	if(ind == N)return 0;
	if(DP[ind][flag] != -1)return DP[ind][flag];
	if(flag == 1 && A[ind][0]!='0' && A[ind][1]!='0')
		return negINF;
	if(flag == 2 && (A[ind][0]!='0' || A[ind][1]!='0'))
		return negINF;
	if(flag == 0 && A[ind][0] == '0' && A[ind][1] == '0')
	{
		//Nothing
		return DP[ind][flag] = max(1 + rec(ind + 1, 2), max(1 + rec(ind + 1, 1), rec(ind+1, 0)));
	}
	else if(flag == 0 && (A[ind][0]=='0' || A[ind][1] == '0'))
	{
		//One vacant
		return DP[ind][flag] = max(1 + rec(ind + 1, 2), rec(ind+1, 0));
	}
	else if(flag == 0)
		return DP[ind][flag] = rec(ind+1, 0);
	else if(flag == 1 && (A[ind][0] == '0' && A[ind][1] == '0'))
		return DP[ind][flag] = max(1 + rec(ind + 1, 2), rec(ind + 1, 0));
	else if(flag == 1)
		return DP[ind][flag] = rec(ind + 1, 0);
	else if(flag == 2)
		return DP[ind][flag] = rec(ind + 1, 0);
}


int main()
{
	cin>>S;
	N = S.size();
	for(int i=0; i<N; i++)
		A[i][0] = S[i];
	cin>>S;
	for(int i=0; i<N; i++)
		A[i][1] = S[i];
	for(int i=0; i<MAXN; i++)
		for(int j=0; j<3; j++)
			DP[i][j] = -1;
	cout<<rec(0, 0)<<endl;
	return 0;
}