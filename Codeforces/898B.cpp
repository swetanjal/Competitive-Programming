#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,a,b;
	cin>>n>>a>>b;
	for(int x=0; ; x++)
	{
		long long lol=x*a;
		if(lol>n)break;
		long long bol=(n-lol);
		if((bol%b)==0)
		{
			cout<<"YES\n";
			cout<<x<<" "<<(bol/b)<<endl;
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}