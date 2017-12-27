#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long N,sigma;
		cin>>N>>sigma;
		if(N==1 && sigma!=0)
		{
			cout<<"-1\n";
		}
		else if(sigma==0)
		{
			for(int i=0; i<N; i++)cout<<"0 ";
			cout<<endl;
		}
		else
		{
			double A=sqrt((N*sigma*sigma)*1.0/2);
			cout<<fixed<<setprecision(8)<<-A<<" ";
			for(int i=1; i<N-1; i++)cout<<"0 ";
			cout<<fixed<<setprecision(8)<<A<<endl;
		}
	}
	return 0;
}