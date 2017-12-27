#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T,N,M;
	cin>>T;
	while(T--)
	{
		cin>>N>>M;
		if(M==1){
			cout<<(N-1)<<endl;
			continue;
		}
		else
		{
			if(N==1){
				cout<<0<<endl;
				continue;
			}
			else if(N==2)
			{
				cout<<M<<endl;
				continue;
			}
			else
			{
				cout<<(((2*M)-1)+(N-2))<<endl;
			}
		}

	}
	return 0;
}