#include "bits/stdc++.h"
using namespace std;
const int MAXN = 105;
int A[MAXN];
int N, M;

int main()
{
	cin>>N>>M;
	for(int i = 0; i < N; i++){
		int l,r;
		cin>>l>>r;
		for(int j = l; j <= r; j++)
			A[j] = 1;
	}
	int ans = 0;
	for(int i = 1; i <= M; i++)
		ans = ans + (1 - A[i]);
	cout<<ans<<endl;
	for(int i = 1; i<= M; i++)
	{
		if(A[i] == 0)
			cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}