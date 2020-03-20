#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;
const int MAXN = 205;
int N, L, low, high, lim;
string S;

long long DP[MAXN][MAXN][MAXN];

long long rec(int ind, int org, int depth){
	if(depth < 0)
		return 0;
	if(ind == lim){
		
		int bit = 0;
		for(int i = org; i < L; i++){
			if(S[i] == '(')bit++;
			else bit--;
		}
		if((depth + bit) == 0){
			//cout<<ind <<" "<<org <<" "<<depth<<endl;
			return 1;
		}
		return 0;
	}
	if(DP[ind][org][depth] != -1)return DP[ind][org][depth];
	long long ret = 0;
	if(org <= low || org >= high){
		//three options
		if(org == L || S[org] != '(' || org == low)
			ret = (ret + rec(ind + 1, org, depth + 1)) % MOD;
		if(org == L || S[org] != ')' || org == low)
			ret = (ret + rec(ind + 1, org, depth - 1)) % MOD;
		if(org < L){
			int bit = -1;
			if(S[org] == '(')
				bit = 1;
			ret = (ret + rec(ind, org + 1, depth + bit)) % MOD;
		}
	}
	else{
		if(org < L){
			int bit = -1;
			if(S[org] == '(')
				bit = 1;
			ret = (ret + rec(ind, org + 1, depth + bit)) % MOD;
		}	
	}
	return DP[ind][org][depth] = ret;
}

int main()
{
	cin>>N;
	cin>>S;
	L = S.size();
	int neg = 0;
	int curr = 0;
	string copy = S;
	for(int i = 0; i < L; i++){
		if(S[i] == '(')curr++;
		else curr--;
		if(curr < 0)
			neg = max(neg, abs(curr));
	}
	for(int i = 1; i <= neg; i++)
		S = '(' + S;
	int pos = 0;
	curr = 0;
	for(int i = L - 1; i >= 0; i--){
		if(copy[i] == '(')curr++;
		else curr--;
		if(curr > 0)
			pos = max(pos, abs(curr));	
	}
	for(int i = 1; i <= pos; i++)
		S = S + ')';
	L = S.size();
	lim = (2 * N) - L;
	if(lim < 0){
		cout<<"0\n";
		return 0;
	}
	low = neg; // <= low valid
	high = L - pos; // >= high valid
	for(int i = 0; i < MAXN; i++)
		for(int j = 0; j < MAXN; j++)
			for(int k = 0; k < MAXN; k++)
				DP[i][j][k] = -1;
	cout<<rec(0, 0, 0)<<endl;
	return 0;
}