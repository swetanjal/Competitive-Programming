#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N,T;
	cin>>T;
	while(T--)
	{
		cin>>N;
		long long A[N];
		int ans=0;
		for(int i=0; i<N; i++)cin>>A[i];
		for(int i=0; i<N; i++)
		{
			for(int j=i; j<N; j++)
			{
				long long sum=0; long long prod=1;
				for(int k=i; k<=j; k++){
					sum+=A[k];
					prod*=A[k];
				}
				if(sum==prod)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}