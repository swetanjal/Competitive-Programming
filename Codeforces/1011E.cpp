#include "bits/stdc++.h"
using namespace std;

int N, K;

int main()
{
	cin>>N>>K;
	long long g = 0;
	for(int i = 1; i <= N; i++)
	{
		long long x;
		cin>>x;
		g = __gcd(g, x);
	}
	set <long long> S;
	set <long long> :: iterator it;
	for(int i = 0; i < K; i++){
		S.insert( (i * 1LL * g) % K);
	}
	cout<<S.size()<<endl;
	for(it = S.begin(); it != S.end(); ++it)
		cout<<*it<<" ";
	cout<<endl;
	return 0;
}