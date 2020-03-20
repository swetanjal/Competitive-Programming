#include "bits/stdc++.h"
using namespace std;
long long two[1000005];
int main()
{
	long long N,M;
	cin>>N>>M;
	two[0]=1; int cnt;
	for(int i=1; ; i++)
	{
		two[i]=two[i-1]*2;
		if(two[i]>=100000000)
		{
			cnt=i;
			break;
		}	
	}
	if(N<=cnt){
		cout<<(M%two[N])<<endl;
	}
	else{
		cout<<M<<endl;
	}
	return 0;
}