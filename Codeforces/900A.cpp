#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int neg=0; int pos=0;
	while(N--)
	{
		long long X,Y;
		cin>>X>>Y;
		if(X<0)neg++;
		else pos++;
	}
	if(neg<=1 || pos<=1)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}