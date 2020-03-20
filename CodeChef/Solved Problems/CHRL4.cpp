#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
long long A[MAXN];
double DP[MAXN];
long long helper[MAXN];
set < pair < double, int> > S;
int N,K;
int main()
{
	cin>>N>>K;
	for(int i=0; i<N; i++)
		cin>>A[i];
	for(int i=0; i<=min(K, N-1); i++){
		if(S.empty()){
			DP[i] = log(A[i]);
			helper[i] = A[i];
		}
		else{
			DP[i] = (log(A[i]) + ((*S.begin()).first));
			helper[i] = (A[i] * helper[(*S.begin()).second])%MOD;
		}
		S.insert(make_pair(DP[i], i));
	}
	for(int i=K+1; i<N; i++){
		pair <double, int> p =make_pair(DP[i-K-1], i-K-1);
		S.erase(S.find(p));
		if(S.empty()){
			DP[i] = log(A[i]);
			helper[i] = A[i];
		}
		else{
			DP[i] = (log(A[i]) + (*S.begin()).first);
			helper[i] = (A[i] * helper[(*S.begin()).second])%MOD;
		}
		S.insert(make_pair(DP[i], i));
	}
	cout<<helper[N-1]<<endl;
	return 0;
}