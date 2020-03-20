#include "bits/stdc++.h"
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int A[1005];
		for(int i=0; i<1005; i++)
			A[i] = 0;
		int N;
		cin>>N;
		for(int i=1; i<=N; i++)
		{
			int u;
			cin>>u;
			A[u] += 1;
		}
		int flag = 0;
		for(int i=1; i<=1000; i++){
			if(A[i] > 1)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}