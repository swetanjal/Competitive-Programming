/*
Nice Observation: A + B = (A | B) + (A & B)
Proof: Venn Diagrams :P
*/

#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int T, N;
long long A[MAXN];
long long B[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=0; i<N; i++)
			cin>>A[i];
		for(int i=0; i<N; i++)
			cin>>B[i];
		for(int i=0; i<N; i++)
			A[i]+=B[i];
		long long cum = 0;
		for(int i=0; i<N; i++)
			cum += A[i];
		cum = cum/N;
		cum = cum/2;
		for(int i=0; i<N; i++)
			A[i] = (A[i] - cum)/N;
		sort(A, A+N);
		long long ret = 0;
		ret = (N - 1) * A[N-1];
		int cnt = 0;
		for(int i = (N-2); cnt<(N-1); cnt++,i--)
			ret = ret + A[i];
		cout<<ret<<endl;
	}
	return 0;
}