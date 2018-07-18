#include "bits/stdc++.h"
using namespace std;
const int MAXN = 3e5 + 5;
int N;
int A[MAXN];
long long X, Y;

int main()
{
	cin>>N>>X>>Y;
	int cnt = 0;
	for(int i=0; i<N; i++)
	{
		char x;
		cin>>x;
		A[cnt]  = x - '0';
		if(i == 0 || A[cnt] != A[cnt - 1])
			cnt++;
	}
	int zeroes = 0;
	for(int i=0; i<cnt; i++)
		if(A[i] == 0)zeroes++;
	long long ans = LONG_LONG_MAX;
	for(int i = 0; i < zeroes; i++)
	{
		ans = min(ans, ((zeroes-i)*1LL*Y) + (i * 1LL * X));
	}
	if(ans == LONG_LONG_MAX)
		cout<<"0\n";
	else
		cout<<ans<<endl;
	return 0;
}