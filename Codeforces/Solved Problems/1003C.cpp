#include "bits/stdc++.h"
using namespace std;
const int MAXN = 5e3 + 5;
int N,K;
long double A[MAXN];

int main()
{
	cin>>N>>K;
	long double ans = 0.0;
	for(int i=0; i<N; i++)
		cin>>A[i];
	for(int i=0; i<N; i++)
	{
		long double sum = 0.0;
		for(int j=i; j<N; j++)
		{
			int k = j - i + 1;
			sum += A[j];
			if(k >= K)
			{
				long double lol = (sum * 1.0) / (k * 1.0);
				if(lol > ans)
				ans = lol;
			}
		}
	}
	cout<<fixed<<setprecision(8)<<ans<<endl;
	return 0;
}